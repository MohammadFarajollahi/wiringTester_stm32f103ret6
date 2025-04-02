
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

//oskop
const int analogPin = PA0;
int sampleSize = 480;  // تعداد نمونه‌ها (یک خط کامل نمایشگر)
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
void setup() {
  Serial1.begin(115200);
  pinMode(PA0, INPUT);  // تنظیم پایه در حالت آنالوگ
  tft.begin();
  tft.setRotation(3);  // now canvas is 11x21
  tft.fillScreen(ILI9488_BLACK);
  keyPadconfig();
  drawGrid();
}

void loop() {
  if (!hold) {
    oskop();
  }
}

void drawGrid() {
  // رسم شبکه برای صفحه نمایشگر
  tft.setTextColor(ILI9488_DARKGREY);
  for (int x = 0; x < 480; x += 40) {
    tft.drawLine(x, 0, x, 320 - signalInfoHeight, ILI9488_DARKGREY);
  }
  for (int y = 0; y < 320 - signalInfoHeight; y += 40) {
    tft.drawLine(0, y, 480, y, ILI9488_DARKGREY);
  }
}

void drawSignalInfo(float voltage, float freq) {
  // نمایش اطلاعات سیگنال در پایین صفحه

  tft.setTextColor(ILI9488_YELLOW);
  tft.fillRect(0, 300 - signalInfoHeight, 480, 320, ILI9488_BLACK);
  tft.fillRect(0, 300 - signalInfoHeight, 480, signalInfoHeight, ILI9488_BLACK);
  tft.setCursor(200, 300 - signalInfoHeight + 10);
  TextLcd = "frequency:" + String(freq, 2) + "HZ";
  tft.print(TextLcd);
  tft.setCursor(10, 300 - signalInfoHeight + 10);
  TextLcd = "Voltage:" + String(voltage, 2) + "V";
  tft.print(TextLcd);
  tft.setCursor(10, 290);
  TextLcd = "voltageScale:" + String(signal_calib, 2);
  tft.print(TextLcd);
  tft.setCursor(260, 290);
  TextLcd = "threshold:" + String(sampleSize);
  tft.print(TextLcd);
}

void drawWaveform() {
  for (int i = 0; i < sampleSize - 1; i++) {
    int x1 = i;
    int y1 = map(lastSamples[i], 0, 4095, 270 - signalInfoHeight - 1, 0);
    int x2 = i + 1;
    int y2 = map(lastSamples[i + 1], 0, 4095, 270 - signalInfoHeight - 1, 0);

    // پاک کردن موج قبلی
    tft.drawLine(x1, y1, x2, y2, ILI9488_BLACK);

    // رسم موج جدید
    y1 = map(samples[i], 0, 4095, 270 - signalInfoHeight - 1, 0);
    y2 = map(samples[i + 1], 0, 4095, 270 - signalInfoHeight - 1, 0);
    tft.drawLine(x1, y1, x2, y2, ILI9488_GREEN);
  }

  // ذخیره مقادیر فعلی برای حذف موج در فریم بعدی
  memcpy(lastSamples, samples, sizeof(samples));
}

void oskop() {

  unsigned long currentTime = micros();

  // خواندن نمونه‌ها
  for (int i = 0; i < sampleSize; i++) {
    samples[i] = analogRead(analogPin);
    delayMicroseconds(timeDiv * 10);  // تأثیر Time/Div بر روی سرعت نمونه‌برداری
    samples[i] *= signal_calib;
    // تشخیص لبه‌ها برای محاسبه فرکانس
    static bool lastSignalState = false;
    bool currentSignalState = samples[i] > threshold;

    if (currentSignalState && !lastSignalState) {  // تشخیص لبه بالا
      unsigned long timeNow = micros();
      unsigned long pulseWidth = timeNow - lastEdgeTime;

      if (pulseWidth > debounceTime) {        // حذف نویز
        frequency_ = 1000000.0 / pulseWidth;  // فرکانس بر حسب هرتز
        lastEdgeTime = timeNow;
      }
    }
    lastSignalState = currentSignalState;
  }

  // رسم موج سیگنال
  drawWaveform();

  // محاسبه ولتاژ و نمایش مشخصات سیگنال
  float voltage = analogRead(analogPin) * voltageScale;
  voltage *= 6.833333;
  voltage_avg += voltage;
  ++volt_cout;
  if (volt_cout >= 1) {
    voltage_avg /= 3;
    voltage = voltage_avg;
    voltage_avg = 0;
    volt_cout = 1;
    drawSignalInfo(voltage, frequency_);
  }

  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    //بلندگو خاموش
    if (key == 'A') {
      sampleSize += 100;
      delay(20);
    }

    if (key == 'B') {
      sampleSize -= 100;
      delay(20);
    }

    if (key == '1') {
      timeDiv += .1;
      delay(1);
    }

    if (key == '2') {
      timeDiv -= .1;
      delay(1);
    }

    if (key == 'C') {
      signal_calib += .1;
      delay(50);
    }

    if (key == 'D') {
      signal_calib -= .1;
      delay(50);
    }

    if (key == '#') {
      hold = !hold;
      delay(100);
    }
  }
  // delay(10);
}



void keyPadconfig() {
  // تنظیم ردیف‌ها به خروجی
  for (int i = 0; i < ROWS; i++) {
    pinMode(rowPins[i], OUTPUT);
    delay(1);
    digitalWrite(rowPins[i], HIGH);
  }

  // تنظیم ستون‌ها به ورودی با پول‌آپ داخلی
  for (int j = 0; j < COLS; j++) {
    pinMode(colPins[j], INPUT_PULLUP);
    delay(1);
  }
}

// تابع برای خواندن کلیدها
char getKey() {
  for (int i = 0; i < ROWS; i++) {
    digitalWrite(rowPins[i], LOW);  // ردیف موردنظر را LOW کن
    delayMicroseconds(1);

    for (int j = 0; j < COLS; j++) {
      if (digitalRead(colPins[j]) == LOW) {  // اگر ستونی LOW شد، یعنی کلید فشرده شده
        //  (digitalRead(colPins[j]) == LOW)
        //   ;                              // صبر کن تا رها شود
        digitalWrite(rowPins[i], HIGH);  // ردیف را دوباره HIGH کن
        return keys[i][j];               // مقدار کلید را برگردان
      }
    }

    digitalWrite(rowPins[i], HIGH);  // بعد از چک کردن، ردیف را HIGH کن
  }
  return '\0';  // اگر کلیدی فشرده نشد، مقدار خالی برگردان
}