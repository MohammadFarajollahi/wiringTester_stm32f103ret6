#include <SoftWire.h>

#define SDA_PIN PB5
#define SCL_PIN PB7
#define MLX90614_ADDRESS 0x5A  // آدرس سنسور

SoftWire myWire(SDA_PIN, SCL_PIN);  

uint16_t readRegister(uint8_t reg) {
    myWire.beginTransmission(MLX90614_ADDRESS);
    myWire.write(reg);
    myWire.endTransmission(false);
    myWire.requestFrom(MLX90614_ADDRESS, (uint8_t)2);

    uint16_t data = myWire.read();
    data |= (uint16_t)myWire.read() << 8;
    return data;
}

void setup() {
    Serial1.begin(115200);
    myWire.begin();
    Serial1.println("MLX90614 Initialized!");
}

void loop() {
    uint16_t rawTemp = readRegister(0x07);  // خواندن دمای محیط
    float ambientTemp = rawTemp * 0.02 - 273.15;

    uint16_t rawObjTemp = readRegister(0x06);  // خواندن دمای جسم
    float objectTemp = rawObjTemp * 0.02 - 273.15;

    Serial1.print("Ambient Temp: "); Serial1.print(ambientTemp); Serial1.println(" °C");
    Serial1.print("Object Temp: "); Serial1.print(objectTemp); Serial1.println(" °C");
    Serial1.println("--------------------");

    delay(1000);
}
