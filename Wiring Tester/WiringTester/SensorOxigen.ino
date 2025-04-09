

void SensorOxigen() {
  float readPwmVoltage = 0;
  for (int i = 0; i <= 100; i++) {
    readPwmVoltage += analogRead(PC1);
    delayMicroseconds(500);
  }
  float PwmVoltage = readPwmVoltage /= 100;
  float rrr = PwmVoltage;
  PwmVoltage /= 392.50443150164598632565206381362;
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
    // digitalWrite(buzzer, 1);
    // delay(10);
    digitalWrite(buzzer, 0);
  }

  OxigenKey();
}

void OxigenKey() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    if (key == '#') {
      ExitToMenu = 1;
      BuzzerBIGbig();
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

    //***********Duty Setting************
    if (key == '6') {
      BuzzerBIGbig();
      if (plus100 == 1) dutyCycle += 0.1;
      if (plus100 == 2) dutyCycle += 1;
      if (plus100 == 3) dutyCycle += 5;
      if (dutyCycle < 0) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;
      delay(5);
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    if (key == '4') {
      BuzzerBIGbig();
      if (plus100 == 1) dutyCycle -= 0.1;
      if (plus100 == 2) dutyCycle -= 1;
      if (plus100 == 3) dutyCycle -= 5;
      if (dutyCycle < 0) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;
      delay(5);
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
    tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
    tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
    tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

    int pwmOut = map(dutyCycle, 1, 99, 50, 197);
    tft.fillRect(11, 260, 197, 30, ILI9488_BLACK);
    tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);

    setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    delay(10);
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
}