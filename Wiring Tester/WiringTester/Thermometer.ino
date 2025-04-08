

void Thermometer() {

  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    //***********mute************
    if (key == '#') {
      ExitToMenu = 1;
      BuzzerBIGbig();
    }
    if (key == '*') {
      uint16_t rawTemp = readRegister(0x07);  // خواندن دمای محیط
      float ambientTemp = rawTemp * 0.02 - 273.15;

      uint16_t rawObjTemp = readRegister(0x06);  // خواندن دمای جسم
      float objectTemp = rawObjTemp * 0.02 - 273.15;

      // Serial1.print("Ambient Temp: ");
      // Serial1.print(ambientTemp);
      // Serial1.println(" °C");
      // Serial1.print("Object Temp: ");
      // Serial1.print(objectTemp);
      // Serial1.println(" °C");
      // Serial1.println("--------------------");
      text = "Temp:" + String(ambientTemp) + "C";
      tft.setTextSize(3);
      tft.setTextColor(ILI9488_RED);
      tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
      tft.setCursor(0, 170);
      tft.println(text);
      BuzzerSet();
      delay(500);
    }
  }
}