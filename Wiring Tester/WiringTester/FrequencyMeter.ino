
int hz;
void FrequencyMeter() {
  freq_meter();
  char mystr[40];
  if (freq < 1000) hz = 1;
  if (freq >= 1000) {
    hz = 0;
    freq /= 1000;
  }
  if (hz == 1) text = "Frequency:" + String(freq) + "HZ";
  if (hz == 0) text = "Frequency:" + String(freq) + "KHz";

  tft.setTextSize(4);
  tft.setTextColor(ILI9488_CYAN);
  tft.fillRect(10, 240, 500, 40, ILI9488_BLACK);
  tft.setCursor(10, 240);
  tft.println(text);
}
void freq_meter() {  // http://arduino.ru/forum/proekty/generator-s-reguliruemoei-chastotoi-na-arduino#comment-296530
  __asm volatile("cpsid i");
  /// Timer2 счёт младших 16 бит
  TIMER2_BASE->CR1 = 0;  //стоп таймер
  TIMER2_BASE->CCER = 0;
  TIMER2_BASE->PSC = 0;
  TIMER2_BASE->CNT = 0;
  TIMER2_BASE->CCR1 = 0;
  TIMER2_BASE->CCR2 = 0;
  TIMER2_BASE->CCR3 = 0;
  TIMER2_BASE->CCR4 = 0;
  TIMER2_BASE->PSC = 0;
  TIMER2_BASE->SR = 0;
  TIMER2_BASE->CCMR2 = 0;
  TIMER2_BASE->CR2 = 1 << 5;      //MMS:010 управление подчинённым в режиме "Update"
  TIMER2_BASE->SMCR = (1 << 14);  // ECE & TS:000  режим 2 внешнего тактирования & разрешение работы от таймера1
  TIMER2_BASE->ARR = 65535;       //считать до максимума
  TIMER2_BASE->EGR = 1;           //перечитать регистры.
  TIMER2_BASE->CR1 |= (1 << 0);   //start timer2
                                  /// Timer3 счёт старших 16 бит
  TIMER3_BASE->CR1 = 1 << 0;      //стоп таймер
  TIMER3_BASE->CCER = 0;
  TIMER3_BASE->PSC = 0;
  TIMER3_BASE->CNT = 0;
  TIMER3_BASE->CCR1 = 0;
  TIMER3_BASE->CCR2 = 0;
  TIMER3_BASE->CCR3 = 0;
  TIMER3_BASE->CCR4 = 0;
  TIMER3_BASE->PSC = 0;
  TIMER3_BASE->SR = 0;
  TIMER3_BASE->CR2 = 0;
  TIMER3_BASE->CCMR1 = 0;
  TIMER3_BASE->SMCR = (1 << 2) | (1 << 1) | (1 << 0) | (1 << 4);  //SMS:111 && TS:001  такт брать от 2-го таймера
  TIMER3_BASE->ARR = 65535;                                       //считать до
  TIMER3_BASE->EGR = 1;                                           //перечитать регистры.
  TIMER3_BASE->CR1 |= (1 << 0);                                   //start timer3
                                                                  /// настройка времени разрешения на таймере1 для таймера2
  TIMER1_BASE->CR1 = (1 << 3) | (1 << 2);                         //один импульс, без прерываний
  TIMER1_BASE->CNT = 0;
  TIMER1_BASE->CR2 = (1 << 4);           //MMS:001 сигнал разрешения работы другим таймерам
  TIMER1_BASE->CCER = 0;                 // отключить выходы таймера на физ ноги
  TIMER1_BASE->PSC = F_CPU / 36000 - 1;  // 1999; // 72000000/2000= 36000кГц тактовая таймера
  TIMER1_BASE->ARR = 35996;              //считать до 36000 (1секунда)
  TIMER1_BASE->EGR = 1;                  //перечитать регистры.
  TIMER1_BASE->CR1 |= (1 << 0);
  __asm volatile("cpsie i");
  while (TIMER1_BASE->CR1 & 1) {
    asm volatile("nop");
    if (mon_flag) { return; }
  }
  freq = TIMER3_BASE->CNT << 16 | TIMER2_BASE->CNT;
}
