float adc0;
float voltageADC0;
float average;
float gndAdc;
int analyzerState;
int sampleCount = 100;
#define ADC_PIN PA0  // پایه ADC (مثلاً PA0 برای اندازه‌گیری ولتاژ)
#define VREF 3.3     // ولتاژ مرجع ADC (VDDA میکرو، مقدار را دقیق تنظیم کنید)
void logicAnalyze() {
  average = 0;
  gndAdc = 0;
  for (int i = 0; i < sampleCount; i++) {
    average += analogRead(PA0);
    gndAdc += analogRead(PA1);
    //delayMicroseconds(20);
    delay(1);
  }
  gndAdc /= sampleCount;
  average /= sampleCount;
  adc0 = average;
  if (adc0 < 3) voltageADC0 = average / 19;
  if (adc0 < 10 && adc0 >= 3) voltageADC0 = average / 23;
  if (adc0 < 20 && adc0 >= 10) voltageADC0 = average / 50;
  if (adc0 < 30 && adc0 >= 20) voltageADC0 = average / 52.08333333333;
  if (adc0 < 40 && adc0 >= 30) voltageADC0 = average / 58.3333333;
  if (adc0 < 50 && adc0 >= 40) voltageADC0 = average / 60;
  if (adc0 < 60 && adc0 >= 50) voltageADC0 = average / 63;
  if (adc0 < 70 && adc0 >= 60) voltageADC0 = average / 65;
  if (adc0 < 110 && adc0 >= 70) voltageADC0 = average / 68.75;
  if (adc0 < 200 && adc0 >= 110) voltageADC0 = average / 71.68458781362007168;
  if (adc0 < 300 && adc0 >= 200) voltageADC0 = average / 75;
  if (adc0 < 400 && adc0 >= 300) voltageADC0 = average / 75.4716981132075;
  if (adc0 < 500 && adc0 >= 400) voltageADC0 = average / 75.0750750750;
  if (adc0 < 600 && adc0 >= 500) voltageADC0 = average / 75.75757575757575757;
  if (adc0 < 1000 && adc0 >= 600) voltageADC0 = average / 76.394194041252864;
  if (adc0 < 1500 && adc0 >= 1000) voltageADC0 = average / 76.9230769230769;
  if (adc0 >= 1500) voltageADC0 = average / 77;



  if (adc0 >= 120 && adc0 <= 122 && gndAdc >= 2315 && gndAdc <= 2322) {
    voltageADC0 = 0;
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);
  }

  if (adc0 >= 110 && adc0 <= 124 && gndAdc >= 2200 && gndAdc <= 2400) {  //nothing
    voltageADC0 = 0;
    digitalWrite(buzzer, 0);
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);   //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);  //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }

  if (voltageADC0 < 4.5 && voltageADC0 > 0 && gndAdc >= 200) {  // signal
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);                 //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);                //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);                //+5v
    tft.fillCircle(410, 270, 20, ILI9488_YELLOW);               //signal
  }

  if (voltageADC0 < 5.2 && voltageADC0 > 4.8 && gndAdc >= 200) {  // +5v
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);                   //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);                  //+12v
    tft.fillCircle(300, 270, 20, ILI9488_GREEN);                  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);                  //signal
  }

  if (voltageADC0 >= 11.8 && gndAdc >= 200) {     // +12v
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);   //gnd
    tft.fillCircle(180, 270, 20, ILI9488_RED);    //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }

  if (gndAdc < 170) {  //gnd
    digitalWrite(buzzer, 1);
    tft.fillCircle(70, 270, 20, ILI9488_BLUE);    //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);  //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }


  text = "Voltage:" + String(voltageADC0, 2) + "V";
  tft.setTextColor(ILI9488_WHITE);
  tft.fillRect(95, 185, 120, 20, ILI9488_BLACK);
  tft.setCursor(0, 185);
  tft.println(text);

  text = "ADC:" + String(adc0);
  tft.setTextColor(ILI9488_WHITE);
  tft.fillRect(47, 210, 120, 20, ILI9488_BLACK);
  tft.setCursor(0, 210);
  tft.println(text);

  float resistant;
  if (gndAdc <= 200) resistant = gndAdc / 0.66071428571428;
  if (gndAdc <= 400 && gndAdc > 200) resistant = gndAdc / 0.156818181;
  if (gndAdc <= 500 && gndAdc > 400) resistant = gndAdc / 0.121212121212121;
  if (gndAdc > 500) resistant = gndAdc / 0.08;


  if (gndAdc < 1000) text = "RES:" + String(resistant);
  if (gndAdc >= 1000) text = "RES: OL";
  tft.setTextColor(ILI9488_WHITE);
  tft.fillRect(300, 210, 170, 20, ILI9488_BLACK);
  tft.setCursor(300, 210);
  tft.println(text);

  Serial1.print("adc:");
  Serial1.print(adc0);
  Serial1.print("/Voltage:");
  Serial1.print(voltageADC0);
  Serial1.print("/adc2:");
  Serial1.println(gndAdc);


  // if (digitalRead(ingnd) == 0) {
  //   Serial1.println("in-");
  // }
}
