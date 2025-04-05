#include "SPI.h"
#include <Adafruit_GFX.h>
#include <ILI9488.h>
#define TFT_CS PA3
#define TFT_DC PA2
#define TFT_LED PA1
#define TFT_RST PA8
ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);
// 📦 فونت آماده
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeMonoBoldOblique18pt7b.h>
#include <Fonts/farsi.h>

void setup() {
  tft.begin();
  tft.setRotation(3);  // جهت صفحه: 0 تا 3
  tft.fillScreen(ILI9488_BLACK);

  // 🌟 فونت اول
  tft.setFont(&FreeSans12pt7b);
  tft.setTextColor(ILI9488_CYAN);
  tft.setCursor(10, 50);
  tft.print("Font: FreeSans");

  // 🌟 فونت دوم
  tft.setFont(&FreeMonoBoldOblique18pt7b);
  tft.setTextColor(ILI9488_YELLOW);
  tft.setCursor(10, 120);
  tft.print("Bold Italic");


  // 🔁 بازگشت به فونت پیش‌فرض
  tft.setFont(&farsi);
  tft.setTextColor(ILI9488_WHITE);
  tft.setCursor(10, 200);
  tft.print("Dolol");

  // 🌟 فونت دوم
  tft.setFont(&FreeMonoBoldOblique18pt7b);
  tft.setTextColor(ILI9488_YELLOW);
  tft.setCursor(10, 400);
  tft.print("dodol");
}

void loop() {
  // چیزی تو loop نیست :)
}
