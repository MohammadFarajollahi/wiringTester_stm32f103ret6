

void WaterSensor() {
  if (WaterVoltMode == 1) {
    float readPwmVoltage = 0;
    for (int i = 0; i <= 200; i++) {
      readPwmVoltage += analogRead(PC1);
      delayMicroseconds(500);
    }
    float PwmVoltage = readPwmVoltage /= 200;
    float rrr = PwmVoltage;
    PwmVoltage /= 392.50443150164598632565206381362;
    ////namayesh
    tft.setTextSize(2);
    text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
    tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
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

    //***********Duty Setting************
    if (key == '6') {
      BuzzerBIGbig();
      dutyCycle += .5;
      if (dutyCycle < .1) dutyCycle = .1;
      if (dutyCycle >= 65) dutyCycle = 65;
      delay(20);
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    if (key == '4') {
      BuzzerBIGbig();
      dutyCycle -= .5;
      if (dutyCycle < .1) dutyCycle = .1;
      if (dutyCycle >= 65) dutyCycle = 65;
      delay(20);
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
    tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
    tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
    tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

    int pwmOut = map(dutyCycle, 1, 65, 11, 235); 
    tft.fillRect(11, 260, 235, 30, ILI9488_BLACK);
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
    text = "Voltage:" + String(PwmVoltage, 2) + " V";  //  adc:" + String(rrr);  //
    tft.setTextColor(ILI9488_YELLOW);                  //ILI9488_MAGENTA
    tft.fillRect(0, 230, 300, 20, ILI9488_BLACK);
    tft.setCursor(0, 230);
    tft.println(text);

    if (key == 'A') {
      Serial1.print("duty:");
      Serial1.println(dutyCycle);
      Serial1.print("cursur:");
      Serial1.println(pwmOut);
    }
  }
}