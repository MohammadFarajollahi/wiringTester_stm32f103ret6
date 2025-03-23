

void menu() {

  if (mainMenu == 1) {
    if (changeMenu == 1) {
      changeMenu = 0;
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("1:Volt meter");
      tft.println("2:Ampere meter");
      tft.println("3:Ohm meter");
      tft.println("4:Signal generator");
      tft.println("5:Oscilloscope");
      tft.println("6:Coil tester");
      tft.println("7:ABS Signal");
      tft.println("8:Gas pedal");
      tft.println("9:Can Tester");
      tft.setCursor(330, 125);
      tft.println("D:Next menu");
      // tft.println("B:Selonoeid Tester");
      // tft.println("C:Remot");
      // tft.println("D:Tachometer");
      // tft.println("*:Thermometer");
      // tft.println("0:Ecu Wiring Test");
      // tft.println("#:Wiring Cut Test");

      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
      //logic
      tft.setCursor(170, 160);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("Logic Analyzer");
      //circle
      tft.fillCircle(70, 270, 20, ILI9488_WHITE);
      tft.fillCircle(180, 270, 20, ILI9488_WHITE);
      tft.fillCircle(300, 270, 20, ILI9488_WHITE);
      tft.fillCircle(410, 270, 20, ILI9488_WHITE);
      //logicName
      tft.setCursor(52, 300);
      tft.setTextColor(ILI9488_BLUE);
      tft.println("GND");
      tft.setCursor(160, 300);
      tft.setTextColor(ILI9488_RED);
      tft.println("+12");
      tft.setCursor(245, 300);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("SIGNSAL+5V");
      tft.setCursor(380, 300);
      tft.setTextColor(ILI9488_YELLOW);
      tft.println("SENSOR");
    }

    logicAnalyze();

    char key = getKey();  // خواندن کلید
    if (key != '\0') {
      //***********mute************
      if (key == 'C') {
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
          tft.fillRect(400, 0, 480, 20, ILI9488_BLACK);
        }
        delay(300);
      }
      // Serial1.print("Key Pressed: ");
      // Serial1.println(key);
      delay(500);  // تاخیر برای جلوگیری از چندبار خواندن
    }
  }
}



// if (key == '1') {
//         Serial1.print("ADC:");
//         Serial1.print(gndAdc);
//         Serial1.print(" ---> out:");
//         Serial1.println("200");
//       }

//       if (key == '2') {
//         Serial1.print("ADC:");
//         Serial1.print(gndAdc);
//         Serial1.print(" ---> out:");
//         Serial1.println("300");
//       }

//       if (key == '3') {
//         Serial1.print("ADC:");
//         Serial1.print(gndAdc);
//         Serial1.print(" ---> out:");
//         Serial1.println("500");
//       }

//       if (key == '4') {
//         Serial1.print("ADC:");
//         Serial1.print(gndAdc);
//         Serial1.print(" ---> out:");
//         Serial1.println("850");
//       }

//       if (key == '5') {
//         Serial1.print("ADC:");
//         Serial1.print(gndAdc);
//         Serial1.print(" ---> out:");
//         Serial1.println("1000");
//       }

//       if (key == '6') {
//         Serial1.print("ADC:");
//         Serial1.print(gndAdc);
//         Serial1.print(" ---> out:");
//         Serial1.println("2000");
//       }

//       if (key == '7') {
//         Serial1.print("ADC:");
//         Serial1.print(gndAdc);
//         Serial1.print(" ---> out:");
//         Serial1.println("4700");
//       }

//       if (key == '8') {
//         Serial1.print("ADC:");
//         Serial1.print(gndAdc);
//         Serial1.print(" ---> out:");
//         Serial1.println("6800");
//       }

//       if (key == '9') {
//         Serial1.print("ADC:");
//         Serial1.print(gndAdc);
//         Serial1.print(" ---> out:");
//         Serial1.println("10000");
//       }

//       if (key == '0') {
//         Serial1.print("ADC:");
//         Serial1.print(gndAdc);
//         Serial1.print(" ---> out:");
//         Serial1.println("20000");
//       }