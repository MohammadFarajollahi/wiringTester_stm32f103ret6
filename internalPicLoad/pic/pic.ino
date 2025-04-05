//https://javl.github.io/image2cpp/

//lcd
#include "SPI.h"
#include <Adafruit_GFX.h>
#include <ILI9488.h>
#define TFT_CS PA3
#define TFT_DC PA2
#define TFT_LED PA1
#define TFT_RST PA8
ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);
#include "logo.h"
#include "mainmenu.h"
// 📦 فونت آماده
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeMonoBoldOblique18pt7b.h>


// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 10640)
// const int epd_bitmap_allArray_LEN = 1;
// const uint16_t* epd_bitmap_allArray[1] = {
// 	epd_bitmap_logo,
// 	epd_bitmap_main1
// };

// 🎯 تابع رسم تصویر
void drawImage(int x, int y, const int imgWidth, const int imgHeight, const uint16_t file[]) {  // const uint16_t epd_bitmap_main1 [] PROGMEM = {
	int index = 0;
	for (int j = 0; j < imgHeight; j++) {
		for (int i = 0; i < imgWidth; i++) {
			tft.drawPixel(x + i, y + j, file[index++]);
		}
	}
}

void setup() {
	tft.begin();
	tft.setRotation(3);  // جهت صفحه: 0 تا 3
	tft.fillScreen(ILI9488_BLACK);

	drawImage(350, 50, 130, 260, epd_bitmap_main1);  // نمایش در مختصات (60,60)
	drawImage(0, 0, 175, 41, epd_bitmap_logo);       // نمایش در مختصات (60,60)
	                                                 // // 🌟 فونت اول
	                                                 // tft.setFont(&FreeSans12pt7b);
	                                                 // tft.setTextColor(ILI9488_CYAN);
	                                                 // tft.setCursor(10, 50);
	                                                 // tft.print("Font: FreeSans");

	// // 🌟 فونت دوم
	// tft.setFont(&FreeMonoBoldOblique18pt7b);
	// tft.setTextColor(ILI9488_YELLOW);
	// tft.setCursor(10, 120);
	// tft.print("Bold Italic");

	// // 🔁 بازگشت به فونت پیش‌فرض
	// tft.setFont();  // یعنی فونت بیت‌مپ پیش‌فرض
	// tft.setTextColor(ILI9488_WHITE);
	// tft.setCursor(10, 200);
	// tft.print("Default Font");
}

void loop() {
	// چیزی تو loop نیست :)
}
