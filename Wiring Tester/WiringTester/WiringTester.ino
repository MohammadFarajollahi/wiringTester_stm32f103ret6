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
const int rowPins[ROWS] = { PB1, PB2, PB3, PB4 };  // ردیف‌ها
const int colPins[COLS] = { PB5, PB6, PB7, PB8 };  // ستون‌ها
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
int buzzer = PB0;
int ingnd = PA1;
String text;
int mute = 1;
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
  digitalWrite(buzzer, 1);
  delay(100);
  digitalWrite(buzzer, 0);
  delay(100);
  digitalWrite(buzzer, 1);
  delay(200);
  digitalWrite(buzzer, 0);
  digitalWrite(rele1, 0);
  digitalWrite(rele1, 0);
  digitalWrite(rele2, 0);
  digitalWrite(rele3, 0);
  digitalWrite(rele4, 0);
  keyPadconfig();
  tft.begin();
  tft.setRotation(3);  // now canvas is 11x21
  tft.fillScreen(ILI9488_BLACK);

  Serial1.println("Start...");

  // tone(buzzer, 2000);  // فرکانس 500 هرتز
  // delay(1000);
  // noTone(buzzer);  // خاموش کردن بازر
}

void loop() {
  menu();


  // tft.setCursor(0, 50);
  // tft.setTextColor(ILI9488_WHITE);
  // tft.fillRect(0, 50, 100, 20, ILI9488_BLACK);
  // tft.println(i);
}
