


void keyPadconfig() {
  // تنظیم ردیف‌ها به خروجی
  for (int i = 0; i < ROWS; i++) {
    pinMode(rowPins[i], OUTPUT);
    delay(1);
    digitalWrite(rowPins[i], HIGH);
  }

  // تنظیم ستون‌ها به ورودی با پول‌آپ داخلی
  for (int j = 0; j < COLS; j++) {
    pinMode(colPins[j], INPUT_PULLUP);
    delay(1);
  }
}

// تابع برای خواندن کلیدها
char getKey() {
  for (int i = 0; i < ROWS; i++) {
    digitalWrite(rowPins[i], LOW);  // ردیف موردنظر را LOW کن
    delayMicroseconds(1);

    for (int j = 0; j < COLS; j++) {
      if (digitalRead(colPins[j]) == LOW) {  // اگر ستونی LOW شد، یعنی کلید فشرده شده
        //  (digitalRead(colPins[j]) == LOW)
        //   ;                              // صبر کن تا رها شود
        digitalWrite(rowPins[i], HIGH);  // ردیف را دوباره HIGH کن
        return keys[i][j];               // مقدار کلید را برگردان
      }
    }

    digitalWrite(rowPins[i], HIGH);  // بعد از چک کردن، ردیف را HIGH کن
  }
  return '\0';  // اگر کلیدی فشرده نشد، مقدار خالی برگردان
}