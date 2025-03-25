
void logicAnalyze() {
  logicKeypad();
  average = 0;
  gndAdc = 0;
  ADCres = 0;
  ADCZero = 0;
  for (int i = 0; i < sampleCount; i++) {
    average += analogRead(PA0);
    gndAdc += analogRead(PA1);
    ADCres += analogRead(PA4);
    ADCZero += analogRead(PA6);
    delayMicroseconds(400);
    //delay(1);
  }
  ADCZero /= sampleCount;
  ADCres /= sampleCount;
  gndAdc /= sampleCount;
  average /= sampleCount;
  adc0 = average;

  adc0 /= 1.01340033500837520;
  //ADCZero/=1.01340033500837520;
  ADCres*=1.00275103163;
  //gndAdc/=1.01340033500837520;
  average /= 1.01340033500837520;
  //***********voltageCalibrate***************
  if (average < 1600) average /= 110.66666666;
  if (average >= 1600 && average < 1700) average /= 109.439124487;
  if (average >= 1700 && average < 1800) average /= 109.254498714;
  if (average >= 1800 && average < 1900) average /= 108.76132930513595166;
  if (average >= 1900 && average < 2000) average /= 107.3446327683615819;
  if (average >= 2000 && average < 2100) average /= 105.82010582010582;
  if (average >= 2100 && average < 2200) average /= 101.382488479262672;
  if (average >= 2200 && average < 2300) average /= 98.332620778110303548525;
  if (average >= 2300 && average < 2400) average /= 98.627787307032590;
  if (average >= 2400 && average < 2500) average /= 95.011876484560570071;
  if (average >= 2500 && average < 2600) average /= 90.579710144927536;
  if (average >= 2600 && average < 2700) average /= 86.66666666666666666;
  if (average >= 2700 && average < 2800) average /= 81.081081081081081081081;
  if (average >= 2800) average /= 78;
  InputVoltage = average;
  if (adc0 <= 200 && adc0 >= 190) InputVoltage = 0;
  if (InputVoltage < 1.2) InputVoltage *= 1.1;
  ////////////////////////////////////////////////////////////////////////
  //*************resistaneCalibrate**********
  float resistant = (4.95e-5) * pow(ADCres, 3) - (0.258) * pow(ADCres, 2) + (453.76) * ADCres - 266740;
  if (resistant > 0) {
    if (resistant < 200 && resistant >= 0) resistant = map(resistant, 0, 200, 90, 200);
    if (resistant < 500 && resistant >= 200) resistant /= 1.7;
    if (resistant < 1300 && resistant >= 500) resistant /= 1.95;
    if (resistant < 2000 && resistant >= 1300) resistant /= 1.5;
    if (resistant >= 2000 && resistant < 6000) resistant /= 1.063829787234042;
    if (resistant >= 6000 && resistant < 15000) resistant /= 1.14;
    if (resistant >= 15000) resistant /= 1.09;
  }
  if (resistant < 0) resistant = map(resistant, -260, 0, 0, 50);
  if (ADCres >= 1462 && ADCres < 1465) resistant = 20;
  if (resistant < 0 || ADCres < 1460) resistant = 0;
  ////////////////////////////////////////////////////////////////////////


  //********************Nothing*********************
  if (InputVoltage == 0 && ADCres > 2600 && ADCres < 2660) {  //Nothing
    digitalWrite(buzzer, 0);
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);   //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);  //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
    tft.fillRect(0, 160, 160, 20, ILI9488_BLACK);
  }

  //********************GND*********************
  if (ADCres <= 1461 && gndAdc < 2000 && ZeroMode == 0) {
    if (mute == 0) {
      digitalWrite(buzzer, 1);
    }
    tft.fillCircle(70, 270, 20, ILI9488_BLUE);    //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);  //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }

  if (ZeroMode == 1 && ADCZero < 1000) {
    if (mute == 0) {
      digitalWrite(buzzer, 1);
    }
    tft.fillCircle(70, 270, 20, ILI9488_BLUE);    //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);  //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }

  //********************+12v*********************
  if (InputVoltage >= 11.8) {
    if (mute == 0) digitalWrite(buzzer, !digitalRead(buzzer));
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);   //gnd
    tft.fillCircle(180, 270, 20, ILI9488_RED);    //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }

  //********************Sensor*********************
  if (InputVoltage < 5 && InputVoltage >= .1) {  // sensor
    if (mute == 0) {
      digitalWrite(buzzer, !digitalRead(buzzer));
      delay(InputVoltage);
      digitalWrite(buzzer, !digitalRead(buzzer));
    }
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);    //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);   //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);   //+5v
    tft.fillCircle(410, 270, 20, ILI9488_YELLOW);  //signal
  }

  //********************Signal*********************
  if (InputVoltage < 11.8 && InputVoltage >= 5) {  // signal
    if (mute == 0) {
      digitalWrite(buzzer, !digitalRead(buzzer));
      delay(InputVoltage * 1.5);
      digitalWrite(buzzer, !digitalRead(buzzer));
    }
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);   //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);  //+12v
    tft.fillCircle(300, 270, 20, ILI9488_GREEN);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }



  if (gndAdc >= 2000) {  //invert voltage
    text = "Probe Warning";
    tft.setTextColor(ILI9488_RED);
    tft.fillRect(0, 160, 160, 20, ILI9488_BLACK);
    tft.setCursor(0, 160);
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



  // ++lcdShowCount;
  // if (lcdShowCount >= 5) {
  //   lcdShowCount = 0;
  text = "Voltage:" + String(InputVoltage, 2) + "V";
  tft.setTextColor(ILI9488_RED);
  tft.fillRect(95, 195, 120, 20, ILI9488_BLACK);
  tft.setCursor(0, 195);
  tft.println(text);

  if (ADCres >= 2500) text = "Res: OL";
  if (resistant >= 1000 && ADCres < 2500) text = "Res:" + String(resistant / 1000, 1) + "K";
  if (resistant < 1000 && ADCres < 2500) text = "Res:" + String(resistant, 1) + "R";
  tft.setTextColor(ILI9488_CYAN);  //ILI9488_MAGENTA
  tft.fillRect(250, 195, 250, 20, ILI9488_BLACK);
  tft.setCursor(250, 195);
  tft.println(text);

  text = "ADC1:" + String(adc0, 1);
  tft.setTextColor(ILI9488_WHITE);
  tft.fillRect(47, 220, 120, 20, ILI9488_BLACK);
  tft.setCursor(0, 220);
  tft.println(text);

  text = "ADC2:" + String(ADCres, 1);
  tft.setTextColor(ILI9488_WHITE);
  tft.fillRect(250, 220, 320, 20, ILI9488_BLACK);
  tft.setCursor(250, 220);
  tft.println(text);
  //}
  // Serial1.print("adc0:");
  // Serial1.print(adc0);
  // Serial1.print(" /Voltage:");
  // Serial1.print(voltageADC0);
  // Serial1.print("/---/gndAdc:");
  // Serial1.println(ADCZero);
}

void logicKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    //***********mute************
    if (key == 'A') {
      digitalWrite(buzzer, 1);
      delay(200);
      digitalWrite(buzzer, 0);
      mute ^= 1;
      Serial1.println(mute);
      if (mute == 1) {
        digitalWrite(buzzer, 0);
        tft.setCursor(400, 0);
        tft.setTextColor(ILI9488_RED);
        tft.println("MUTE");
      }
      if (mute == 0) {
        tft.fillRect(400, 0, 100, 20, ILI9488_BLACK);
      }
      delay(100);
    }

    //***********mute************
    if (key == 'B') {
      digitalWrite(buzzer, 1);
      delay(100);
      digitalWrite(buzzer, 0);
      ZeroMode ^= 1;
      if (ZeroMode == 1) {
        tft.setCursor(350, 20);
        tft.setTextColor(ILI9488_RED);
        tft.println("Zero Mode");
      }
      if (ZeroMode == 0) {
        tft.fillRect(350, 20, 150, 20, ILI9488_BLACK);
      }
      delay(100);
    }
    // Serial1.print("Key Pressed: ");
    // Serial1.println(key);
    delay(100);  // تاخیر برای جلوگیری از چندبار خواندن
  }
}
