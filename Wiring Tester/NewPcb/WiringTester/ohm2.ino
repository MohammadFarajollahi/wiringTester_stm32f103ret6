

void ohm2() {
oHmKeypad();
  average = 0;
  gndAdc = 0;
  ADCres = 0;
  //ADCZero = 0;
  for (int i = 0; i < sampleCount; i++) {
    average += analogRead(PA0);
    gndAdc += analogRead(PA1);
    ADCres += analogRead(PA4);
    //ADCZero += analogRead(PA6);
    delayMicroseconds(400);
    //delay(1);
  }
  //ADCZero /= sampleCount;
  ADCres /= sampleCount;
  gndAdc /= sampleCount;
  average /= sampleCount;
  adc0 = average;

  adc0 /= 1.01340033500837520;
  //ADCZero/=1.01340033500837520;
  ADCres *= 1.00275103163;
  //gndAdc/=1.01340033500837520;
  average /= 1.01340033500837520;
  //***********voltageCalibrate***************
  if (average < 1500) average /= 110.66666666;
  if (average >= 1500 && average < 1700) average /= 109.439124487;
  if (average >= 1700 && average < 1800) average /= 107.747747747747747;
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
  InputVoltage *= voltCalib;
  if (adc0 <= 210 && adc0 >= 160) InputVoltage = 0;
  if (InputVoltage < 1.2) InputVoltage *= 1.1;
  InputVoltage /= 1.00735294;

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
  //if (resistant < 0 || ADCres < 1460) resistant = 0;
  ////////////////////////////////////////////////////////////////////////
  tft.setTextSize(3);
  if (ADCres > 1470) {  //شستشس
    resistant *= 1.06;
    if (ADCres >= 2500) text = "Res: OL";
    if (resistant >= 1000 && ADCres < 2500) text = "Res:" + String(resistant / 1000, 1) + "K";
    if (resistant < 1000 && ADCres < 2500) text = "Res:" + String(resistant, 1) + "R";
    tft.setTextColor(ILI9488_YELLOW);
    tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
    tft.setCursor(0, 170);
    tft.println(text);
  }

  if (ADCres <= 1470) {
    resistant = map(ADCres, 1460, 1468, 0, 100);
    if (resistant < 0) resistant = 0;
    text = "Res:" + String(resistant, 1) + "R";
    tft.setTextColor(ILI9488_YELLOW);
    tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
    tft.setCursor(0, 170);
    tft.println(text);
  }
}