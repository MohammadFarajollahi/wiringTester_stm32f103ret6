


void VoltMEter() {
  average = 0;
  for (int i = 0; i < 150; i++) {
    average += analogRead(PA0);
    // delay(1);
    delayMicroseconds(1000);
    //delay(1);
  }

  average /= 150;
  adc0 = average;
  average /= 1.012;
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
  tft.setTextSize(3);
  text = "Voltage:" + String(InputVoltage, 2) + "V";
  tft.setTextColor(ILI9488_RED);
  tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
  tft.setCursor(0, 170);
  tft.println(text);

KeypadVoltage();
}



void KeypadVoltage() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    //***********mute************
    if (key == 'A') {
    }

    if (key == '#') {
      ExitToMenu = 1;
      BuzzerBIGbig();
    }
    delay(100);  // تاخیر برای جلوگیری از چندبار خواندن
  }
}