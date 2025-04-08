

void Generator() {
  GeneratorKeypad();

  delay(10);
}

void GeneratorKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    if (key == '#') {
      ExitToMenu = 1;
      BuzzerBIGbig();
    }
    //***********Frequency Setting************
    if (key == '6') {
      BuzzerBIGbig();
      if (plus100 == 0) pwmFrequency += 1;
      if (plus100 == 1) pwmFrequency += 100;
      if (pwmFrequency <= 1) pwmFrequency = 1;
      delay(50);
    }

    if (key == '4') {
      BuzzerBIGbig();
      if (plus100 == 0) pwmFrequency -= 1;
      if (plus100 == 1) pwmFrequency -= 100;
      if (pwmFrequency <= 1) pwmFrequency = 1;
      delay(50);
    }

    //***********Duty Setting************
    if (key == '2') {
      BuzzerBIGbig();
      ++dutyCycle;
      if (dutyCycle <= 1) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;

      delay(50);
    }

    if (key == '8') {
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
        tft.println("D: Pulse Count -> +1");
      }
      delay(500);
    }
    if (dutyCycle <= 1) dutyCycle = 1;
    if (dutyCycle >= 99) dutyCycle = 99;
    if (pwmFrequency <= 1) pwmFrequency = 1;
    setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);

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
  }
}