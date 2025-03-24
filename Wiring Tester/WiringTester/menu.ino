

void menu() {

  if (mainMenu == 1) {
    if (changeMenu == 1) {
      changeMenu = 0;
      tft.setTextSize(2);
      tft.setCursor(200, 25);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("*Main Menu*");
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("1:Logic Analyzer");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("2:Volt meter");
      tft.println("3:Ampere meter");
      tft.println("4:Ohm meter");
      tft.println("5:Capacitor Meter");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      tft.setCursor(330, 125);
      tft.println("D:Next menu");

      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }

    ReadMainKeypad();
  }

  //**********Logic Analyzer***********
  if (MenuSelect == 1) {
    if (MenuSelectChange == 1) {
      MenuSelectChange = 0;
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
  }

  //**********Logic Analyzer***********
  if (MenuSelect == 2) {
    if (MenuSelectChange == 1) {
      MenuSelectChange = 0;
      //logic
      tft.setCursor(170, 160);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("Volt Meter");
    }
    VoltMEter();
  }
}


void ReadMainKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    //***********Logic************
    if (key == '1') {
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 1;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("1:Logic Analyzer");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("2:Volt meter");
      tft.println("3:Ampere meter");
      tft.println("4:Ohm meter");
      tft.println("5:Capacitor Meter");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      tft.setCursor(330, 125);
      tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }
    //***********voltmeter************
    if (key == '2') {
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 2;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(0, 0);
      tft.setTextColor(ILI9488_WHITE);
      tft.println("1:Logic Analyzer");
      tft.setTextColor(ILI9488_MAGENTA);
      tft.println("2:Volt meter");
      tft.setTextColor(ILI9488_WHITE);
      tft.println("3:Ampere meter");
      tft.println("4:Ohm meter");
      tft.println("5:Capacitor Meter");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      tft.setCursor(330, 125);
      tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
    }
  }
}