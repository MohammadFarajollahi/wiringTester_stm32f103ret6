#include "SPI.h"
#include <Adafruit_GFX.h>
#include <ILI9488.h>
#include "image_array.h"  // آرایه تصویر را اضافه کن

#define TFT_CS   PA3
#define TFT_DC   PA2
#define TFT_LED  PA1
#define TFT_RST  PA8

// مقداردهی نمایشگر
ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);

// ابعاد تصویر (حتما مقدار صحیح را بگذار)
#define IMAGE_WIDTH  240  // عرض تصویر
#define IMAGE_HEIGHT 320  // ارتفاع تصویر

void setup() {
    Serial1.begin(115200);
    Serial1.println("شروع نمایش تصویر از حافظه داخلی...");

    tft.begin();
    tft.fillScreen(ILI9488_BLACK);
    
    Serial1.println("در حال نمایش تصویر...");
    tft.drawRGBBitmap(0, 0, myImage, IMAGE_WIDTH, IMAGE_HEIGHT);

    Serial1.println("نمایش کامل شد!");
}

void loop() {
  // حلقه اصلی خالی است چون فقط یک بار تصویر نمایش داده می‌شود.
}
