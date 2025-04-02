
int OutOskop;
void OskoP() {
  while (1) {
    if (!hold) {
      oSkop();
    }

    KeyPad();
    if (OutOskop == 1) {
      MenuSelectChange = 1;
      MenuSelect = 1;
      tft.fillScreen(ILI9488_BLACK);
      MenuSelect = 1;
      MenuSelectChange = 1;
      digitalWrite(buzzer, 1);
      delay(250);
      digitalWrite(buzzer, 0);
      tft.setTextSize(2);
      tft.setCursor(330, 125);
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
      tft.println("5:Thermometer");
      tft.println("6:Frequency Meter");
      tft.println("7:Oscilloscope");
      tft.println("8:Signal Generator");
      tft.println("9:Sensor Simulator");
      // tft.setCursor(330, 125);
      // tft.println("D:Next menu");
      //line
      tft.drawLine(0, 150, 480, 150, ILI9488_WHITE);
      break;
    }
  }
}


void KeyPad() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    //بلندگو خاموش
    if (key == 'A') {
      sampleSize += 100;
      BuzzerBIGbig();
      delay(5);
    }

    if (key == 'B') {
      sampleSize -= 100;
      if (sampleSize < 100) sampleSize = 100;
      BuzzerBIGbig();
    }

    if (key == '1') {
      timeDiv += .1;
      BuzzerBIGbig();
    }

    if (key == '2') {
      timeDiv -= .1;
      BuzzerBIGbig();
      if (timeDiv < 0) timeDiv = 0;
    }

    if (key == 'C') {
      signal_calib += .1;
      BuzzerBIGbig();
    }

    if (key == 'D') {
      signal_calib -= .1;

      BuzzerBIGbig();
    }

    if (key == '#') {
      hold = !hold;
      BuzzerSet();
    }

    if (key == '*') {
      OutOskop = 1;
    }
  }
}

void drawGrid() {
  // رسم شبکه برای صفحه نمایشگر
  tft.setTextColor(ILI9488_DARKGREY);
  for (int x = 0; x < 480; x += 40) {
    tft.drawLine(x, 0, x, 320 - signalInfoHeight, ILI9488_DARKGREY);
  }
  for (int y = 0; y < 320 - signalInfoHeight; y += 40) {
    tft.drawLine(0, y, 480, y, ILI9488_DARKGREY);
  }
}

void drawSignalInfo(float voltage, float freq) {
  // نمایش اطلاعات سیگنال در پایین صفحه
  tft.setTextSize(1);
  tft.setTextColor(ILI9488_YELLOW);
  tft.fillRect(0, 300 - signalInfoHeight, 480, 320, ILI9488_BLACK);
  tft.fillRect(0, 300 - signalInfoHeight, 480, signalInfoHeight, ILI9488_BLACK);

  tft.setCursor(10, 300 - signalInfoHeight + 10);
  TextLcd = "Voltage:" + String(voltage, 2) + "V";
  tft.print(TextLcd);
  tft.setCursor(10, 290);
  TextLcd = "voltageScale:" + String(signal_calib, 2);
  tft.print(TextLcd);

  tft.setCursor(200, 290);
  TextLcd = "threshold:" + String(sampleSize);
  tft.print(TextLcd);
  tft.setCursor(200, 300 - signalInfoHeight + 10);
  TextLcd = "frequency:" + String(freq, 2) + "HZ";
  tft.print(TextLcd);

  tft.setCursor(350, 290);
  TextLcd = "Time/DIV:" + String(timeDiv, 2) + " ";
  tft.print(TextLcd);
}

void drawWaveform() {
  for (int i = 0; i < sampleSize - 1; i++) {
    int x1 = i;
    int y1 = map(lastSamples[i], 0, 4095, 270 - signalInfoHeight - 1, 0);
    int x2 = i + 1;
    int y2 = map(lastSamples[i + 1], 0, 4095, 270 - signalInfoHeight - 1, 0);

    // پاک کردن موج قبلی
    tft.drawLine(x1, y1, x2, y2, ILI9488_BLACK);

    // رسم موج جدید
    y1 = map(samples[i], 0, 4095, 270 - signalInfoHeight - 1, 0);
    y2 = map(samples[i + 1], 0, 4095, 270 - signalInfoHeight - 1, 0);
    tft.drawLine(x1, y1, x2, y2, ILI9488_GREEN);
  }

  // ذخیره مقادیر فعلی برای حذف موج در فریم بعدی
  memcpy(lastSamples, samples, sizeof(samples));
}

void oSkop() {

  unsigned long currentTime = micros();

  // خواندن نمونه‌ها
  for (int i = 0; i < sampleSize; i++) {
    samples[i] = analogRead(analogPin);
    delayMicroseconds(timeDiv * 10);  // تأثیر Time/Div بر روی سرعت نمونه‌برداری
    samples[i] *= signal_calib;
    // تشخیص لبه‌ها برای محاسبه فرکانس
    static bool lastSignalState = false;
    bool currentSignalState = samples[i] > threshold;

    if (currentSignalState && !lastSignalState) {  // تشخیص لبه بالا
      unsigned long timeNow = micros();
      unsigned long pulseWidth = timeNow - lastEdgeTime;

      if (pulseWidth > debounceTime) {        // حذف نویز
        frequency_ = 1000000.0 / pulseWidth;  // فرکانس بر حسب هرتز
        lastEdgeTime = timeNow;
      }
    }
    lastSignalState = currentSignalState;
  }

  // رسم موج سیگنال
  drawWaveform();

  // محاسبه ولتاژ و نمایش مشخصات سیگنال
  float voltage = analogRead(analogPin) * voltageScale;
  voltage *= 6.833333;
  voltage_avg += voltage;
  ++volt_cout;
  if (volt_cout >= 5) {
    voltage_avg /= 3;
    voltage = voltage_avg;
    voltage_avg = 0;
    volt_cout = 0;
    drawSignalInfo(voltage, frequency_);
  }


  // delay(10);
}
