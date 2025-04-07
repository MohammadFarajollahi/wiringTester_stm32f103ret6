

void AmpereMeter() {
  CurrentKeypad();
  if (DCMode == 1) {
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
    tft.setTextSize(3);
    text = "Current:" + String(current, 2) + " A";
    tft.setTextColor(ILI9488_CYAN);
    tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
    tft.setCursor(0, 170);
    tft.println(text);
  }

  if (DCMode == 0) {
    currentRMS = measureCurrentRMS();
    float current = currentRMS;
    tft.setTextSize(3);
    text = "Current:" + String(current, 2) + " A";
    tft.setTextColor(ILI9488_CYAN);
    tft.fillRect(0, 170, 300, 40, ILI9488_BLACK);
    tft.setCursor(0, 170);
    tft.println(text);
  }
}


// محاسبه آفست سنسور (در حالت بدون جریان)
float calibrateOffset() {
  long sum = 0;
  for (int i = 0; i < SAMPLES; i++) {
    sum += analogRead(SENSOR_PIN);
  }
  return (float)sum / SAMPLES * (5 / 4095.0);  // تبدیل مقدار ADC به ولتاژ
}

// اندازه‌گیری جریان RMS
float measureCurrentRMS() {
  long sumSquares = 0;
  for (int i = 0; i < SAMPLES; i++) {
    int sensorValue = analogRead(SENSOR_PIN);
    float voltage = sensorValue * (5 / 4095.0);                      // تبدیل مقدار ADC به ولتاژ
    float current = (voltage - offsetVoltage) / SENSOR_SENSITIVITY;  // محاسبه جریان
    sumSquares += current * current;                                 // مجذور جریان
  }
  float meanSquare = (float)sumSquares / SAMPLES;
  return sqrt(meanSquare);  // بازگشت مقدار RMS
}


void CurrentKeypad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    if (key == '#') {
      ExitToMenu = 1;
      BuzzerBIGbig();
    }
    //***********AC / DC************
    if (key == '0') {

      digitalWrite(buzzer, 1);
      delay(100);
      digitalWrite(buzzer, 0);

      DCMode ^= 1;
      tft.setTextSize(2);
      if (DCMode == 1) {
        tft.fillRect(0, 75, 140, 20, ILI9488_BLACK);
        tft.setCursor(0, 75);
        digitalWrite(buzzer, 0);
        tft.setTextColor(ILI9488_RED);
        tft.println("Dc Mode");
        float sum = 0;
        for (int i = 0; i < 200; i++) {
          sum += analogRead(ACS712_PIN);
          delay(1);
        }
        offset = (sum / 200.0) * VREF / 4095.0;  // میانگین‌گیری برای حذف نویز
      }
      if (DCMode == 0) {
        tft.fillRect(0, 75, 140, 20, ILI9488_BLACK);
        tft.setCursor(0, 75);
        tft.setTextColor(ILI9488_RED);
        tft.println("AC Mode");
        //*******adc******
        offsetVoltage = calibrateOffset();  // محاسبه آفست اولیه سنسور
      }
    }
  }
}