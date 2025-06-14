

void menu2() {

  if (mainMenuChange == 1) {
    mainMenuChange = 0;
    /////**************************************************************Main Menu1***************************************************/////
    /////**************************************************************Main Menu1***************************************************/////
    /////**************************************************************Main Menu1***************************************************/////
    if (mainMenu == 1) {
      tft.fillRect(452, 58, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 88, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 116, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 145, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 174, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 204, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 234, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 262, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 290, 480, 15, ILI9488_BLACK);
      tft.drawLine(0, 40, 480, 40, ILI9488_WHITE);
      tft.drawLine(308, 40, 308, 320, ILI9488_WHITE);
      drawImage(320, 50, 130, 260, epd_bitmap_main1);  // نمایش در مختصات (60,60)
      float readPwmVoltage = 0;
      for (int i = 0; i <= 200; i++) {
        readPwmVoltage += analogRead(PC2);
        delayMicroseconds(500);
      }
      readPwmVoltage /= 200;
      readPwmVoltage /= 106.6666666666666666666;
      Serial1.println(readPwmVoltage);

      if (readPwmVoltage >= 11.5) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery1);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage >= 11 && readPwmVoltage < 11.5) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery2);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage >= 10.5 && readPwmVoltage < 11) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery3);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage >= 10 && readPwmVoltage < 10.5) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery4);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage < 10) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery5);  // نمایش در مختصات (60,60)
      }
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
    /////********************************************************************************Main Menu2********************************************************/////
    /////********************************************************************************Main Menu2********************************************************/////
    /////********************************************************************************Main Menu2********************************************************/////
    if (mainMenu == 2) {
      tft.fillRect(452, 58, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 88, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 116, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 145, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 174, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 204, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 234, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 262, 480, 15, ILI9488_BLACK);
      tft.fillRect(452, 290, 480, 15, ILI9488_BLACK);
      tft.drawLine(0, 40, 480, 40, ILI9488_WHITE);
      tft.drawLine(308, 40, 308, 320, ILI9488_WHITE);
      drawImage(320, 50, 130, 260, epd_bitmap_mainmenu2);  // نمایش در مختصات (60,60)
      float readPwmVoltage = 0;
      for (int i = 0; i <= 200; i++) {
        readPwmVoltage += analogRead(PC2);
        delayMicroseconds(500);
      }
      readPwmVoltage /= 200;
      readPwmVoltage /= 106.6666666666666666666;
      Serial1.println(readPwmVoltage);

      if (readPwmVoltage >= 11.5) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery1);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage >= 11 && readPwmVoltage < 11.5) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery2);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage >= 10.5 && readPwmVoltage < 11) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery3);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage >= 10 && readPwmVoltage < 10.5) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery4);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage < 10) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery5);  // نمایش در مختصات (60,60)
      }
      tft.setTextSize(2);
      tft.setCursor(452, 88);  //58 //88
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
  /////********************************************************************************SELECT Menu1********************************************************/////
  /////********************************************************************************SELECT Menu1********************************************************/////
  /////********************************************************************************SELECT Menu1********************************************************/////
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
        tft.println("Wiring Test");
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
        tft.setTextSize(2);
        tft.setTextColor(ILI9488_RED);
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
        tft.setTextSize(2);
        tft.setCursor(40, 50);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("12V Power Supply");

        text = "Press Start";
        tft.setTextSize(3);
        tft.setTextColor(ILI9488_YELLOW);
        tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
        tft.setCursor(0, 170);
        tft.println(text);
        float sum = 0;
        for (int i = 0; i < 200; i++) {
          sum += analogRead(ACS712_PIN);
          delay(1);
        }
        offset = (sum / 200.0) * VREF / 4095.0;  // میانگین‌گیری برای حذف نویز
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
      //**********Selonoei***********
      if (MenuSelect == 8) {
        releGenerator();
        tft.setTextSize(2);
        tft.setCursor(70, 50);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("solenoid Tester ");

        dutyCycle = 10;
        pwmFrequency = 50;
        plus100 = 0;


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
          tft.setTextColor(ILI9488_WHITE);
          tft.println("F4: Pulse Count -> +1");
        }

        tft.setTextSize(2);
        text = "Frequency:" + String(pwmFrequency) + " HZ";
        tft.setTextColor(ILI9488_RED);
        tft.fillRect(0, 100, 270, 20, ILI9488_BLACK);
        tft.setCursor(0, 100);
        tft.println(text);

        text = "Duty:" + String(dutyCycle) + " %";
        tft.setTextColor(ILI9488_CYAN);  //ILI9488_MAGENTA
        tft.fillRect(0, 130, 250, 20, ILI9488_BLACK);
        tft.setCursor(0, 130);
        tft.println(text);

        setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);

        tft.drawLine(10, 240, 290, 240, ILI9488_WHITE);

        tft.setTextSize(2);
        tft.setTextColor(ILI9488_YELLOW);  //ILI9488_MAGENTA
        tft.fillRect(0, 280, 150, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(120, 250);
        tft.println("HELP");
        tft.setTextColor(ILI9488_WHITE);
        tft.setTextSize(2);
        tft.setCursor(0, 275);
        tft.println("2-8: Frequency   4-6:Duty ");

        float sum = 0;
        for (int i = 0; i < 200; i++) {
          sum += analogRead(ACS712_PIN);
          delay(1);
        }
        offset = (sum / 200.0) * VREF / 4095.0;  // میانگین‌گیری برای حذف نویز
        while (1) {
          Generator();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            delay(500);
            break;
          }
        }
      }

      //**********Signal Generator***********
      //**********Signal Generator***********
      if (MenuSelect == 9) {
        releSimulator();
        digitalWrite(SensorPulsePin, 0);  // square wave
        digitalWrite(SimulatorLow, 1);    // Low Voltage
        tft.setTextSize(2);
        tft.setCursor(17, 50);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("Square Signal Generator");

        dutyCycle = 2;
        pwmFrequency = 2000;

        tft.setTextSize(2);
        text = "Frequency:" + String(pwmFrequency) + " HZ";
        tft.setTextColor(ILI9488_RED);
        tft.fillRect(0, 100, 270, 20, ILI9488_BLACK);
        tft.setCursor(0, 100);
        tft.println(text);

        text = "Duty:" + String(dutyCycle) + " %";
        tft.setTextColor(ILI9488_CYAN);  //ILI9488_MAGENTA
        tft.fillRect(0, 130, 250, 20, ILI9488_BLACK);
        tft.setCursor(0, 130);
        tft.println(text);

        tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
        tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
        tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
        tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

        int pwmOut = map(dutyCycle, 1, 99, 50, 237);
        tft.fillRect(11, 260, 237, 30, ILI9488_BLACK);
        tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

        setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
        // delay(50);
        // //*****pwm Voltage*****
        // float readPwmVoltage = 0;
        // for (int i = 0; i <= 200; i++) {
        //   readPwmVoltage += analogRead(PC1);
        //   delayMicroseconds(500);
        // }
        // float PwmVoltage = readPwmVoltage /= 200;
        // float rrr = PwmVoltage;
        // PwmVoltage /= 392.50443150164598632565206381362;
        // tft.setTextSize(2);
        // text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
        // tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
        // tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
        // tft.setCursor(0, 230);
        // tft.println(text);

        ////////////////////pulse100///////////////////////
        plus100 = 2;
        if (plus100 == 1) {
          tft.setTextSize(2);
          tft.fillRect(0, 200, 250, 20, ILI9488_BLACK);
          tft.setCursor(0, 200);
          tft.setTextColor(ILI9488_GREEN);
          tft.println("F4:Pulse Count +0.1");
        }
        if (plus100 == 2) {
          tft.setTextSize(2);
          tft.fillRect(0, 200, 250, 20, ILI9488_BLACK);
          tft.setCursor(0, 200);
          tft.setTextColor(ILI9488_GREEN);
          tft.println("F4:Pulse Count +1");
        }
        if (plus100 == 3) {
          tft.setTextSize(2);
          tft.fillRect(0, 200, 250, 20, ILI9488_BLACK);
          tft.setCursor(0, 200);
          tft.setTextColor(ILI9488_GREEN);
          tft.println("F4:Pulse Count +5");
        }


        while (1) {
          SquarSignalGenerator();
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

    //*********************************************************mainMenu2************************************************
    //*********************************************************mainMenu2************************************************
    //*********************************************************mainMenu2************************************************

    if (mainMenu == 2) {
      //**********Sensor Oxigen***********
      //**********Sensor Oxigen***********
      if (MenuSelect == 1) {
        drawImage(50, 50, 175, 41, epd_bitmap_wirecheck);  // نمایش در مختصات (60,60)
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
          wirecheck();
          char key = getKey();  // خواندن کلید
          if (key != '\0') {
            if (key == '*') {
              break;
            }
          }
          if (key == '#') {
            ExitToMenu = 1;
            break;
          }
        }

        if (ExitToMenu == 0) {
          digitalWrite(buzzer, 1);
          delay(500);
          digitalWrite(buzzer, 0);
          tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
          drawImage(55, 100, 200, 100, epd_bitmap_sensorHelp);
          releSimulator();
          WaterVoltMode = 1;
          digitalWrite(SensorPulsePin, 1);
          digitalWrite(SimulatorLow, 1);
          digitalWrite(releSelf, 1);
          tft.setTextSize(2);
          tft.setCursor(60, 50);
          tft.setTextColor(ILI9488_WHITE);
          tft.println("  Oxygen Sensor");

          dutyCycle = 10;
          pwmFrequency = 2000;

          tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
          tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
          tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
          tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

          int pwmOut = map(dutyCycle, 1, 20, 11, 235);
          tft.fillRect(11, 260, 235, 30, ILI9488_BLACK);
          tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

          setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
          delay(50);
          //*****pwm Voltage*****
          float readPwmVoltage = 0;
          for (int i = 0; i <= 200; i++) {
            readPwmVoltage += analogRead(PC1);
            delayMicroseconds(500);
          }
          float PwmVoltage = readPwmVoltage /= 200;
          float rrr = PwmVoltage;
          PwmVoltage /= 392.50443150164598632565206381362;
          tft.setTextSize(2);
          text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
          tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
          tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
          tft.setCursor(0, 230);
          tft.println(text);
        }
        while (1) {
          if (ExitToMenu == 0) SensorOxigen();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            digitalWrite(SensorPulsePin, 0);
            digitalWrite(releSelf, 0);
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }

      //**********Sensor Water***********
      //**********Sensor Water***********
      if (MenuSelect == 2) {                               // 0 - 3.3v
        drawImage(50, 50, 175, 41, epd_bitmap_wirecheck);  // نمایش در مختصات (60,60)
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
          wirecheck();
          char key = getKey();  // خواندن کلید
          if (key != '\0') {
            if (key == '*') {
              break;
            }
          }
          if (key == '#') {
            ExitToMenu = 1;
            break;
          }
        }

        if (ExitToMenu == 0) {
          digitalWrite(buzzer, 1);
          delay(500);
          digitalWrite(buzzer, 0);
          tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
          drawImage(55, 100, 200, 100, epd_bitmap_sensorHelp);
          releSimulator();
          WaterVoltMode = 1;
          digitalWrite(SensorPulsePin, 1);
          digitalWrite(SimulatorLow, 1);
          digitalWrite(releSelf, 1);
          tft.setTextSize(2);
          tft.setCursor(60, 50);
          tft.setTextColor(ILI9488_WHITE);
          tft.println("  Water Sensor");

          dutyCycle = 20;
          pwmFrequency = 2000;

          tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
          tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
          tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
          tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

          int pwmOut = map(dutyCycle, 1, 65, 11, 235);
          tft.fillRect(11, 260, 235, 30, ILI9488_BLACK);
          tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

          setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
          delay(50);
          //*****pwm Voltage*****
          float readPwmVoltage = 0;
          for (int i = 0; i <= 200; i++) {
            readPwmVoltage += analogRead(PC1);
            delayMicroseconds(500);
          }
          float PwmVoltage = readPwmVoltage /= 200;
          float rrr = PwmVoltage;
          PwmVoltage /= 392.50443150164598632565206381362;
          tft.setTextSize(2);
          text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
          tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
          tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
          tft.setCursor(0, 230);
          tft.println(text);
        }
        while (1) {
          if (ExitToMenu == 0) WaterSensor();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            digitalWrite(SensorPulsePin, 0);
            digitalWrite(releSelf, 0);
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }

      //**********Throttle ***********
      //**********Throttle ***********
      if (MenuSelect == 3) {                               // 0 - 3.3v
        drawImage(50, 50, 175, 41, epd_bitmap_wirecheck);  // نمایش در مختصات (60,60)
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
          wirecheck();
          char key = getKey();  // خواندن کلید
          if (key != '\0') {
            if (key == '*') {
              break;
            }
          }
          if (key == '#') {
            ExitToMenu = 1;
            break;
          }
        }

        if (ExitToMenu == 0) {

          digitalWrite(buzzer, 1);
          delay(500);
          digitalWrite(buzzer, 0);
          tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
          drawImage(55, 100, 200, 100, epd_bitmap_sensorHelp);
          releSimulator();
          WaterVoltMode = 1;
          digitalWrite(SensorPulsePin, 1);
          digitalWrite(SimulatorLow, 1);
          digitalWrite(releSelf, 1);
          tft.setTextSize(2);
          tft.setCursor(70, 50);
          tft.setTextColor(ILI9488_WHITE);
          tft.println("Throttle");

          dutyCycle = 40;
          pwmFrequency = 2000;

          tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
          tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
          tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
          tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

          int pwmOut = map(dutyCycle, 1, 90, 11, 235);
          tft.fillRect(11, 260, 235, 30, ILI9488_BLACK);
          tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

          setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
          delay(50);
          //*****pwm Voltage*****
          float readPwmVoltage = 0;
          for (int i = 0; i <= 200; i++) {
            readPwmVoltage += analogRead(PC1);
            delayMicroseconds(500);
          }
          float PwmVoltage = readPwmVoltage /= 200;
          float rrr = PwmVoltage;
          PwmVoltage /= 392.50443150164598632565206381362;
          tft.setTextSize(2);
          text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
          tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
          tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
          tft.setCursor(0, 230);
          tft.println(text);
        }
        while (1) {
          if (ExitToMenu == 0) Throttle();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            digitalWrite(SensorPulsePin, 0);
            digitalWrite(releSelf, 0);
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }

      //**********temp ***********
      //**********temp ***********
      if (MenuSelect == 4) {                               // 0 - 3.3v
        drawImage(50, 50, 175, 41, epd_bitmap_wirecheck);  // نمایش در مختصات (60,60)
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
          wirecheck();
          char key = getKey();  // خواندن کلید
          if (key != '\0') {
            if (key == '*') {
              break;
            }
            if (key == '#') {
              ExitToMenu = 1;
              break;
            }
          }
        }
        if (ExitToMenu == 0) {
          digitalWrite(buzzer, 1);
          delay(500);
          digitalWrite(buzzer, 0);
          tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
          drawImage(55, 100, 200, 100, epd_bitmap_sensorHelp);
          releSimulator();
          WaterVoltMode = 1;
          digitalWrite(SensorPulsePin, 1);
          digitalWrite(SimulatorLow, 1);
          digitalWrite(releSelf, 1);
          tft.setTextSize(2);
          tft.setCursor(50, 50);
          tft.setTextColor(ILI9488_WHITE);
          tft.println("Air Temperature");

          dutyCycle = 20;
          pwmFrequency = 2000;

          tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
          tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
          tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
          tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

          int pwmOut = map(dutyCycle, 1, 65, 11, 235);
          tft.fillRect(11, 260, 235, 30, ILI9488_BLACK);
          tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

          setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
          delay(50);
          //*****pwm Voltage*****
          float readPwmVoltage = 0;
          for (int i = 0; i <= 200; i++) {
            readPwmVoltage += analogRead(PC1);
            delayMicroseconds(500);
          }
          float PwmVoltage = readPwmVoltage /= 200;
          float rrr = PwmVoltage;
          PwmVoltage /= 392.50443150164598632565206381362;
          tft.setTextSize(2);
          text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
          tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
          tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
          tft.setCursor(0, 230);
          tft.println(text);
        }
        while (1) {
          if (ExitToMenu == 0) AirTemperature();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            digitalWrite(SensorPulsePin, 0);
            digitalWrite(releSelf, 0);
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }


      //**********oil ***********
      //**********oil ***********
      if (MenuSelect == 5) {                               // 0 - 3.3v
        drawImage(50, 50, 175, 41, epd_bitmap_wirecheck);  // نمایش در مختصات (60,60)
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
          wirecheck();
          char key = getKey();  // خواندن کلید
          if (key != '\0') {
            if (key == '*') {
              break;
            }
            if (key == '#') {
              ExitToMenu = 1;
              break;
            }
          }
        }
        if (ExitToMenu == 0) {
          digitalWrite(buzzer, 1);
          delay(500);
          digitalWrite(buzzer, 0);
          tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
          drawImage(55, 100, 200, 100, epd_bitmap_sensorHelp);
          releSimulator();
          WaterVoltMode = 1;
          digitalWrite(SensorPulsePin, 1);
          digitalWrite(SimulatorLow, 1);
          digitalWrite(releSelf, 1);
          tft.setTextSize(2);
          tft.setCursor(75, 50);
          tft.setTextColor(ILI9488_WHITE);
          tft.println("Oil Sensor");

          dutyCycle = 20;
          pwmFrequency = 2000;

          tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
          tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
          tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
          tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

          int pwmOut = map(dutyCycle, 1, 65, 11, 235);
          tft.fillRect(11, 260, 235, 30, ILI9488_BLACK);
          tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

          setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
          delay(50);
          //*****pwm Voltage*****
          float readPwmVoltage = 0;
          for (int i = 0; i <= 200; i++) {
            readPwmVoltage += analogRead(PC1);
            delayMicroseconds(500);
          }
          float PwmVoltage = readPwmVoltage /= 200;
          float rrr = PwmVoltage;
          PwmVoltage /= 392.50443150164598632565206381362;
          tft.setTextSize(2);
          text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
          tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
          tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
          tft.setCursor(0, 230);
          tft.println(text);
        }
        while (1) {
          if (ExitToMenu == 0) OilSensor();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            digitalWrite(SensorPulsePin, 0);
            digitalWrite(releSelf, 0);
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }

      //**********fuel  ***********
      //**********fuel  ***********
      if (MenuSelect == 6) {                               // 0 - 3.3v
        drawImage(50, 50, 175, 41, epd_bitmap_wirecheck);  // نمایش در مختصات (60,60)
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
          wirecheck();
          char key = getKey();  // خواندن کلید
          if (key != '\0') {
            if (key == '*') {
              break;
            }
            if (key == '#') {
              ExitToMenu = 1;
              break;
            }
          }
        }
        if (ExitToMenu == 0) {
          digitalWrite(buzzer, 1);
          delay(500);
          digitalWrite(buzzer, 0);
          tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
          drawImage(55, 100, 200, 100, epd_bitmap_sensorHelp);
          releSimulator();
          WaterVoltMode = 1;
          digitalWrite(SensorPulsePin, 1);
          digitalWrite(SimulatorLow, 1);
          digitalWrite(releSelf, 1);
          tft.setTextSize(2);
          tft.setCursor(70, 50);
          tft.setTextColor(ILI9488_WHITE);
          tft.println("Fuel Sensor");

          dutyCycle = 20;
          pwmFrequency = 2000;

          tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
          tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
          tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
          tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

          int pwmOut = map(dutyCycle, 1, 65, 11, 235);
          tft.fillRect(11, 260, 235, 30, ILI9488_BLACK);
          tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

          setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
          delay(50);
          //*****pwm Voltage*****
          float readPwmVoltage = 0;
          for (int i = 0; i <= 200; i++) {
            readPwmVoltage += analogRead(PC1);
            delayMicroseconds(500);
          }
          float PwmVoltage = readPwmVoltage /= 200;
          float rrr = PwmVoltage;
          PwmVoltage /= 392.50443150164598632565206381362;
          tft.setTextSize(2);
          text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
          tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
          tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
          tft.setCursor(0, 230);
          tft.println(text);
        }
        while (1) {
          if (ExitToMenu == 0) fuelSensor();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            digitalWrite(SensorPulsePin, 0);
            digitalWrite(releSelf, 0);
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }

      //**********cooler  ***********
      //**********cooler  ***********
      if (MenuSelect == 7) {                               // 0 - 3.3v
        drawImage(50, 50, 175, 41, epd_bitmap_wirecheck);  // نمایش در مختصات (60,60)
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
          wirecheck();
          char key = getKey();  // خواندن کلید
          if (key != '\0') {
            if (key == '*') {
              break;
            }
            if (key == '#') {
              ExitToMenu = 1;
              break;
            }
          }
        }
        if (ExitToMenu == 0) {
          digitalWrite(buzzer, 1);
          delay(500);
          digitalWrite(buzzer, 0);
          tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
          drawImage(55, 100, 200, 100, epd_bitmap_sensorHelp);
          releSimulator();
          WaterVoltMode = 1;
          digitalWrite(SensorPulsePin, 1);
          digitalWrite(SimulatorLow, 1);
          digitalWrite(releSelf, 1);
          tft.setTextSize(2);
          tft.setCursor(70, 50);
          tft.setTextColor(ILI9488_WHITE);
          tft.println("cooler Sensor");

          dutyCycle = 20;
          pwmFrequency = 2000;

          tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
          tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
          tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
          tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

          int pwmOut = map(dutyCycle, 1, 65, 11, 235);
          tft.fillRect(11, 260, 235, 30, ILI9488_BLACK);
          tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

          setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
          delay(50);
          //*****pwm Voltage*****
          float readPwmVoltage = 0;
          for (int i = 0; i <= 200; i++) {
            readPwmVoltage += analogRead(PC1);
            delayMicroseconds(500);
          }
          float PwmVoltage = readPwmVoltage /= 200;
          float rrr = PwmVoltage;
          PwmVoltage /= 392.50443150164598632565206381362;
          tft.setTextSize(2);
          text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
          tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
          tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
          tft.setCursor(0, 230);
          tft.println(text);
        }
        while (1) {
          if (ExitToMenu == 0) coolerSensor();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            digitalWrite(SensorPulsePin, 0);
            digitalWrite(releSelf, 0);
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }

      //**********map Sensor***********
      //**********map Sensor***********
      if (MenuSelect == 8) {                               // 0 - 3.3v
        drawImage(50, 50, 175, 41, epd_bitmap_wirecheck);  // نمایش در مختصات (60,60)
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
          wirecheck();
          char key = getKey();  // خواندن کلید
          if (key != '\0') {
            if (key == '*') {
              break;
            }
            if (key == '#') {
              ExitToMenu = 1;
              break;
            }
          }
        }
        if (ExitToMenu == 0) {
          digitalWrite(buzzer, 1);
          delay(500);
          digitalWrite(buzzer, 0);
          tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
          drawImage(55, 100, 200, 100, epd_bitmap_sensorHelp);
          releSimulator();
          WaterVoltMode = 1;
          digitalWrite(SensorPulsePin, 1);
          digitalWrite(SimulatorLow, 1);
          digitalWrite(releSelf, 1);
          tft.setTextSize(2);
          tft.setCursor(70, 50);
          tft.setTextColor(ILI9488_WHITE);
          tft.println("Map Sensor");

          dutyCycle = 20;
          pwmFrequency = 2000;

          tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
          tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
          tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
          tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

          int pwmOut = map(dutyCycle, 1, 65, 11, 235);
          tft.fillRect(11, 260, 235, 30, ILI9488_BLACK);
          tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

          setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
          delay(50);
          //*****pwm Voltage*****
          float readPwmVoltage = 0;
          for (int i = 0; i <= 200; i++) {
            readPwmVoltage += analogRead(PC1);
            delayMicroseconds(500);
          }
          float PwmVoltage = readPwmVoltage /= 200;
          float rrr = PwmVoltage;
          PwmVoltage /= 392.50443150164598632565206381362;
          tft.setTextSize(2);
          text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
          tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
          tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
          tft.setCursor(0, 230);
          tft.println(text);
        }
        while (1) {
          if (ExitToMenu == 0) mapSensor();
          if (ExitToMenu == 1) {
            ExitToMenu = 0;
            digitalWrite(SensorPulsePin, 0);
            digitalWrite(releSelf, 0);
            tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
            releAnalyzer();
            break;
          }
        }
      }


      // //**********Signal Generator***********
      // //**********Signal Generator***********
      // if (MenuSelect == 9) {
      //   releSimulator();
      //   digitalWrite(SensorPulsePin, 1);
      //   digitalWrite(SimulatorLow, 1);
      //   tft.setTextSize(2);
      //   tft.setCursor(17, 50);
      //   tft.setTextColor(ILI9488_WHITE);
      //   tft.println("Square Signal Generator");

      //   dutyCycle = 2;
      //   pwmFrequency = 2000;

      //   tft.setTextSize(2);
      //   text = "Frequency:" + String(pwmFrequency) + " HZ";
      //   tft.setTextColor(ILI9488_RED);
      //   tft.fillRect(0, 100, 270, 20, ILI9488_BLACK);
      //   tft.setCursor(0, 100);
      //   tft.println(text);

      //   text = "Duty:" + String(dutyCycle) + " %";
      //   tft.setTextColor(ILI9488_CYAN);  //ILI9488_MAGENTA
      //   tft.fillRect(0, 130, 250, 20, ILI9488_BLACK);
      //   tft.setCursor(0, 130);
      //   tft.println(text);

      //   tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
      //   tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
      //   tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
      //   tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

      //   int pwmOut = map(dutyCycle, 1, 99, 50, 237);
      //   tft.fillRect(11, 260, 237, 30, ILI9488_BLACK);
      //   tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

      //   setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
      //   delay(50);
      //   //*****pwm Voltage*****
      //   float readPwmVoltage = 0;
      //   for (int i = 0; i <= 200; i++) {
      //     readPwmVoltage += analogRead(PC1);
      //     delayMicroseconds(500);
      //   }
      //   float PwmVoltage = readPwmVoltage /= 200;
      //   float rrr = PwmVoltage;
      //   PwmVoltage /= 392.50443150164598632565206381362;
      //   tft.setTextSize(2);
      //   text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
      //   tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
      //   tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
      //   tft.setCursor(0, 230);
      //   tft.println(text);

      //   //**************low Voltage Mode****************
      //   if (simaulatorMode == 1) {
      //     tft.setTextSize(1);
      //     tft.fillRect(0, 180, 300, 20, ILI9488_BLACK);
      //     tft.setCursor(0, 180);
      //     tft.setTextColor(ILI9488_GREEN);
      //     tft.println("LOW VOLTAGE Mode: 3.3v");
      //     digitalWrite(SimulatorLow, 1);
      //   }
      //   if (simaulatorMode == 0) {
      //     tft.setTextSize(1);
      //     tft.fillRect(0, 180, 300, 20, ILI9488_BLACK);
      //     tft.setCursor(0, 180);
      //     tft.setTextColor(ILI9488_GREEN);
      //     tft.println("Hight VOLTAGE Mode: 5V");
      //     digitalWrite(SimulatorLow, 0);
      //   }

      //   ////////////////////pulse100///////////////////////
      //   plus100 = 2;
      //   if (plus100 == 1) {
      //     tft.setTextSize(1);
      //     tft.fillRect(0, 200, 150, 20, ILI9488_BLACK);
      //     tft.setCursor(0, 200);
      //     tft.setTextColor(ILI9488_GREEN);
      //     tft.println("Pulse Count:+0.1");
      //   }
      //   if (plus100 == 2) {
      //     tft.setTextSize(1);
      //     tft.fillRect(0, 200, 150, 20, ILI9488_BLACK);
      //     tft.setCursor(0, 200);
      //     tft.setTextColor(ILI9488_GREEN);
      //     tft.println("Pulse Count:+1");
      //   }
      //   if (plus100 == 3) {
      //     tft.setTextSize(1);
      //     tft.fillRect(0, 200, 150, 20, ILI9488_BLACK);
      //     tft.setCursor(0, 200);
      //     tft.setTextColor(ILI9488_GREEN);
      //     tft.println("Pulse Count:+5");
      //   }


      //   while (1) {
      //     SimulationManual();
      //     if (ExitToMenu == 1) {
      //       ExitToMenu = 0;
      //       tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
      //       releAnalyzer();
      //       break;
      //     }
      //   }
      // }
      ///////////main menu2
    }
  }
  if (mainMenu == 1) KeyPad1();
  if (mainMenu == 2) KeyPad2();
}



//*******************************************************************************menu Select*****************************************************************************
//*******************************************************************************menu Select*****************************************************************************
//*******************************************************************************menu Select*****************************************************************************
//*******************************************************************************menu Select*****************************************************************************
//*******************************************************************************menu Select*****************************************************************************
void KeyPad1() {
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
        tft.setCursor(5, 29);
        tft.setTextColor(ILI9488_RED);
        tft.println("MUTE");
      }
      if (mute == 0) {
        tft.fillRect(5, 29, 50, 7, ILI9488_BLACK);
      }
      delay(100);
    }

    if (key == 'A') {
      digitalWrite(buzzer, 1);
      delay(200);
      digitalWrite(buzzer, 0);
      mainMenu++;
      mainMenuChange = 1;
      MenuSelect = 1;
    }

    // if (key == 'B') {
    //   digitalWrite(buzzer, 1);
    //   delay(200);
    //   digitalWrite(buzzer, 0);
    //   mainMenu--;
    //   mainMenuChange = 1;
    // }

    if (mainMenu < 1) mainMenu = 1;

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

    if (key == '0') {
      digitalWrite(buzzer, 1);
      delay(500);
      digitalWrite(buzzer, 0);
      float readPwmVoltage = 0;
      for (int i = 0; i <= 200; i++) {
        readPwmVoltage += analogRead(PC2);
        delayMicroseconds(500);
      }
      readPwmVoltage /= 200;
      readPwmVoltage /= 106.6666666666666666666;
      Serial1.println(readPwmVoltage);

      if (readPwmVoltage >= 11.5) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery1);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage >= 11 && readPwmVoltage < 11.5) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery2);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage >= 10.5 && readPwmVoltage < 11) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery3);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage >= 10 && readPwmVoltage < 10.5) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery4);  // نمایش در مختصات (60,60)
      }

      if (readPwmVoltage < 10) {
        drawImage(0, 0, 41, 30, epd_bitmap_battery5);  // نمایش در مختصات (60,60)
      }
    }

    //******************EEprom***************
    if (key == 'D') {
      ++eepromReset;
      digitalWrite(buzzer, 1);
      delay(1000);
      digitalWrite(buzzer, 0);
      Serial1.print("calibrate:");
      Serial1.println(eepromReset);
    }

    if (key == '#') {
      if (eepromReset >= 5) {
        eepromReset = 0;
        digitalWrite(buzzer, 1);
        delay(100);
        digitalWrite(buzzer, 0);
        delay(100);
        digitalWrite(buzzer, 1);
        delay(100);
        digitalWrite(buzzer, 0);
        delay(100);
        digitalWrite(buzzer, 1);
        delay(100);
        digitalWrite(buzzer, 0);
        delay(100);
        tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
        tft.setTextSize(3);
        tft.setTextColor(ILI9488_CYAN);
        text = "Claibration";
        tft.setCursor(0, 100);
        tft.println(text);
        delay(3000);
        tft.fillRect(0, 50, 300, 320, ILI9488_BLACK);
        eepromfirst();
        readEEprom();
      }
    }
    delay(250);
  }
}

/////////////////////////////////////////////////MENU2//////////////////////////////////////////////
/////////////////////////////////////////////////MENU2//////////////////////////////////////////////
/////////////////////////////////////////////////MENU2//////////////////////////////////////////////
void KeyPad2() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    BuzzerBIGbig();
    if ((key == '1') || (key == '2') || (key == '3') || (key == '4') || (key == '5') || (key == '6') || (key == '7') || (key == '8')) {
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
        tft.setCursor(5, 29);
        tft.setTextColor(ILI9488_RED);
        tft.println("MUTE");
      }
      if (mute == 0) {
        tft.fillRect(5, 29, 50, 7, ILI9488_BLACK);
      }
      delay(100);
    }

    // if (key == 'A') {
    //   digitalWrite(buzzer, 1);
    //   delay(200);
    //   digitalWrite(buzzer, 0);
    //   // mainMenu++;
    //   // mainMenuChange = 1;
    // }

    if (key == 'B') {
      digitalWrite(buzzer, 1);
      delay(200);
      digitalWrite(buzzer, 0);
      mainMenu--;
      mainMenuChange = 1;
      MenuSelect = 1;
    }

    if (mainMenu > 2) mainMenu = 2;

    if (key == '*') {
      changeMenu = 1;
    }

    if (key == '1') {
      tft.setTextSize(2);
      tft.setCursor(452, 88);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 1;
    }
    if (key == '2') {
      tft.setTextSize(2);
      tft.setCursor(452, 116);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 2;
    }
    if (key == '3') {
      tft.setTextSize(2);
      tft.setCursor(452, 145);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 3;
    }
    if (key == '4') {
      tft.setTextSize(2);
      tft.setCursor(452, 174);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 4;
    }

    if (key == '5') {
      tft.setTextSize(2);
      tft.setCursor(452, 204);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 5;
    }

    if (key == '6') {
      tft.setTextSize(2);
      tft.setCursor(452, 234);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 6;
    }
    if (key == '7') {
      tft.setTextSize(2);
      tft.setCursor(452, 262);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 7;
    }
    if (key == '8') {
      tft.setTextSize(2);
      tft.setCursor(452, 290);  //58 //88
      tft.setTextColor(ILI9488_GREEN);
      tft.println("<-");
      MenuSelect = 8;
    }

    // if (key == '9') {
    //   // tft.setTextSize(2);
    //   // tft.setCursor(452, 290);  //58 //88
    //   // tft.setTextColor(ILI9488_GREEN);
    //   // tft.println("<-");
    //   MenuSelect = 9;
    // }
    delay(250);
  }
}