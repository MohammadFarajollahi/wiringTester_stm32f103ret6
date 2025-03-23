float adc0;
float voltageADC0;
float average;
float gndAdc;
int analyzerState;
int sampleCount = 200;
int lcdShowCount;
float ADCres;
#define ADC_PIN PA0  // پایه ADC (مثلاً PA0 برای اندازه‌گیری ولتاژ)
#define VREF 3.3     // ولتاژ مرجع ADC (VDDA میکرو، مقدار را دقیق تنظیم کنید)
void logicAnalyze() {
  average = 0;
  gndAdc = 0;
  for (int i = 0; i < sampleCount; i++) {
    average += analogRead(PA0);
    gndAdc += analogRead(PA1);
    ADCres += analogRead(PA4);
    //delayMicroseconds(20);
    delay(1);
  }
  ADCres /= sampleCount;
  gndAdc /= sampleCount;
  average /= sampleCount;
  adc0 = average;
  //***********voltageCalibrate***************
  if (average < 1600) average /= 110.66666666;
  if (average >= 16000 && average < 16000) average /= 107.9411764705882352;
  //*************resistaneCalibrate**********
  float resistant = (4.95e-5) * pow(ADCres, 3) - (0.258) * pow(ADCres, 2) + (453.76) * ADCres - 266740;
  if (resistant > 0) {
    if (resistant < 200 && resistant >= 0) resistant = map(resistant, 0, 200, 90, 200);
    if (resistant < 500 && resistant >= 200) resistant /= 1.7;
    if (resistant < 1300 && resistant >= 500) resistant /= 1.95;
    if (resistant < 2000 && resistant >= 1300) resistant /= 1.5;
    if (resistant >= 2000 && resistant < 6000) resistant /= 1.063829787234042;
    if (resistant >= 6000 && resistant<15000) resistant /= 1.14;
    if(resistant >=15000)resistant /= 1.09;
  }
  if (resistant < 0) resistant = map(resistant, -260, 0, 0, 90);
  if (resistant < 0) resistant = 0;
  ++lcdShowCount;
  if (lcdShowCount >= 1) {
    lcdShowCount = 0;
    text = "Voltage:" + String(average, 2) + "V";
    tft.setTextColor(ILI9488_RED);
    tft.fillRect(95, 195, 120, 20, ILI9488_BLACK);
    tft.setCursor(0, 195);
    tft.println(text);

    if (ADCres >= 2500) text = "Res: OL";
    if (resistant >= 1000 && ADCres < 2500) text = "Res:" + String(resistant / 1000, 1) + "K";
    if (resistant < 1000 && ADCres < 2500) text = "Res:" + String(resistant, 1) + "R";
    tft.setTextColor(ILI9488_ORANGE);
    tft.fillRect(250, 195, 250, 20, ILI9488_BLACK);
    tft.setCursor(250, 195);
    tft.println(text);

    text = "ADC:" + String(adc0 , 1);
    tft.setTextColor(ILI9488_WHITE);
    tft.fillRect(47, 220, 120, 20, ILI9488_BLACK);
    tft.setCursor(0, 220);
    tft.println(text);

    if (resistant >= 1000) text = "ADC2:" + String(ADCres, 1);
    if (resistant < 1000) text = "ADC2:" + String(ADCres, 1);
    tft.setTextColor(ILI9488_WHITE);
    tft.fillRect(250, 220, 320, 20, ILI9488_BLACK);
    tft.setCursor(250, 220);
    tft.println(text);
  }
  // Serial1.print("adc0:");
  // Serial1.print(adc0);
  // Serial1.print(" /Voltage:");
  // Serial1.print(voltageADC0);
  // Serial1.print("/---/gndAdc:");
  // Serial1.println(gndAdc);
}
