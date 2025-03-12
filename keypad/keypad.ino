#define ROWS 4
#define COLS 4

// پین‌های ردیف و ستون را مشخص کنید
const int rowPins[ROWS] = { PC0, PC1, PC2, PC3 };  // ردیف‌ها
const int colPins[COLS] = { PC4, PC5, PC6, PC7 };  // ستون‌ها

// نقشه‌ی دکمه‌ها مطابق با ترتیب واقعی
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

void setup() {
  Serial1.begin(115200);

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

void loop() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    Serial1.print("Key Pressed: ");
    Serial1.println(key);
    delay(20);  // تاخیر برای جلوگیری از چندبار خواندن
  }
}

// تابع برای خواندن کلیدها
char getKey() {
  for (int i = 0; i < ROWS; i++) {
    digitalWrite(rowPins[i], LOW);  // ردیف موردنظر را LOW کن
    delayMicroseconds(5);

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
