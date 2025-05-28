

void Thermometer() {

  average = 0;
  for (int i = 0; i < 200; i++) {
    average += analogRead(PC0);
    delay(1);
    //delay(1);
  }
  int adcValue = average / 200;
  float voltage = (adcValue * VREF) / 4095.0;
  // اعمال مقدار اولیه Offset برای دقت بهتر
  float current = (voltage - offset) / SENSITIVITY;
  current *= 1.65;
  current *= 2.551724137931034;  // FOR 30A
  current *= amperCalib;
  if (current < 0) current *= -1;
  tft.setTextSize(3);
  text = "Current:" + String(current, 2) + " A";
  tft.setTextColor(ILI9488_CYAN);
  tft.fillRect(0, 100, 300, 40, ILI9488_BLACK);
  tft.setCursor(0, 100);
  tft.println(text);

  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    //***********mute************
    if (key == '#') {
      ExitToMenu = 1;
      BuzzerBIGbig();
    }
    if (key == '*') {
      releGenerator();
      dutyCycle = 60;
      pwmFrequency = 20000;
      plus100 = 1;
      setupPWM(myTimer4, 1, pwmFrequency, dutyCycle);
      //////
      text = "Out: 12V";
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

































// void Thermometer() {

//   char key = getKey();  // خواندن کلید
//   if (key != '\0') {
//     //***********mute************
//     if (key == '#') {
//       ExitToMenu = 1;
//       BuzzerBIGbig();
//     }
//     if (key == '*') {
//       uint16_t rawTemp = readRegister(0x07);  // خواندن دمای محیط
//       float ambientTemp = rawTemp * 0.02 - 273.15;

//       uint16_t rawObjTemp = readRegister(0x06);  // خواندن دمای جسم
//       float objectTemp = rawObjTemp * 0.02 - 273.15;

//       // Serial1.print("Ambient Temp: ");
//       // Serial1.print(ambientTemp);
//       // Serial1.println(" °C");
//       // Serial1.print("Object Temp: ");
//       // Serial1.print(objectTemp);
//       // Serial1.println(" °C");
//       // Serial1.println("--------------------");
//       text = "Temp:" + String(ambientTemp) + "C";
//       tft.setTextSize(3);
//       tft.setTextColor(ILI9488_RED);
//       tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
//       tft.setCursor(0, 170);
//       tft.println(text);
//       BuzzerSet();
//       delay(500);
//     }
//   }
// }