

void menu2() {

  if (mainMenuChange == 1) {
    mainMenuChange = 0;
    if (mainMenu == 1) {
      tft.drawLine(0, 40, 480, 40, ILI9488_WHITE);
      tft.drawLine(308, 40, 308, 320, ILI9488_WHITE);
      drawImage(320, 50, 130, 260, epd_bitmap_main1);  // نمایش در مختصات (60,60)
      tft.setTextSize(2);
      tft.setCursor(452, 58);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      if (mute == 1) {
        tft.setTextSize(1);
        digitalWrite(buzzer, 0);
        tft.setCursor(0, 26);
        tft.setTextColor(ILI9488_RED);
        tft.println("MUTE");
      }
      if (mute == 0) {
        tft.fillRect(0, 26, 50, 7, ILI9488_BLACK);
      }
    }
  }

  if (changeMenu == 1) {
    changeMenu = 0;
    if (mainMenu == 1) {
      //**********Logic Analyzer***********
      if (MenuSelect == 1) {
        digitalWrite(SensorPulsePin, 0);
        releAnalyzer();
        tft.setTextSize(2);
        //logic
        tft.setCursor(90, 50);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("Logic Analyzer");
        //circle
        tft.fillCircle(70, 190, 20, ILI9488_WHITE);   //gnd
        tft.fillCircle(200, 190, 20, ILI9488_WHITE);  //+12
        tft.fillCircle(70, 270, 20, ILI9488_WHITE);   //+5
        tft.fillCircle(200, 270, 20, ILI9488_WHITE);  //signal
        //logicName
        tft.setCursor(52, 220);
        tft.setTextColor(ILI9488_BLUE);
        tft.println("GND");
        tft.setCursor(180, 220);
        tft.setTextColor(ILI9488_RED);
        tft.println("+12");
        tft.setCursor(50, 300);
        tft.setTextColor(ILI9488_GREEN);
        tft.println("+5V");
        tft.setCursor(170, 300);
        tft.setTextColor(ILI9488_YELLOW);
        tft.println("SENSOR");
        while (1) {
          logicAnalyze();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            break;
          }
        }
      }

      //**********volt Meter***********
      if (MenuSelect == 2) {
        releAnalyzer();
        //logic
        tft.setCursor(90, 50);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("Volt Meter");
        while (1) {
          VoltMEter();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;        
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            break;
          }
        }
      }
      ///////////main Menu1
    }
  }

  ReadMainKeypad2();
}



//**********************************************menu Select********************************************
//**********************************************menu Select********************************************
//**********************************************menu Select********************************************
void ReadMainKeypad2() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    BuzzerBIGbig();
    if ((key == '1') || (key == '2') || (key == '3') || (key == '4') || (key == '5') || (key == '6') || (key == '7') || (key == '8') || (key == '9')) {
      tft.fillRect(452, 58, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 88, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 116, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 145, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 174, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 204, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 234, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 262, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 290, 480, 15, ILI9488_BLACK);
    }

    //بلندگو خاموش
    if (key == 'C') {
      digitalWrite(buzzer, 1);
      delay(100);
      digitalWrite(buzzer, 0);
      mute ^= 1;
      Serial1.println(mute);
      if (mute == 1) {
        tft.setTextSize(1);
        digitalWrite(buzzer, 0);
        tft.setCursor(0, 26);
        tft.setTextColor(ILI9488_RED);
        tft.println("MUTE");
      }
      if (mute == 0) {
        tft.fillRect(0, 26, 50, 7, ILI9488_BLACK);
      }
      delay(100);
    }

    if (key == 'A') {
      mainMenu++;
      mainMenuChange = 1;
    }

    if (key == '*') {
      changeMenu = 1;
    }

    if (key == '1') {
      MenuSelect = 1;
      tft.setTextSize(2);
      tft.setCursor(452, 58);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
    }
    if (key == '2') {
      tft.setTextSize(2);
      tft.setCursor(452, 88);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 2;
    }
    if (key == '3') {
      tft.setTextSize(2);
      tft.setCursor(452, 116);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 3;
    }
    if (key == '4') {
      tft.setTextSize(2);
      tft.setCursor(452, 145);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 4;
    }
    if (key == '5') {
      tft.setTextSize(2);
      tft.setCursor(452, 174);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 5;
    }

    if (key == '6') {
      tft.setTextSize(2);
      tft.setCursor(452, 204);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 6;
    }

    if (key == '7') {
      tft.setTextSize(2);
      tft.setCursor(452, 234);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 7;
    }
    if (key == '8') {
      tft.setTextSize(2);
      tft.setCursor(452, 262);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 8;
    }
    if (key == '9') {
      tft.setTextSize(2);
      tft.setCursor(452, 290);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 9;
    }
    delay(250);
  }
}