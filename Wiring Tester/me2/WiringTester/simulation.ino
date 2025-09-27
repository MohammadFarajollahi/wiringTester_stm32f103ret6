


void simulator() {
  simulateKeypad();

  float readPwmVoltage = 0;
  for (int i = 0; i <= 100; i++) {
    readPwmVoltage += analogRead(PC1);
    delayMicroseconds(500);
  }
  float PwmVoltage = readPwmVoltage /= 100;
  float rrr = PwmVoltage;
  PwmVoltage /= 392.50443150164598632565206381362;
  if (PwmVoltage >= 5) {
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
}


void simulateKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {

    //***********Frequency Setting************
    if (key == 'A') {
      BuzzerBIGbig();
      if (plus100 == 1) pwmFrequency += 1;
      if (plus100 == 2) pwmFrequency += 10;
      if (plus100 == 3) pwmFrequency += 100;
      if (pwmFrequency <= 1) pwmFrequency = 1;
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    if (key == 'B') {
      BuzzerBIGbig();
      if (plus100 == 1) pwmFrequency -= 1;
      if (plus100 == 2) pwmFrequency -= 10;
      if (plus100 == 3) pwmFrequency -= 100;

      if (pwmFrequency <= 1) pwmFrequency = 1;
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    //***********Duty Setting************
    if (key == 'C') {
      BuzzerBIGbig();
      if (plus100 == 1) dutyCycle += 0.1;
      if (plus100 == 2) dutyCycle += 1;
      if (plus100 == 3) dutyCycle += 5;
      if (dutyCycle < 0) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;
      delay(10);
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    if (key == 'D') {
      BuzzerBIGbig();
      if (plus100 == 1) dutyCycle -= 0.1;
      if (plus100 == 2) dutyCycle -= 1;
      if (plus100 == 3) dutyCycle -= 5;
      if (dutyCycle < 0) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;
      delay(10);
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    //*****************LOW Mode*****************
    if (key == '*') {
      BuzzerSet();
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
      simaulatorMode ^= 1;
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
    }

    //****************Pulse100 Mode**************
    if (key == '0') {
      BuzzerSet();
      plus100 += 1;
      if (plus100 >= 4) plus100 = 1;
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
    }
    delay(10);

    //*********************lcd Show*********************
    //*********************lcd Show*********************
    //*********************lcd Show*********************
    tft.setTextSize(2);
    text = "Frequency:" + String(pwmFrequency) + " HZ";
    tft.setTextColor(ILI9488_RED);
    tft.fillRect(0, 190, 270, 20, ILI9488_BLACK);
    tft.setCursor(0, 190);
    tft.println(text);

    text = "Duty:" + String(dutyCycle, 1) + " %";
    tft.setTextColor(ILI9488_CYAN);  //ILI9488_MAGENTA
    tft.fillRect(300, 190, 250, 20, ILI9488_BLACK);
    tft.setCursor(300, 190);
    tft.println(text);


    int pwmOut = map(dutyCycle, 1, 99, 50, 370);
    tft.fillRect(50, 260, 370, 30, ILI9488_BLACK);
    tft.fillRect(50, 260, pwmOut, 30, ILI9488_GREEN);

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
}