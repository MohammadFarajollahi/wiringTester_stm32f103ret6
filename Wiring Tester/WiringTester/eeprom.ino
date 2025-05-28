
void readEEprom() {
  voltCalib = EEPROMread(0, 9).toFloat();
  resAnalizerCalib = EEPROMread(10, 19).toFloat();
  amperCalib = EEPROMread(20, 29).toFloat();
  ohmeterCalib = EEPROMread(30, 39).toFloat();
  tempCalib = EEPROMread(40, 49).toFloat();
  voltSensorCalib = EEPROMread(50, 59).toFloat();
  Serial1.println("");
  Serial1.println("----------ReadEEPROM--------------");
  Serial1.print("volt:");
  Serial1.println(String(voltCalib,3));
  Serial1.print("resAnaliz:");
  Serial1.println(String(resAnalizerCalib,3));
  Serial1.print("amper:");
  Serial1.println(String(amperCalib,3));
  Serial1.print("ohmeter:");
  Serial1.println(String(resAnalizerCalib,3));
  Serial1.print("temp:");
  Serial1.println(String(tempCalib,3));
  Serial1.print("voltSensor:");
  Serial1.println(String(voltSensorCalib,3));
  Serial1.println("-----------------------------");
}

void eepromfirst() {
  Serial1.println("<***EEPROM First***>");
  EEPROMwrite(0, "1");  //volt
  delay(10);
  EEPROMwrite(10, "1");  //resAnalizer
  delay(10);
  EEPROMwrite(20, "1");  //amper
  delay(10);
  EEPROMwrite(30, "1");  //ohmeter
  delay(10);
  EEPROMwrite(40, "1");  //temp
  delay(10);
  EEPROMwrite(50, "1");  //voltSensor
  delay(10);
}


String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}











String EEPROMread(int StartAddr, int StringLength) {
  char buf[StringLength + 1];
  eeprom_read_string(StartAddr, buf, StringLength + 1);
  String dataStr = buf;
  return dataStr;
}

void EEPROMwrite(int StartAddr, String DataString) {
  int val = DataString.length() + 1;
  char StringChar[val];
  char buff[val];

  DataString.toCharArray(StringChar, val);
  strcpy(buff, StringChar);
  eeprom_write_string(StartAddr, buff);
}

boolean eeprom_is_addr_ok(int addr) {
  return ((addr >= addressEEPROM_min) && (addr <= addressEEPROM_max));
}

boolean eeprom_write_bytes(int startAddr, const byte* array, int numBytes) {
  int i;

  if (!eeprom_is_addr_ok(startAddr) || !eeprom_is_addr_ok(startAddr + numBytes)) {
    return false;
     Serial1.println("EEprom Error1");
  }

  for (i = 0; i < numBytes; i++) {
    EEPROM.write(startAddr + i, array[i]);
  }
  return true;
}

boolean eeprom_write_string(int addr, const char* string) {
  int numBytes;  // number of actual bytes to be written

  numBytes = strlen(string) + 1;  // Write string content plus byte terminator string (0x00)
  return eeprom_write_bytes(addr, (const byte*)string, numBytes);
}

boolean eeprom_read_string(int addr, char* buffer, int bufSize) {
  byte ch;        // read bytes from eeprom
  int bytesRead;  // number of bytes read so far

  if (!eeprom_is_addr_ok(addr))  // check the starting address
  {
    return false;
    Serial1.println("EEprom Error2");
  }

  if (bufSize == 0)  // how can we store bytes in an empty buffer?
  {
    return false;
    Serial1.println("EEprom Error3");
  }

  if (bufSize == 1) {
    buffer[0] = 0;
    return true;
  }

  bytesRead = 0;                       // initialize a byte counter
  ch = EEPROM.read(addr + bytesRead);  // read the next byte from eeprom
  buffer[bytesRead] = ch;              // save it in the user's buffer
  bytesRead++;

  // if no stop conditions are met, read the next byte from the eeprom
  while ((ch != 0x00) && (bytesRead < bufSize) && ((addr + bytesRead) <= addressEEPROM_max)) {
    ch = EEPROM.read(addr + bytesRead);
    buffer[bytesRead] = ch;  // save it in the user's buffer
    bytesRead++;
  }

  if ((ch != 0x00) && (bytesRead >= 1))  // make sure the user buffer has the string terminator, (0x00) as the last byte
  {
    buffer[bytesRead - 1] = 0;
  }
  return true;
}