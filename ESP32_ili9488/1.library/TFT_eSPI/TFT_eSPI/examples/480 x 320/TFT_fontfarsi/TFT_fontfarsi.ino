/*
 Font draw speed and flicker test, draws all numbers 0-999 in each font
 Average time in milliseconds to draw each character is shown in red
 
 A total of 2890 characters are drawn in each font then the time per
 character printed on screen
 
  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  #########################################################################
 */

#include <SPI.h>

#include <TFT_eSPI.h> // Hardware-specific library
// #include "Fonts/AF8x8.h"
// #include "Fonts/AF9x10.h"
// #include "Fonts/AF9x11.h"
 #include "Fonts/AF12x16.h"
// #include "Fonts/AF12x16DF.h"
TFT_eSPI tft = TFT_eSPI();       // Invoke custom library



void setup(void) {
  tft.begin();
  tft.SetFont(AF12x16); 
  
}

void loop() {

        //  tft.LcdFontXScale(1);
        //  tft.LcdFontYScale(1);   
        //  tft.fillScreen(TFT_BLACK); 
        //  tft.setRotation(2);     
        //  tft.SetLetter(P_LETTER);          
        //  tft.SetFgColor(TFT_WHITE);
        //  tft.SetBkColor(TFT_BLACK);
        //  tft.SetCursor(0 ,0);
        //  tft.Puts("  به نام خدا  ");

         tft.setRotation(2);
         tft.SetLetter(P_LETTER); 
         tft.fillScreen(TFT_BLACK); 
         tft.LcdFontXScale(1);
         tft.LcdFontYScale(1);   
         tft.drawString(0,0,"  میکرونیک  ",TFT_WHITE ,TFT_BLACK );

         tft.LcdFontXScale(2);
         tft.LcdFontYScale(2);   
         tft.drawString(1,0,"  میکرونیک  ",TFT_WHITE ,TFT_BLACK );

         tft.LcdFontXScale(3);
         tft.LcdFontYScale(3);   
         tft.drawString(2,0,"  میکرونیک  ",TFT_WHITE ,TFT_BLACK );


         tft.LcdFontXScale(4);
         tft.LcdFontYScale(4);          
         tft.drawString(3,0,"  میکرونیک  ",TFT_WHITE ,TFT_BLACK );

         tft.LcdFontXScale(5);
         tft.LcdFontYScale(5);          
         tft.drawString(4,0,"  میکرونیک  ",TFT_WHITE ,TFT_BLACK );
       
         delay(3000);


         tft.LcdFontXScale(3);
         tft.LcdFontYScale(3);   
         tft.fillScreen(TFT_BLACK); 
         tft.setRotation(2);     
         tft.SetLetter(P_LETTER); 
                        
         tft.drawString(0,0,"  به نام خدا  ",TFT_BLACK ,TFT_WHITE );
         tft.drawString(1,0,"  فونت فارسی  ",TFT_BLACK ,TFT_BLUE );
         tft.drawString(2,0,"  میکرونیک  ",TFT_BLACK ,TFT_RED );

         tft.setTextColor(TFT_WHITE,TFT_BLACK );
         tft.drawString(" micronik.ir",0,220,4 );
         tft.setTextColor(TFT_WHITE,TFT_BLACK );
         tft.drawString(" TFT ili9488",0 ,240,4 );
         tft.setTextColor(TFT_WHITE,TFT_BLACK );
         tft.drawString(" ESP32 & ESP8266",0,260,4 );
         
        // Set the font colour to be green with black background, set to font 4
        tft.setCursor(0, 290, 4);
       // tft.setTextFont(4);
        tft.setTextColor(TFT_GREEN,TFT_BLACK);       
        tft.println(" micronik.ir");        
        tft.println(" TFT ili9488");
        tft.print(" ESP32 & ESP8266");


        //tft.drawFloat(12.5, 2, 100, 80, 4);

        delay(5000);

        tft.fillScreen(TFT_BLUE);
        tft.setTextColor(TFT_WHITE, TFT_BLUE);  
        for (int i = 0; i < 1000; i++) {
        tft.drawNumber(i, 80 , 180, 8);
                                       }

  delay(3000);
}