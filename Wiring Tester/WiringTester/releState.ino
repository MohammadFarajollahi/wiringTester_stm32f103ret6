

void releCurrent() {
  digitalWrite(rele1, 0);
  digitalWrite(rele2, 0);
  digitalWrite(rele3, 0);
  digitalWrite(rele4, 0);
  digitalWrite(Releselonoeid, 0);
  digitalWrite(ReleAmper, 1);
  myTimer1.pause();        // متوقف کردن تایمر
  digitalWrite(PA8, LOW);  // پین را صفر کن
  myTimer4.pause();        // متوقف کردن تایمر
  digitalWrite(PB6, LOW);  // پین را صفر کن
}

void releAnalyzer() {
  digitalWrite(rele1, 0);
  digitalWrite(rele2, 0);
  digitalWrite(rele3, 0);
  digitalWrite(rele4, 0);
  digitalWrite(Releselonoeid, 0);
  digitalWrite(ReleAmper, 0);
  myTimer1.pause();        // متوقف کردن تایمر
  digitalWrite(PA8, LOW);  // پین را صفر کن
  myTimer4.pause();        // متوقف کردن تایمر
  digitalWrite(PB6, LOW);  // پین را صفر کن
}

void releGenerator() {
  digitalWrite(rele1, 0);
  digitalWrite(rele2, 0);
  digitalWrite(rele3, 0);
  digitalWrite(rele4, 0);
  digitalWrite(Releselonoeid, 1);
  digitalWrite(ReleAmper, 0);
}

void releFrequency() {
  digitalWrite(rele1, 1);
  digitalWrite(rele2, 1);
  digitalWrite(rele3, 0);
  digitalWrite(rele4, 0);
  digitalWrite(Releselonoeid, 0);
  digitalWrite(ReleAmper, 0);
  myTimer1.pause();        // متوقف کردن تایمر
  digitalWrite(PA8, LOW);  // پین را صفر کن
  myTimer4.pause();        // متوقف کردن تایمر
  digitalWrite(PB6, LOW);  // پین را صفر کن
}

void releSimulator() {
  digitalWrite(rele1, 1);
  digitalWrite(rele2, 0);
  digitalWrite(rele3, 0);
  digitalWrite(rele4, 0);
  digitalWrite(Releselonoeid, 0);
  digitalWrite(ReleAmper, 0);
}