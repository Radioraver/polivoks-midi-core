#ifndef TEST_HARDWARE_H
#define TEST_HARDWARE_H

#include <Arduino.h>

#include "ShiftRegisterDriver.h"
#include "WalkingBit.h"

class TestHardware
{
public:

    explicit TestHardware(ShiftRegisterDriver& driver);

    void begin();

    void update();

private:

    WalkingBit walkingBit;
};

#endif
