
//lcd
#include "SPI.h"
#include <Adafruit_GFX.h>
#include <ILI9488.h>
#define TFT_CS PA3
#define TFT_DC PA2
#define TFT_LED PA1
#define TFT_RST PA8
ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);



//oskop
const int analogPin = PA0;
int sampleSize = 1900;  // تعداد نمونه‌ها (یک خط کامل نمایشگر)
uint16_t samples[2000];
uint16_t lastSamples[2000];  // ذخیره مقادیر قبلی موج
// مقیاس ولتاژ
float voltageScale = 3.3 / 4095.0;
int threshold = 1;  //200 آستانه برای تشخیص لبه2048
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

void setup() {
  Serial1.begin(115200);
  pinMode(PA0, INPUT);  // تنظیم پایه در حالت آنالوگ
  tft.begin();
  tft.setRotation(3);  // now canvas is 11x21
  tft.fillScreen(ILI9488_BLACK);
  drawGrid();
}

void loop() {
  oskop();
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


  if (voltage == 0) {
    ++test_voltage;
    if (test_voltage >= 3) {
      tft.fillRect(0, 300 - signalInfoHeight, 480, 320, ILI9488_BLACK);


      test_voltage = 10;
      tft.setCursor(200, 300 - signalInfoHeight + 10);
      tft.print("frequency: No Signal");
      tft.setCursor(10, 300 - signalInfoHeight + 10);
      TextLcd = "Voltage:" + String(voltage, 2) + "V";
      tft.print(TextLcd);
      freqFult = 1;
      if (show_fail == 0) {

        show_fail = 1;
      }
    }
  } else {
    freqFult = 0;
    test_voltage = 0;
  }

  if (freqFult == 0) {
    if (voltage > 0) {
      tft.fillRect(0, 300 - signalInfoHeight, 480, signalInfoHeight, ILI9488_BLACK);
      tft.setCursor(200, 300 - signalInfoHeight + 10);
      TextLcd = "frequency:" + String(freq, 2) + "HZ";
      tft.print(TextLcd);



      tft.setCursor(10, 300 - signalInfoHeight + 10);
      TextLcd = "Voltage:" + String(voltage, 2) + "V";
      tft.print(TextLcd);
      // tft.printf("Voltage: %.2f V", voltage);
    }
    if (show_fail == 1) {
      show_fail = 0;
    }
  }


  tft.setCursor(10, 290);
  TextLcd = "voltageScale:" + String(signal_calib, 2);
  tft.print(TextLcd);

  tft.setCursor(260, 290);
  TextLcd = "threshold:" + String(sampleSize) ;
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
  if (volt_cout >= 3) {
    voltage_avg /= 3;
    voltage = voltage_avg;
    voltage_avg = 0;
    volt_cout = 0;
    drawSignalInfo(voltage, frequency_);
  }
 // delay(10);
}