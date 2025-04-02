

void OhmMeter() {
  ADCres = 0;
  for (int i = 0; i < 500; i++) {
    ADCres += analogRead(PA4);
    delayMicroseconds(500);
    //delay(1);
  }
  ADCres /= 500;
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

  if (ADCres > 1465) {
    resistant*=1.079365079365079365;
    if (ADCres >= 2500) text = "Res: OL";
    if (resistant >= 1000 && ADCres < 2500) text = "Res:" + String(resistant / 1000, 1) + "K";
    if (resistant < 1000 && ADCres < 2500) text = "Res:" + String(resistant, 1) + "R";
    tft.setTextSize(5);
    tft.setTextColor(ILI9488_YELLOW);
    tft.fillRect(50, 240, 500, 40, ILI9488_BLACK);
    tft.setCursor(50, 240);
    tft.println(text);
  }

  if (ADCres <= 1465) {
    resistant = map(ADCres, 1445, 1465, 0, 100);
    if(resistant<0)resistant=0;
    text = "Res:" + String(resistant, 1) + "R";
    tft.setTextSize(5);
    tft.setTextColor(ILI9488_YELLOW);
    tft.fillRect(50, 240, 500, 40, ILI9488_BLACK);
    tft.setCursor(50, 240);
    tft.println(text);
  }

  text = "adc:" + String(ADCres);
  tft.setTextSize(2);
  tft.setTextColor(ILI9488_WHITE);
  tft.fillRect(0, 180, 200, 30, ILI9488_BLACK);
  tft.setCursor(0, 180);
  tft.println(text);
}