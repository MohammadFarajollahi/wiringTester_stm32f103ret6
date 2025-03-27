
float map2(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void simulator() {
  simulateKeypad();

  float readPwmVoltage = 0;
  for (int i = 0; i <= 200; i++) {
    readPwmVoltage += analogRead(PC1);
    delayMicroseconds(500);
  }
  float PwmVoltage = readPwmVoltage /= 200;
  float rrr = PwmVoltage;
  PwmVoltage /= 89.979550102249488752556237218814;
  text = "Voltage:" + String(PwmVoltage) + " V  adc:" + String(rrr);  //
  tft.setTextColor(ILI9488_YELLOW);               //ILI9488_MAGENTA
  tft.fillRect(0, 230, 400, 20, ILI9488_BLACK);
  tft.setCursor(0, 230);
  tft.println(text);

  delay(5);
}


void simulateKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
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

    float readPwmVoltage = 0;
    for (int i = 0; i <= 100; i++) {
      readPwmVoltage += analogRead(PC1);
      delayMicroseconds(500);
    }
    float PwmVoltage = readPwmVoltage /= 100;
    float rrr = PwmVoltage;
    PwmVoltage /= 381.5580286168521;
    text = "Voltage:" + String(PwmVoltage) + " V";  //
    tft.setTextColor(ILI9488_YELLOW);               //ILI9488_MAGENTA
    tft.fillRect(0, 230, 400, 20, ILI9488_BLACK);
    tft.setCursor(0, 230);
    tft.println(text);


    int pwmOut = map(dutyCycle, 1, 99, 50, 370);
    tft.fillRect(50, 260, 370, 30, ILI9488_BLACK);
    tft.fillRect(50, 260, pwmOut, 30, ILI9488_GREEN);
    //***********Frequency Setting************
    if (key == 'A') {
      BuzzerBIGbig();
      if (plus100 == 0) ++pwmFrequency;
      if (plus100 == 1) pwmFrequency += 100;
      if (pwmFrequency <= 1) pwmFrequency = 1;
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    if (key == 'B') {
      BuzzerBIGbig();
      if (plus100 == 0) --pwmFrequency;
      if (plus100 == 1) pwmFrequency -= 100;
      if (pwmFrequency <= 1) pwmFrequency = 1;
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    //***********Duty Setting************
    if (key == 'C') {
      BuzzerBIGbig();
      if (plus100 == 0) ++dutyCycle;
      if (plus100 == 1) dutyCycle += 10;
      if (dutyCycle <= 1) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;
      delay(10);
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    if (key == 'D') {
      BuzzerBIGbig();
      if (plus100 == 0) --dutyCycle;
      if (plus100 == 1) dutyCycle -= 10;
      if (dutyCycle <= 1) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;
      delay(10);
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }

    if (key == '*') {
      BuzzerSet();
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }
    if (key == '0') {
      BuzzerSet();
      plus100 ^= 1;
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
      delay(10);
    }
    if (dutyCycle <= 1) dutyCycle = 1;
    if (dutyCycle >= 99) dutyCycle = 99;
    if (pwmFrequency <= 1) pwmFrequency = 1;
  }
}