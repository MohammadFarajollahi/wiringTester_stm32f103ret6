

void menu() {

  if (mainMenu == 1) {
    if (changeMenu == 1) {
      changeMenu = 0;
      tft.setTextSize(2);
      tft.setCursor(330, 125);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("*Main Menu*");
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("1:Logic Analyzer");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("2:Volt meter");
      tft.println("3:Ampere meter");
      tft.println("4:Ohm meter");
      tft.println("5:Thermometer");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      // tft.setCursor(330, 125);
      // tft.println("D:Next menu");

      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
      if (mute == 1) {
        digitalWrite(buzzer, 0);
        tft.setCursor(400, 0);
        tft.setTextColor(ILI9488_RED);
        tft.println("MUTE");
      }
      if (mute == 0) {
        tft.fillRect(400, 0, 100, 20, ILI9488_BLACK);
      }
    }

    ReadMainKeypad();
  }

  //**********Logic Analyzer***********
  if (MenuSelect == 1) {
    if (MenuSelectChange == 1) {
      digitalWrite(SensorPulsePin, 0);
      releAnalyzer();
      tft.setTextSize(2);
      MenuSelectChange = 0;
      //logic
      tft.setCursor(170, 160);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("Logic Analyzer");
      //circle
      tft.fillCircle(70, 270, 20, ILI9488_WHITE);
      tft.fillCircle(180, 270, 20, ILI9488_WHITE);
      tft.fillCircle(300, 270, 20, ILI9488_WHITE);
      tft.fillCircle(410, 270, 20, ILI9488_WHITE);
      //logicName
      tft.setCursor(52, 300);
      tft.setTextColor(ILI9488_BLUE);
      tft.println("GND");
      tft.setCursor(160, 300);
      tft.setTextColor(ILI9488_RED);
      tft.println("+12");
      tft.setCursor(245, 300);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("SIGNSAL+5V");
      tft.setCursor(380, 300);
      tft.setTextColor(ILI9488_YELLOW);
      tft.println("SENSOR");

      if (mute == 1) {
        digitalWrite(buzzer, 0);
        tft.setCursor(400, 0);
        tft.setTextColor(ILI9488_RED);
        tft.println("MUTE");
      }
      if (mute == 0) {
        tft.fillRect(400, 0, 100, 20, ILI9488_BLACK);
      }
    }
    logicAnalyze();
  }

  //**********Voltmeter***********
  if (MenuSelect == 2) {
    if (MenuSelectChange == 1) {
      releAnalyzer();
      MenuSelectChange = 0;
      //logic
      tft.setCursor(170, 160);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("Volt Meter");
    }
    VoltMEter();
  }

  //**********Ampermeter***********
  if (MenuSelect == 3) {
    if (MenuSelectChange == 1) {
      releCurrent();
      MenuSelectChange = 0;
      //logic
      tft.setCursor(170, 160);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("Ampere Meter");
      tft.setTextSize(2);
      if (DCMode == 1) {
        tft.fillRect(370, 20, 150, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(370, 20);
        tft.setTextColor(ILI9488_RED);
        tft.println("Dc Mode");
        float sum = 0;
        for (int i = 0; i < 200; i++) {
          sum += analogRead(ACS712_PIN);
          delay(1);
        }
        offset = (sum / 200.0) * VREF / 4095.0;  // میانگین‌گیری برای حذف نویز
      }
      if (DCMode == 0) {
        tft.fillRect(370, 20, 150, 20, ILI9488_BLACK);
        tft.setCursor(370, 20);
        tft.setTextColor(ILI9488_RED);
        tft.println("AC Mode");
        offsetVoltage = calibrateOffset();  // محاسبه آفست اولیه سنسور
      }
    }
    AmpereMeter();
  }

  //**********Voltmeter***********
  if (MenuSelect == 4) {
    if (MenuSelectChange == 1) {
      releAnalyzer();
      MenuSelectChange = 0;
      //logic
      tft.setCursor(170, 160);
      tft.setTextColor(ILI9488_WHITE);
      tft.println(" Ohm Meter ");
    }
    OhmMeter();
  }

  //**********Voltmeter***********
  if (MenuSelect == 5) {
    if (MenuSelectChange == 1) {
      releAnalyzer();
      MenuSelectChange = 0;
      //logic
      tft.setCursor(170, 160);
      tft.setTextColor(ILI9488_WHITE);
      tft.println(" Thermometer ");

      text = "Press *";
      tft.setTextSize(5);
      tft.setTextColor(ILI9488_YELLOW);
      tft.fillRect(50, 240, 500, 40, ILI9488_BLACK);
      tft.setCursor(50, 240);
      tft.println(text);
    }
    Thermometer();
  }

  //**********FrequencyMeter***********
  if (MenuSelect == 6) {
    if (MenuSelectChange == 1) {
      releFrequency();
      MenuSelectChange = 0;
      //logic
      tft.setTextSize(2);
      tft.setCursor(165, 160);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("Frequency Meter");
    }
    FrequencyMeter();
  }

  //**********Oskop***********
  if (MenuSelect == 7) {
    if (MenuSelectChange == 1) {
      tft.fillScreen(ILI9488_BLACK);
      releAnalyzer();
      MenuSelectChange = 0;
      //logic
      drawGrid();
      OutOskop = 0;
      tft.setTextSize(1);
      tft.setCursor(1, 1);
      tft.setTextColor(ILI9488_RED);
      tft.println("Oscilloscope");
      tft.setCursor(1, 20);
      tft.setTextColor(ILI9488_CYAN);
      tft.println("* -> Exit");
      tft.setCursor(200, 1);
      tft.println("1 & 2 -> Time/DIV");
      tft.setCursor(320, 1);
      tft.println("A & B -> THreshold");
      tft.setCursor(200, 20);
      tft.println("C & D -> VoltSale");
      tft.setCursor(320, 20);
      tft.println("# -> Pause");
    }
    OskoP();
  }


  //**********Generator***********
  if (MenuSelect == 8) {
    if (MenuSelectChange == 1) {
      releGenerator();
      MenuSelectChange = 0;
      dutyCycle = 10;
      pwmFrequency = 200;
      //logic
      tft.setTextSize(2);
      tft.setCursor(180, 160);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("Generator");
      plus100 = 1;

      if (plus100 == 1) {
        tft.fillRect(370, 20, 150, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(370, 20);
        tft.setTextColor(ILI9488_RED);
        tft.println("+100");
      }
      if (plus100 == 0) {
        tft.fillRect(370, 20, 150, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(370, 20);
        tft.setTextColor(ILI9488_RED);
        tft.println("+1");
      }

      tft.setTextSize(2);
      text = "Frequency:" + String(pwmFrequency) + " HZ";
      tft.setTextColor(ILI9488_RED);
      tft.fillRect(0, 250, 270, 20, ILI9488_BLACK);
      tft.setCursor(0, 250);
      tft.println(text);

      text = "Duty:" + String(dutyCycle) + " %";
      tft.setTextColor(ILI9488_CYAN);  //ILI9488_MAGENTA
      tft.fillRect(300, 250, 250, 20, ILI9488_BLACK);
      tft.setCursor(300, 250);
      tft.println(text);

      setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);
    }
    Generator();
  }


  //**********simaltor***********
  if (MenuSelect == 9) {
    if (MenuSelectChange == 1) {
      digitalWrite(SensorPulsePin, 1);
      releSimulator();
      MenuSelectChange = 0;
      //Sensor Simulator
      tft.setTextSize(2);
      tft.setCursor(160, 160);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("Sensor Simulator");
      dutyCycle = 2;
      pwmFrequency = 2000;
      tft.drawLine(49, 259, 423, 259, ILI9488_WHITE);
      tft.drawLine(49, 259, 49, 290, ILI9488_WHITE);
      tft.drawLine(49, 290, 423, 290, ILI9488_WHITE);
      tft.drawLine(423, 259, 423, 290, ILI9488_WHITE);

      tft.setTextSize(2);
      text = "Frequency:" + String(pwmFrequency) + " HZ";
      tft.setTextColor(ILI9488_RED);
      tft.fillRect(0, 190, 270, 20, ILI9488_BLACK);
      tft.setCursor(0, 190);
      tft.println(text);

      text = "Duty:" + String(dutyCycle) + " %";
      tft.setTextColor(ILI9488_CYAN);  //ILI9488_MAGENTA
      tft.fillRect(300, 190, 250, 20, ILI9488_BLACK);
      tft.setCursor(300, 190);
      tft.println(text);

      int pwmOut = map(dutyCycle, 1, 99, 50, 370);
      tft.fillRect(50, 260, 370, 30, ILI9488_BLACK);
      tft.fillRect(50, 260, pwmOut, 30, ILI9488_GREEN);

      if (simaulatorMode == 1) {
        tft.setTextSize(1);
        tft.fillRect(410, 40, 250, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(410, 40);
        tft.setTextColor(ILI9488_RED);
        tft.println("LOW Mode");
        digitalWrite(SimulatorLow, 1);
      }
      if (simaulatorMode == 0) {
        tft.setTextSize(1);
        tft.fillRect(410, 40, 250, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(410, 40);
        tft.setTextColor(ILI9488_RED);
        tft.println("Hight Mode");
        digitalWrite(SimulatorLow, 0);
      }
      plus100 = 2;
      if (plus100 == 1) {
        tft.setTextSize(2);
        tft.fillRect(400, 20, 150, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(400, 20);
        tft.setTextColor(ILI9488_RED);
        tft.println("+0.1");
      }
      if (plus100 == 2) {
        tft.setTextSize(2);
        tft.fillRect(400, 20, 150, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(400, 20);
        tft.setTextColor(ILI9488_RED);
        tft.println("+1");
      }
      if (plus100 == 3) {
        tft.setTextSize(2);
        tft.fillRect(400, 20, 150, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(400, 20);
        tft.setTextColor(ILI9488_RED);
        tft.println("+5");
      }

      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
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
      tft.fillRect(0, 230, 400, 20, ILI9488_BLACK);
      tft.setCursor(0, 230);
      tft.println(text);
    }
    simulator();
  }
}



//**********************************************menu Select********************************************
//**********************************************menu Select********************************************
//**********************************************menu Select********************************************
void ReadMainKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {


    //بلندگو خاموش
    if (key == '#') {
      digitalWrite(buzzer, 1);
      delay(200);
      digitalWrite(buzzer, 0);
      mute ^= 1;
      Serial1.println(mute);
      if (mute == 1) {
        tft.setTextSize(2);
        digitalWrite(buzzer, 0);
        tft.setCursor(400, 0);
        tft.setTextColor(ILI9488_RED);
        tft.println("MUTE");
      }
      if (mute == 0) {
        tft.fillRect(400, 0, 100, 20, ILI9488_BLACK);
      }
      delay(100);
    }
    //***********Logic************
    if (key == '1') {
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 1;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(330, 125);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("*Main Menu*");
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("1:Logic Analyzer");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("2:Volt meter");
      tft.println("3:Ampere meter");
      tft.println("4:Ohm meter");
      tft.println("5:Thermometer");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      // tft.setCursor(330, 125);
      // tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }
    //***********voltmeter************
    if (key == '2') {
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 2;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(330, 125);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("*Main Menu*");
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("1:Logic Analyzer");
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("2:Volt meter");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("3:Ampere meter");
      tft.println("4:Ohm meter");
      tft.println("5:Thermometer");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      // tft.setCursor(330, 125);
      // tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }

    //***********Ampermeter************
    if (key == '3') {
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 3;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(330, 125);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("*Main Menu*");
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("1:Logic Analyzer");
      tft.println("2:Volt meter");
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("3:Ampere meter");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("4:Ohm meter");
      tft.println("5:Thermometer");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      // tft.setCursor(330, 125);
      // tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }

    //***********Ohmeter************
    if (key == '4') {
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 4;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(330, 125);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("*Main Menu*");
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("1:Logic Analyzer");
      tft.println("2:Volt meter");
      tft.println("3:Ampere meter");
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("4:Ohm meter");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("5:Thermometer");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      // tft.setCursor(330, 125);
      // tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }

    //***********Thermometer************
    if (key == '5') {
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 5;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(330, 125);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("*Main Menu*");
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("1:Logic Analyzer");
      tft.println("2:Volt meter");
      tft.println("3:Ampere meter");
      tft.println("4:Ohm meter");
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("5:Thermometer");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      // tft.setCursor(330, 125);
      // tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }

    //**********frequency meter************
    if (key == '6') {
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 6;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(330, 125);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("*Main Menu*");
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("1:Logic Analyzer");
      tft.println("2:Volt meter");
      tft.println("3:Ampere meter");
      tft.println("4:Ohm meter");
      tft.println("5:Thermometer");
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("6:Frequency Meter");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      // tft.setCursor(330, 125);
      // tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }

    //***********Oskop************
    if (key == '7') {
      mute = 0;
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 7;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
    }

    //**********generator************
    if (key == '8') {
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 8;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(330, 125);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("*Main Menu*");
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("1:Logic Analyzer");
      tft.println("2:Volt meter");
      tft.println("3:Ampere meter");
      tft.println("4:Ohm meter");
      tft.println("5:Thermometer");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("8:Signal Generator");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("9:Sensor Simulator");
      // tft.setCursor(330, 125);
      // tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }


    //**********generator************
    if (key == '9') {
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 9;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(330, 125);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("*Main Menu*");
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("1:Logic Analyzer");
      tft.println("2:Volt meter");
      tft.println("3:Ampere meter");
      tft.println("4:Ohm meter");
      tft.println("5:Thermometer");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("9:Sensor Simulator");
      // tft.setCursor(330, 125);
      // tft.setTextColor(ILI9488_WHITE);
      // tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }
    if (mute == 1) {
      tft.setTextSize(2);
      digitalWrite(buzzer, 0);
      tft.setCursor(400, 0);
      tft.setTextColor(ILI9488_RED);
      tft.println("MUTE");
    }
    if (mute == 0) {
      tft.fillRect(400, 0, 100, 20, ILI9488_BLACK);
    }
  }
}