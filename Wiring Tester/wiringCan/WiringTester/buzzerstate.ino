

void BuzzerBIGbig() {
  if (mute == 0) {
    digitalWrite(buzzer, 1);
    delay(10);
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