

void ohMmeter() {
  oHmKeypad();
  float Vout = readVoltage();
  float Vin = 3.3;  // ولتاژ مرجع تغذیه

  if (Vout >= 3.29) {  ///Vin
    Serial1.println("Overrange!");
    tft.setTextSize(3);
    text = "RES: OL";
    tft.setTextColor(ILI9488_YELLOW);
    tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
    tft.setCursor(0, 170);
    tft.println(text);
    delay(1000);
    return;
  }

  // فرمول مقاومت:
  float RX = R_REF * (Vout / (Vin - Vout));
  float Res = Res;

  Serial1.print("Vout: ");
  Serial1.print(Vout, 6);
  Serial1.println(" V");
  Serial1.print("Resistance: ");
  if (Vout >= 0.01) {
    if (RX >= 200000) Res = RX * 1.12;
    if (RX < 200000 && RX >= 80000) Res = RX * 1.036269430051813471502;
    if (RX < 800000 && RX >= 20000) Res = RX * 1.008;
    if (RX < 20000 && RX >= 950) Res = RX * 1;
    if (RX < 950 && RX >= 500) Res = RX / 1.014705882352941176;
    if (RX < 500 && RX >= 200) Res = RX / 1.075757575757575757575;
    if (RX < 200 && RX >= 150) Res = RX / 1.14573459715639810;
    if (RX < 150 && RX >= 90) Res = RX / 1.25;
    if (RX < 90 && RX >= 60) Res = RX / 1.0882352941176;
    if (RX < 60 && RX >= 40) Res = RX / 2.181818181818181818;
    if (RX < 40 && RX >= 28) Res = RX / 3.86;
    if (Vout <= 0.009) Res = 0;
  }

  if (Vout < 0.01) {
    Res = RX / 6.5;
    if (Vout <= 0.009) Res = 0;
  }


  // delay(200);
  tft.setTextSize(3);
  if (Res < 1000) text = "RES:" + String(Res, 2) + " R";
  if (Res >= 1000) text = "RES:" + String(Res / 1000, 2) + " K";
  if (Res >= 1000000) text = "RES:" + String(Res / 1000000, 2) + " M";
  tft.setTextColor(ILI9488_YELLOW);
  tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
  tft.setCursor(0, 170);
  tft.println(text);
  tft.setTextSize(1);
  text = "ADC:" + String(RX) + " Voltage:" + String(Vout) + "v";
  tft.setTextColor(ILI9488_WHITE);
  tft.fillRect(0, 220, 300, 20, ILI9488_BLACK);
  tft.setCursor(0, 220);
  tft.println(text);
  delay(500);
}


void oHmKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    if (key == '#') {
      ExitToMenu = 1;
      BuzzerBIGbig();
    }
  }
}