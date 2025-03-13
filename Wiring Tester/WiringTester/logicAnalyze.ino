float adc0;
float voltageADC0;
float average;
float gndAdc;
int analyzerState;
int sampleCount = 75;
int lcdShowCount;
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
  ///////////////////////resistance///////////////////
  // ADC:184.10 ---> out:200
  // ADC:192.00 ---> out:300
  // ADC:210.23 ---> out:500
  // ADC:240.37 ---> out:850
  // ADC:259.53 ---> out:1000
  // ADC:339.07 ---> out:2000
  // ADC:531.63 ---> out:4700
  // ADC:651.87 ---> out:6800
  // ADC:835.57 ---> out:10000
  // ADC:1152.23 ---> out:20000
  float resistant = 0.0185 * pow(gndAdc, 1.97);
  if (resistant < 1000) resistant = map(resistant, 550, 1000, 200, 1000);

  if (adc0 >= 120 && adc0 <= 122 && gndAdc >= 2315 && gndAdc <= 2322) {
    voltageADC0 = 0;
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);
  }

  if (adc0 >= 100 && adc0 <= 130 && gndAdc >= 2200 && gndAdc <= 2400) {  //nothing
    voltageADC0 = 0;
    digitalWrite(buzzer, 0);
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);   //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);  //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }

  if (voltageADC0 < 4.5 && voltageADC0 >= .1 && gndAdc >= 200) {  // sensor
    if (mute == 0) {
      digitalWrite(buzzer, !digitalRead(buzzer));
      delay(10);
      digitalWrite(buzzer, !digitalRead(buzzer));
    }
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);    //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);   //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);   //+5v
    tft.fillCircle(410, 270, 20, ILI9488_YELLOW);  //signal
  }

  if (voltageADC0 < 11.8 && voltageADC0 >= 4.5 && gndAdc >= 200) {  // signal
    if (mute == 0) {
      digitalWrite(buzzer, !digitalRead(buzzer));
      delay(20);
      digitalWrite(buzzer, !digitalRead(buzzer));
    }
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);   //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);  //+12v
    tft.fillCircle(300, 270, 20, ILI9488_GREEN);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }

  if (voltageADC0 >= 11.8 && gndAdc >= 200) {  // +12v
    if (mute == 0) digitalWrite(buzzer, !digitalRead(buzzer));
    tft.fillCircle(70, 270, 20, ILI9488_WHITE);   //gnd
    tft.fillCircle(180, 270, 20, ILI9488_RED);    //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }

  //if (gndAdc < 170) {  //gnd
  if (resistant <= 50) {
    if (mute == 0) digitalWrite(buzzer, 1);
    tft.fillCircle(70, 270, 20, ILI9488_BLUE);    //gnd
    tft.fillCircle(180, 270, 20, ILI9488_WHITE);  //+12v
    tft.fillCircle(300, 270, 20, ILI9488_WHITE);  //+5v
    tft.fillCircle(410, 270, 20, ILI9488_WHITE);  //signal
  }


  ++lcdShowCount;
  if (lcdShowCount >= 1) {
    lcdShowCount = 0;

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

    if (gndAdc < 1500) {
      if (resistant < 1000) {
        if (resistant <= 40) = 0;
        // resistant = map(resistant, 550, 1000, 200, 1000);
        text = "RES:" + String(resistant) + "R";
      }
      if (resistant >= 1000) text = "RES:" + String(resistant / 1000) + "K";
    }
    if (gndAdc >= 1500) text = "RES: OL";

    tft.setTextColor(ILI9488_WHITE);
    tft.fillRect(300, 210, 170, 20, ILI9488_BLACK);
    tft.setCursor(300, 210);
    tft.println(text);
  }
  Serial1.print("adc0:");
  Serial1.print(adc0);
  Serial1.print(" /Voltage:");
  Serial1.print(voltageADC0);
  Serial1.print("/---/gndAdc:");
  Serial1.print(gndAdc);
  Serial1.print(" /res:");
  Serial1.println(resistant);
}
