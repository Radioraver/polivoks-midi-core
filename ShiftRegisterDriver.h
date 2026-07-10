
#ifndef SHIFT_REGISTER_DRIVER_H
#define SHIFT_REGISTER_DRIVER_H

#include <Arduino.h>
#include <SPI.h>

class ShiftRegisterDriver
{
public:
    ShiftRegisterDriver();

    void begin();
    void update(const uint8_t* buffer);

private:
    static constexpr uint8_t LATCH_PIN = 10;

    void latch();
};

#endif // SHIFT_REGISTER_DRIVER_H
```
