//lcd
#include "SPI.h"
#include <Adafruit_GFX.h>
#include <ILI9488.h>
#define TFT_CS PA3
#define TFT_DC PA2
#define TFT_LED PA1
#define TFT_RST PA8
ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);
//#include <Fonts/FreeSansOblique9pt7b.h>
#include "logo.h"
#include "mainmenu.h"
#include "help.h"
//keypad
#define ROWS 4
#define COLS 4
// پین‌های ردیف و ستون را مشخص کنید
const int rowPins[ROWS] = { PB8, PB9, PB10, PB11 };    // ردیف‌ها
const int colPins[COLS] = { PB12, PB13, PB14, PB15 };  // ستون‌ها
// const int rowPins[ROWS] = { PC0, PC1, PC2, PC3 };  // ردیف‌ها
// const int colPins[COLS] = { PC4, PC5, PC6, PC7 };  // ستون‌ها
// نقشه‌ی دکمه‌ها مطابق با ترتیب واقعی
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

int mainMenu = 1;
int changeMenu = 1;
int MenuSelect = 1;
int MenuSelectChange = 1;

int rele1 = PC8;
int rele2 = PC9;
int rele3 = PC10;
int rele4 = PC11;
int ReleAmper = PC13;
int Releselonoeid = PC12;
int buzzer = PB0;
int ingnd = PA1;
int SimulatorLow = PC7;
int simaulatorMode = 1;
String text;
int mute = 0;
int ZeroMode = 0;

//analyzer
float adc0;
float voltageADC0;
float average;
float gndAdc;
int analyzerState;
int sampleCount = 150;
int lcdShowCount;
float ADCres;
float InputVoltage;
int ADCZero;
int ExitToMenu;
#define ADC_PIN PA0  // پایه ADC (مثلاً PA0 برای اندازه‌گیری ولتاژ)
#define VREF 3.3     // ولتاژ مرجع ADC (VDDA میکرو، مقدار را دقیق تنظیم کنید)

//****ampermetr***
#define ACS712_PIN PC0     // پایه ADC
#define VREF 3.3           // ولتاژ مرجع (برای بردهای 3.3V)
#define SENSITIVITY 0.185  // برای مدل 5A مقدار 185mV/A
float offset = 0;          // مقدار اولیه
int DCMode = 1;
#include "ACS712.h"
#define SENSOR_PIN PC0            // پایه ADC که خروجی سنسور به آن متصل است
#define SAMPLES 3000              // تعداد نمونه‌گیری برای محاسبه RMS
#define SENSOR_SENSITIVITY 0.185  // حساسیت سنسور (ACS712-58A = 0.185V/A) (ACS712-30A = 0.06V/A)
float offsetVoltage = 0.0;        // مقدار ولتاژ آفست سنسور
float currentRMS = 0.0;           // جریان RMS

//*****generator****
#define PWM_PIN1 PA8        // خروجی اول (تایمر 1، کانال 1)
#define PWM_PIN2 PB6        // خروجی دوم (تایمر 4، کانال 1)
HardwareTimer myTimer1(1);  // به جای timer1
HardwareTimer myTimer4(4);  // به جای timer4
float dutyCycle = 30;
int pwmFrequency = 100;
int plus100;
int SensorPulsePin = PB1;

//frequency
volatile int mon_flag;
float freq;
byte fq[8], pd, x;


//oskop
const int analogPin = PA0;
int sampleSize = 500;  // تعداد نمونه‌ها (یک خط کامل نمایشگر)
uint16_t samples[5000];
uint16_t lastSamples[5000];  // ذخیره مقادیر قبلی موج
// مقیاس ولتاژ
float voltageScale = 3.3 / 4095.0;
float threshold = .1;  //200 آستانه برای تشخیص لبه2048
// متغیرهای فرکانس
volatile unsigned long lastEdgeTime = 0;
volatile float frequency_ = 0;
long debounceTime = 200;  // حداقل فاصله زمانی بین دو لبه (بر حسب میکروثانیه)
// اندازه بخش مشخصات سیگنال
const int signalInfoHeight = 50;
int test_voltage;
float readv;
int freqFult;
int show_fail;
int volt_cout;
float voltage_avg;
float signal_calib = 1;
float voltage;
String TextLcd;
float timeDiv = .1;
bool hold = false;  // وضعیت ثابت نگه داشتن نمایش
int mainMenuChange;

////temp
#include <SoftWire.h>
#define SDA_PIN PB5
#define SCL_PIN PB7
#define MLX90614_ADDRESS 0x5A  // آدرس سنسور
SoftWire myWire(SDA_PIN, SCL_PIN);
uint16_t readRegister(uint8_t reg) {
  myWire.beginTransmission(MLX90614_ADDRESS);
  myWire.write(reg);
  myWire.endTransmission(false);
  myWire.requestFrom(MLX90614_ADDRESS, (uint8_t)2);

  uint16_t data = myWire.read();
  data |= (uint16_t)myWire.read() << 8;
  return data;
}

//ohmeter
#define ADS1115_ADDRESS 0x48  // آدرس پیش فرض
#define R_REF 10000           // مقاومت مرجع (10KΩ دقیق)
void writeRegister(uint8_t reg, uint16_t value) {
  myWire.beginTransmission(ADS1115_ADDRESS);
  myWire.write(reg);
  myWire.write(value >> 8);
  myWire.write(value & 0xFF);
  myWire.endTransmission();
}
int16_t readADC() {
  myWire.beginTransmission(ADS1115_ADDRESS);
  myWire.write(0x00);  // آدرس رجیستر دیتا
  myWire.endTransmission();
  myWire.requestFrom(ADS1115_ADDRESS, (uint8_t)2);
  int16_t result = ((int16_t)myWire.read() << 8) | myWire.read();
  return result;
}
void configADS() {
  // کانفیگ: ورودی AIN0 نسبت به GND
  // PGA = ±4.096V, MODE = Single Shot
  writeRegister(0x01, 0xC283);
}

float readVoltage() {
  configADS();
  myWire.beginTransmission(ADS1115_ADDRESS);
  myWire.write(0x00);
  myWire.endTransmission();
  delay(10);
  int16_t raw = readADC();
  float voltage = (raw * 4.096) / 32768.0;
  if (voltage < 0) voltage = 0;  // از نوسان نویز جلوگیری کن
  return voltage;
}


void drawImage(int x, int y, const int imgWidth, const int imgHeight, const uint16_t file[]) {  // const uint16_t epd_bitmap_main1 [] PROGMEM = {
  int index = 0;
  for (int j = 0; j < imgHeight; j++) {
    for (int i = 0; i < imgWidth; i++) {
      tft.drawPixel(x + i, y + j, file[index++]);
    }
  }
}


/**********************************************Setup****************************************************/
/**********************************************Setup****************************************************/
/**********************************************Setup****************************************************/
/**********************************************Setup****************************************************/
void setup() {
  myWire.begin();
  Serial1.begin(115200);
  pinMode(PA0, INPUT);  // تنظیم پایه در حالت آنالوگ
  // adc_calibrate(ADC1);                        // کالیبره کردن ADC برای دقت بیشتر
  // adc_set_sample_rate(ADC1, ADC_SMPR_239_5);  // افزایش زمان نمونه‌گیری برای کاهش نویز
  pinMode(buzzer, OUTPUT);
  pinMode(ingnd, INPUT);
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  pinMode(ReleAmper, OUTPUT);
  pinMode(Releselonoeid, OUTPUT);
  pinMode(SimulatorLow, OUTPUT);
  pinMode(SensorPulsePin, OUTPUT);
  digitalWrite(SimulatorLow, 0);
  digitalWrite(buzzer, 1);
  delay(100);
  digitalWrite(buzzer, 0);
  delay(100);
  digitalWrite(buzzer, 1);
  delay(200);
  digitalWrite(buzzer, 0);
  digitalWrite(rele1, 0);
  digitalWrite(rele2, 0);
  digitalWrite(rele3, 0);
  digitalWrite(rele4, 0);
  digitalWrite(ReleAmper, 0);
  keyPadconfig();
  tft.begin();
  //tft.setFont(&FreeSansOblique9pt7b);
  tft.setRotation(3);  // now canvas is 11x21
  tft.fillScreen(ILI9488_BLACK);

  pinMode(ACS712_PIN, INPUT_ANALOG);
  Serial1.println("Start...");

  //generator
  pinMode(PWM_PIN1, PWM);
  pinMode(PWM_PIN2, PWM);
  myTimer1.pause();        // متوقف کردن تایمر
  digitalWrite(PA8, LOW);  // پین را صفر کن
  myTimer4.pause();        // متوقف کردن تایمر
  digitalWrite(PB6, LOW);  // پین را صفر کن


  ///فرکانس
  pinMode(PA15, INPUT_PULLDOWN);  // вход частотомера
  //pinMode(PA2, INPUT_PULLUP);

  RCC_BASE->APB1ENR |= (1 << 2) | (1 << 1) | (1 << 0);                         //включить тактирование tim-2,3,4
  RCC_BASE->APB2ENR |= (1 << 3) | (1 << 11) | (1 << 2) | (1 << 0) | (1 << 4);  ////включить тактирование port-a-b-c,tim1
  AFIO_BASE->MAPR = (1 << 8) | (1 << 6);
  Serial1.println("Start...");
  //first Config//
  mute = 1;
  changeMenu = 0;  //taaqir menu
  MenuSelect = 1;  //option Select
  mainMenu = 1;    //main menu Select
  mainMenuChange = 1;
  tft.fillScreen(ILI9488_BLACK);
  drawImage(120, 0, 175, 41, epd_bitmap_logo);  // نمایش در مختصات (60,60)
  drawImage(315, 0, 159, 41, epd_bitmap_help);  // نمایش در مختصات (60,60)
  releAnalyzer();
}

void loop() {
  menu2();
}
