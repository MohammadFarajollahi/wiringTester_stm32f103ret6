

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
            releAnalyzer();
            break;
          }
        }
      }

      //**********volt Meter***********
      if (MenuSelect == 2) {
        releAnalyzer();
        tft.setCursor(90, 50);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("Volt Meter");
        while (1) {
          VoltMEter();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }

      //**********Amper Meter***********
      if (MenuSelect == 3) {
        releCurrent();
        tft.setCursor(90, 50);
        tft.setTextColor(ILI9488_CYAN);
        tft.println("Amper Meter");
        tft.fillRect(0, 75, 140, 20, ILI9488_BLACK);
        tft.setCursor(0, 75);
        digitalWrite(buzzer, 0);
        tft.setTextColor(ILI9488_MAGENTA);
        tft.println("Dc Mode");
        DCMode = 1;
        float sum = 0;
        for (int i = 0; i < 200; i++) {
          sum += analogRead(ACS712_PIN);
          delay(1);
        }
        offset = (sum / 200.0) * VREF / 4095.0;  // میانگین‌گیری برای حذف نویز
        while (1) {
          AmpereMeter();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }
      //**********OHM Meter***********
      if (MenuSelect == 4) {
        releOhmeter();
        tft.setCursor(90, 50);
        tft.setTextColor(ILI9488_YELLOW);
        tft.println("OHM Meter");
        // tft.fillRect(0, 75, 140, 20, ILI9488_BLACK);
        // tft.setCursor(0, 75);
        // digitalWrite(buzzer, 0);
        // tft.setTextColor(ILI9488_RED);
        // tft.println("Dc Mode");
        while (1) {
          ohMmeter();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }

      //**********Frequency Meter***********
      if (MenuSelect == 5) {
        releFrequency();
        tft.setCursor(72, 50);
        tft.setTextColor(ILI9488_YELLOW);
        tft.println("Frequency Meter");
        while (1) {
          FrequencyMeter();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }

      //**********thermometer***********
      if (MenuSelect == 6) {
        releAnalyzer();
        //logic
        tft.setCursor(90, 50);
        tft.setTextColor(ILI9488_WHITE);
        tft.println(" Thermometer ");

        text = "Press *";
        tft.setTextSize(3);
        tft.setTextColor(ILI9488_YELLOW);
        tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
        tft.setCursor(0, 170);
        tft.println(text);
        while (1) {
          Thermometer();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }
      //**********Oskop***********
      if (MenuSelect == 7) {
        tft.fillScreen(ILI9488_BLACK);
        releAnalyzer();
        drawGrid();
        OutOskop = 0;
        tft.setTextSize(1);
        tft.setCursor(1, 1);
        tft.setTextColor(ILI9488_RED);
        tft.println("Oscilloscope");
        tft.setCursor(1, 20);
        tft.setTextColor(ILI9488_CYAN);
        tft.println("# -> Exit");
        tft.setCursor(200, 1);
        tft.println("4 & 6 -> Time/DIV");
        tft.setCursor(320, 1);
        tft.println("C & D -> THreshold");
        tft.setCursor(200, 20);
        tft.println("2 & 8 -> VoltSale");
        tft.setCursor(320, 20);
        tft.println("* -> Pause");
        while (1) {
          OskoP();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            changeMenu = 0;  //taaqir menu
            MenuSelect = 1;  //option Select
            mainMenu = 1;    //main menu Select
            mainMenuChange = 1;
            tft.fillScreen(ILI9488_BLACK);
            drawImage(120, 0, 175, 41, epd_bitmap_logo);  // نمایش در مختصات (60,60)
            drawImage(315, 0, 159, 41, epd_bitmap_help);  // نمایش در مختصات (60,60)
            releAnalyzer();
            break;
          }
        }
      }

      //**********Selonoei***********
      if (MenuSelect == 8) {
        releGenerator();
        tft.setTextSize(2);
        tft.setCursor(70, 50);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("solenoid Tester ");

        dutyCycle = 10;
        pwmFrequency = 200;
        plus100 = 1;

        if (plus100 == 1) {
          tft.setTextSize(1);
          tft.fillRect(0, 300, 150, 20, ILI9488_BLACK);
          digitalWrite(buzzer, 0);
          tft.setCursor(0, 300);
          tft.setTextColor(ILI9488_WHITE);
          tft.println("D: Pulse Count -> +100");
        }
        if (plus100 == 0) {
          tft.setTextSize(1);
          tft.fillRect(0, 300, 150, 20, ILI9488_BLACK);
          digitalWrite(buzzer, 0);
          tft.setCursor(0, 300);
          tft.setTextColor(ILI9488_YELLOW);
          tft.println("D: Pulse Count -> +1");
        }

        tft.setTextSize(2);
        text = "Frequency:" + String(pwmFrequency) + " HZ";
        tft.setTextColor(ILI9488_YELLOW);
        tft.fillRect(0, 100, 270, 20, ILI9488_BLACK);
        tft.setCursor(0, 100);
        tft.println(text);

        text = "Duty:" + String(dutyCycle) + " %";
        tft.setTextColor(ILI9488_CYAN);  //ILI9488_MAGENTA
        tft.fillRect(0, 130, 250, 20, ILI9488_BLACK);
        tft.setCursor(0, 130);
        tft.println(text);

        setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);



        tft.setTextSize(1);
        tft.fillRect(0, 280, 150, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(0, 280);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("2,8: Frequency Control  4,6:Duty Control");
        while (1) {
          Generator();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }

        //**********Signal Generator***********
      if (MenuSelect == 6) {
        releAnalyzer();
        //logic
        tft.setCursor(70, 50);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("Signal Generator");

      
        while (1) {
          SignalGenerator();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
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