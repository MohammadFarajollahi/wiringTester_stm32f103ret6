

void WaterSensor() {

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
      if (plus100 == 1) dutyCycle += 0.1;
      if (plus100 == 2) dutyCycle += 1;
      if (plus100 == 3) dutyCycle += 5;
      if (dutyCycle < 0) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;
      delay(5);
      setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);
    }

    if (key == '4') {
      BuzzerBIGbig();
      if (plus100 == 1) dutyCycle -= 0.1;
      if (plus100 == 2) dutyCycle -= 1;
      if (plus100 == 3) dutyCycle -= 5;
      if (dutyCycle < 0) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;
      delay(5);
      setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);
    }

    tft.drawLine(10, 259, 250, 259, ILI9488_WHITE);
    tft.drawLine(10, 259, 10, 290, ILI9488_WHITE);
    tft.drawLine(10, 290, 250, 290, ILI9488_WHITE);
    tft.drawLine(250, 259, 250, 290, ILI9488_WHITE);

    int pwmOut = map(dutyCycle, 1, 99, 50, 197);
    tft.fillRect(11, 260, 197, 30, ILI9488_BLACK);
    tft.fillRect(11, 260, pwmOut, 30, ILI9488_GREEN);
  }
}