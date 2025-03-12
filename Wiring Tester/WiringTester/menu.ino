

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
      tft.setCursor(170, 165);
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
      tft.setCursor(285, 300);
      tft.setTextColor(ILI9488_GREEN);
      tft.println("+5");
      tft.setCursor(380, 300);
      tft.setTextColor(ILI9488_YELLOW);
      tft.println("SIGNAL");
    }

    logicAnalyze();

    char key = getKey();  // خواندن کلید
    if (key != '\0') {
      Serial1.print("Key Pressed: ");
      Serial1.println(key);
      delay(20);  // تاخیر برای جلوگیری از چندبار خواندن
    }
  }
}