
#include "ShiftRegisterDriver.h"

ShiftRegisterDriver::ShiftRegisterDriver()
{
}

void ShiftRegisterDriver::begin()
{
    pinMode(LATCH_PIN, OUTPUT);
    digitalWrite(LATCH_PIN, HIGH);

    SPI.begin();

    SPI.beginTransaction(
        SPISettings(
            1000000,       // 1 MHz
            MSBFIRST,
            SPI_MODE0));
}

void ShiftRegisterDriver::update(const uint8_t* buffer)
{
    digitalWrite(LATCH_PIN, LOW);

    // Передаємо всі 6 байтів у каскад регістрів
    for (int i = 5; i >= 0; i--)
    {
        SPI.transfer(buffer[i]);
    }

    latch();
}

void ShiftRegisterDriver::latch()
{
    digitalWrite(LATCH_PIN, HIGH);
    delayMicroseconds(1);
    digitalWrite(LATCH_PIN, LOW);
    delayMicroseconds(1);
    digitalWrite(LATCH_PIN, HIGH);
}
```
