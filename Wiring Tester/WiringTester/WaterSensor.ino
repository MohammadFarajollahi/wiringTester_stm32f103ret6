

void WaterSensor() {
  if (WaterVoltMode == 1) {
    float readPwmVoltage = 0;
    for (int i = 0; i <= 100; i++) {
      readPwmVoltage += analogRead(PC1);
      delayMicroseconds(500);
    }
    float PwmVoltage = readPwmVoltage /= 100;
    float rrr = PwmVoltage;
    PwmVoltage /= 392.50443150164598632565206381362;
    ////namayesh
    tft.setTextSize(2);
    text = "Voltage:" + String(PwmVoltage, 2) + " V Du:" + String(dutyCycle);  //  adc:" + String(rrr);  //
    tft.setTextColor(ILI9488_YELLOW);                                          //ILI9488_MAGENTA
    tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
    tft.setCursor(0, 230);
    tft.println(text);
    ////////
    if (PwmVoltage >= 12) {
      releAnalyzer();
      text = "Probe Warning";
      tft.setTextColor(ILI9488_RED);
      tft.fillRect(0, 150, 160, 20, ILI9488_BLACK);
      tft.setCursor(0, 150);
      tft.println(text);
      for (int i = 0; i <= 20; i++) {
        digitalWrite(buzzer, !digitalRead(buzzer));
        delay(20);
      }
      delay(200);
      digitalWrite(buzzer, 0);
    }
  }
  WaterKey();
}

void WaterKey() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    if (key == '#') {
      ExitToMenu = 1;
      BuzzerBIGbig();
    }

    if (key == '1') {
      BuzzerBIGbig();
      tft.setTextSize(2);
      tft.fillRect(0, 130, 300, 20, ILI9488_BLACK);
      tft.setCursor(0, 130);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("Vlotage Mode");
      releSimulator();
      delay(500);
      WaterVoltMode = 1;
      dutyCycle = 2;
      plus100 = 2;
    }

    if (key == '2') {
      BuzzerBIGbig();
      dutyCycle = 81;
      plus100 = 1;
      tft.setTextSize(2);
      tft.fillRect(0, 130, 300, 20, ILI9488_BLACK);
      tft.setCursor(0, 130);
      tft.setTextColor(ILI9488_CYAN);
      tft.println("RES Mode");
      ReleWater();
      delay(500);
      WaterVoltMode = 0;
      pwmFrequency = 2000;
    }

    //////////////pulse1000/////////
    if (key == 'B') {
      BuzzerSet();
      plus100 += 1;
      if (plus100 >= 4) plus100 = 1;
      if (plus100 == 1) {
        tft.setTextSize(1);
        tft.fillRect(0, 70, 150, 20, ILI9488_BLACK);
        tft.setCursor(0, 70);
        tft.setTextColor(ILI9488_GREEN);
        tft.println("Pulse Count:+0.1");
      }
      if (plus100 == 2) {
        tft.setTextSize(1);
        tft.fillRect(0, 70, 150, 20, ILI9488_BLACK);
        tft.setCursor(0, 70);
        tft.setTextColor(ILI9488_GREEN);
        tft.println("Pulse Count:+1");
      }
      if (plus100 == 3) {
        tft.setTextSize(1);
        tft.fillRect(0, 70, 150, 20, ILI9488_BLACK);
        tft.setCursor(0, 70);
        tft.setTextColor(ILI9488_GREEN);
        tft.println("Pulse Count:+5");
      }
    }

    ///////////////////////**********************************Volt Mode*********************************************///////////////////////
    ///////////////////////**********************************Volt Mode*********************************************///////////////////////
    ///////////////////////**********************************Volt Mode*********************************************///////////////////////
    if (WaterVoltMode == 1) {
      //***********Frequency Setting************
      if (key == '9') {
        BuzzerBIGbig();
        if (plus100 == 1) pwmFrequency += 1;
        if (plus100 == 2) pwmFrequency += 10;
        if (plus100 == 3) pwmFrequency += 100;
        if (pwmFrequency <= 1) pwmFrequency = 1;
        setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
      }

      if (key == '7') {
        BuzzerBIGbig();
        if (plus100 == 1) pwmFrequency -= 1;
        if (plus100 == 2) pwmFrequency -= 10;
        if (plus100 == 3) pwmFrequency -= 100;

        if (pwmFrequency <= 1) pwmFrequency = 1;
        setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
      }
      //***********Duty Setting************
      if (key == '6') {
        BuzzerBIGbig();
        if (plus100 == 1) dutyCycle += 0.1;
        if (plus100 == 2) dutyCycle += 1;
        if (plus100 == 3) dutyCycle += 5;
        if (dutyCycle < .1) dutyCycle = .1;
        if (dutyCycle >= 99) dutyCycle = 99;
        delay(10);
        setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
      }

      if (key == '4') {
        BuzzerBIGbig();
        if (plus100 == 1) dutyCycle -= 0.1;
        if (plus100 == 2) dutyCycle -= 1;
        if (plus100 == 3) dutyCycle -= 5;
        if (dutyCycle < .1) dutyCycle = .1;
        if (dutyCycle >= 99) dutyCycle = 99;
        delay(10);
        setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
      }

      tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
      tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
      tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
      tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

      int pwmOut = map(dutyCycle, 1, 99, 50, 197);
      tft.fillRect(11, 260, 197, 30, ILI9488_BLACK);
      tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

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
      text = "Voltage:" + String(PwmVoltage, 2) + " V Du:" + String(dutyCycle);  //  adc:" + String(rrr);  //
      tft.setTextColor(ILI9488_YELLOW);                                          //ILI9488_MAGENTA
      tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
      tft.setCursor(0, 230);
      tft.println(text);
    }
    ///////////////////////**********************************Res Mode*********************************************///////////////////////
    ///////////////////////**********************************Res Mode*********************************************///////////////////////
    ///////////////////////**********************************Res Mode*********************************************///////////////////////
    if (WaterVoltMode == 0) {
      //***********Frequency Setting************
      if (key == '9') {
        BuzzerBIGbig();
        if (plus100 == 1) pwmFrequency += 100;
        if (plus100 == 2) pwmFrequency += 10;
        if (plus100 == 3) pwmFrequency += 100;
        if (pwmFrequency <= 100) pwmFrequency = 1;
        setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);
        delay(100);
      }

      if (key == '7') {
        BuzzerBIGbig();
        if (plus100 == 1) pwmFrequency -= 100;
        if (plus100 == 2) pwmFrequency -= 10;
        if (plus100 == 3) pwmFrequency -= 100;
        if (pwmFrequency <= 100) pwmFrequency = 1;
        setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);
        delay(100);
      }
      //***********Duty Setting************
      if (key == '6') {
        BuzzerBIGbig();
        if (plus100 == 1) dutyCycle += 0.1;
        if (plus100 == 2) dutyCycle += 1;
        if (plus100 == 3) dutyCycle += 5;
        if (dutyCycle < 0) dutyCycle = 1;
        if (dutyCycle >= 99) dutyCycle = 99;
        delay(10);
        setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);
      }

      if (key == '4') {
        BuzzerBIGbig();
        if (plus100 == 1) dutyCycle -= 0.1;
        if (plus100 == 2) dutyCycle -= 1;
        if (plus100 == 3) dutyCycle -= 5;
        if (dutyCycle < 0) dutyCycle = 1;
        if (dutyCycle >= 99) dutyCycle = 99;
        delay(10);
        setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);
      }

      tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
      tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
      tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
      tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

      int pwmOut = map(dutyCycle, 1, 99, 50, 197);
      tft.fillRect(11, 260, 197, 30, ILI9488_BLACK);
      tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

      tft.setTextSize(2);
      text = "Duty:" + String(dutyCycle, 2) + "% Fr:" + String(pwmFrequency);  //  adc:" + String(rrr);  //
      tft.setTextColor(ILI9488_YELLOW);                                        //ILI9488_MAGENTA
      tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
      tft.setCursor(0, 230);
      tft.println(text);
    }
  }
}