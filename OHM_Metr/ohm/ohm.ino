#include <SoftWire.h>

#define SDA_PIN PB5
#define SCL_PIN PB7

#define ADS1115_ADDRESS 0x48  // آدرس پیش فرض
#define R_REF 10000.0         // مقاومت مرجع (10KΩ دقیق)

SoftWire myWire(SDA_PIN, SCL_PIN);

void writeRegister(uint8_t reg, uint16_t value) {
  myWire.beginTransmission(ADS1115_ADDRESS);
  myWire.write(reg);
  myWire.write(value >> 8);
  myWire.write(value & 0xFF);
  myWire.endTransmission();
}

int16_t readADC() {
  myWire.beginTransmission(ADS1115_ADDRESS);
  myWire.write(0x00);  // آدرس رجیستر دیتا
  myWire.endTransmission();
  myWire.requestFrom(ADS1115_ADDRESS, (uint8_t)2);
  int16_t result = ((int16_t)myWire.read() << 8) | myWire.read();
  return result;
}

void configADS() {
  // کانفیگ: ورودی AIN0 نسبت به GND
  // PGA = ±4.096V, MODE = Single Shot
  writeRegister(0x01, 0xC283);
}

float readVoltage() {
  configADS();

  // شروع کانورت
  myWire.beginTransmission(ADS1115_ADDRESS);
  myWire.write(0x00);
  myWire.endTransmission();

  // صبر کن تا تبدیل تموم بشه
  delay(10);

  int16_t raw = readADC();

  // تبدیل به ولتاژ
  float voltage = (raw * 4.096) / 32768.0;
  if (voltage < 0) voltage = 0;  // از نوسان نویز جلوگیری کن
  return voltage;
}

int rele1 = PC8;
int rele2 = PC9;
int rele3 = PC10;
int rele4 = PC11;
void setup() {
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  digitalWrite(rele1, 1);
  digitalWrite(rele2, 1);
  digitalWrite(rele3, 1);
  Serial1.begin(115200);
  myWire.begin();
  Serial1.println("ADS1115 Initialized for Ohm Meter!");
}

void loop() {
  float Vout = readVoltage();
  float Vin = 3.28;  // ولتاژ مرجع تغذیه

  if (Vout >= Vin) {
    Serial1.println("Overrange!");
    delay(1000);
    return;
  }

  // فرمول مقاومت:
  float Rx = R_REF * (Vout / (Vin - Vout));

  Serial1.print("Vout: ");
  Serial1.print(Vout, 6);
  Serial1.println(" V");
  Serial1.print("Resistance: ");
  if (Rx < 1000)
    Serial1.print(Rx, 1), Serial1.println(" Ohm");
  else
    Serial1.print(Rx / 1000.0, 2), Serial1.println(" kOhm");

  Serial1.println("------------------------------");

  delay(500);
}
