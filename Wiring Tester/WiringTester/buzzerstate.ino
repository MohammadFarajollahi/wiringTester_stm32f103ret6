

void BuzzerBIGbig() {
  if (mute == 0) {
    digitalWrite(buzzer, 1);
    delay(20);
    digitalWrite(buzzer, 0);
  }
}

void BuzzerSet() {
  if (mute == 0) {
    digitalWrite(buzzer, 1);
    delay(100);
    digitalWrite(buzzer, 0);
  }
}