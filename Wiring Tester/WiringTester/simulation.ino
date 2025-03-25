

void simulator() {
  simulateKeypad();
  tft.setTextSize(2);
  text = "Frequency:" + String(pwmFrequency) + " HZ";
  tft.setTextColor(ILI9488_RED);
  tft.fillRect(0, 250, 200, 20, ILI9488_BLACK);
  tft.setCursor(0, 250);
  tft.println(text);

  text = "Duty:" + String(dutyCycle) + " %";
  tft.setTextColor(ILI9488_CYAN);  //ILI9488_MAGENTA
  tft.fillRect(250, 250, 250, 20, ILI9488_BLACK);
  tft.setCursor(250, 250);
  tft.println(text);

  if (dutyCycle < 0) dutyCycle = 0;
  if (pwmFrequency < 0) pwmFrequency = 0;
  delay(10);
}


void simulateKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    //***********Frequency Setting************
    if (key == 'A') {
      digitalWrite(buzzer, 1);
      delay(100);
      digitalWrite(buzzer, 0);
      if (plus100 == 0) ++pwmFrequency;
      if (plus100 == 1) pwmFrequency += 100;
    }

    if (key == 'B') {
      digitalWrite(buzzer, 1);
      delay(100);
      digitalWrite(buzzer, 0);
      if (plus100 == 0) --pwmFrequency;
      if (plus100 == 1) pwmFrequency -= 100;
    }

    //***********Duty Setting************
    if (key == 'C') {
      digitalWrite(buzzer, 1);
      delay(100);
      digitalWrite(buzzer, 0);
      ++dutyCycle;
    }

    if (key == 'D') {
      digitalWrite(buzzer, 1);
      delay(100);
      digitalWrite(buzzer, 0);
      --dutyCycle;
    }

    if (key == '*') {
      digitalWrite(buzzer, 1);
      delay(300);
      digitalWrite(buzzer, 0);
      setupPWM(myTimer1, 1, pwmFrequency, dutyCycle);
    }
    if (key == '0') {
      digitalWrite(buzzer, 1);
      delay(300);
      digitalWrite(buzzer, 0);
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
    }
  }
}