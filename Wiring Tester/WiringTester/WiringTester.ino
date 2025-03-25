//lcd
#include "SPI.h"
#include <Adafruit_GFX.h>
#include <ILI9488.h>
#define TFT_CS PA3
#define TFT_DC PA2
#define TFT_LED PA1
#define TFT_RST PA8
ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);


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
int dutyCycle = 30;
int pwmFrequency = 100;
int plus100;
void setup() {
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
  tft.setRotation(3);  // now canvas is 11x21
  tft.fillScreen(ILI9488_BLACK);

  pinMode(ACS712_PIN, INPUT_ANALOG);
  Serial1.println("Start...");
  mute = 1;

  //generator
  pinMode(PWM_PIN1, PWM);
  pinMode(PWM_PIN2, PWM);
  myTimer1.pause();        // متوقف کردن تایمر
  digitalWrite(PA8, LOW);  // پین را صفر کن
  myTimer4.pause();        // متوقف کردن تایمر
  digitalWrite(PB6, LOW);  // پین را صفر کن
}

void loop() {
  menu();
}
