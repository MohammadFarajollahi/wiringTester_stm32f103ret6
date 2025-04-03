

void Generator() {
  GeneratorKeypad();

  delay(10);
}

void GeneratorKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    //***********Frequency Setting************
    if (key == 'A') {
      BuzzerBIGbig();
      if (plus100 == 1) pwmFrequency += 1;
      if (plus100 == 2) pwmFrequency += 10;
      if (plus100 == 3) pwmFrequency += 100;
      if (pwmFrequency <= 1) pwmFrequency = 1;
      delay(50);
    }

    if (key == 'B') {
      BuzzerBIGbig();
      if (plus100 == 1) pwmFrequency -= 1;
      if (plus100 == 2) pwmFrequency -= 10;
      if (plus100 == 3) pwmFrequency -= 100;
      if (pwmFrequency <= 1) pwmFrequency = 1;
      delay(50);
    }

    //***********Duty Setting************
    if (key == 'C') {
      BuzzerBIGbig();
      ++dutyCycle;
      if (dutyCycle <= 1) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;

      delay(50);
    }

    if (key == 'D') {
      BuzzerBIGbig();
      --dutyCycle;
      if (dutyCycle <= 1) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;

      delay(50);
    }

    if (key == '*') {
      BuzzerSet();
      setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);
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
      delay(500);
    }
    if (dutyCycle <= 1) dutyCycle = 1;
    if (dutyCycle >= 99) dutyCycle = 99;
    if (pwmFrequency <= 1) pwmFrequency = 1;
    setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);

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
  }
}