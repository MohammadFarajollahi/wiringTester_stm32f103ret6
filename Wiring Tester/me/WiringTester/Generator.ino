

void Generator() {
  GeneratorKeypad();

  //*****************************READ CURRENTR*****************************
  //*****************************READ CURRENTR*****************************
  //*****************************READ CURRENTR*****************************
  average = 0;
  for (int i = 0; i < 200; i++) {
    average += analogRead(PC0);
    delay(1);
    //delay(1);
  }
  int adcValue = average / 200;
  float voltage = (adcValue * VREF) / 4095.0;
  // اعمال مقدار اولیه Offset برای دقت بهتر
  float current = (voltage - offset) / SENSITIVITY;
  current *= 1.65;
  //current *= 2.551724137931034;  // FOR 30A
  current *= amperCalib;
  if (current < 0) current *= -1;
  tft.setTextSize(2);
  text = "Current:" + String(current, 2) + " A";
  tft.setTextColor(ILI9488_BLUE);
  tft.fillRect(0, 160, 300, 40, ILI9488_BLACK);
  tft.setCursor(0, 160);
  tft.println(text);

}

void GeneratorKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    if (key == '#') {
      ExitToMenu = 1;
      BuzzerBIGbig();
    }
    //***********Frequency Setting************
    if (key == '2') {
      BuzzerBIGbig();
      if (plus100 == 0) pwmFrequency += 1;
      if (plus100 == 1) pwmFrequency += 100;
      if (pwmFrequency <= 1) pwmFrequency = 1;
      //delay(50);
    }

    if (key == '8') {
      BuzzerBIGbig();
      if (plus100 == 0) pwmFrequency -= 1;
      if (plus100 == 1) pwmFrequency -= 100;
      if (pwmFrequency <= 1) pwmFrequency = 1;
      //delay(50);
    }

    //***********Duty Setting************
    if (key == '6') {
      BuzzerBIGbig();
      ++dutyCycle;
      if (dutyCycle <= 1) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;

     // delay(50);
    }

    if (key == '4') {
      BuzzerBIGbig();
      --dutyCycle;
      if (dutyCycle <= 1) dutyCycle = 1;
      if (dutyCycle >= 99) dutyCycle = 99;

      //delay(50);
    }

    if (key == '*') {
      BuzzerSet();
      setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);
    }
    if (key == 'D') {
      BuzzerSet();
      plus100 ^= 1;
      if (plus100 == 1) {
        tft.setTextSize(1);
        tft.fillRect(0, 300, 150, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(0, 300);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("F4: Pulse Count -> +100");
      }
      if (plus100 == 0) {
        tft.setTextSize(1);
        tft.fillRect(0, 300, 150, 20, ILI9488_BLACK);
        digitalWrite(buzzer, 0);
        tft.setCursor(0, 300);
        tft.setTextColor(ILI9488_WHITE);
        tft.println("F4: Pulse Count -> +1");
      }
      delay(250);
    }
    if (dutyCycle <= 1) dutyCycle = 1;
    if (dutyCycle >= 99) dutyCycle = 99;
    if (pwmFrequency <= 1) pwmFrequency = 1;
    setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);

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
  }
}