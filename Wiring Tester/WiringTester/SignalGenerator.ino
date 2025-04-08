


void SignalGenerator() {


  signalGenKey();
}

void signalGenKey() {
  char key = getKey();  // خواندن کلید
  if (key != '\0') {
    if (key == '#') {
      ExitToMenu = 1;
      BuzzerBIGbig();
      /////////////////
      
    }
  }
}