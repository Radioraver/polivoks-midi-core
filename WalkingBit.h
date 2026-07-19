#ifndef WALKING_BIT_H
#define WALKING_BIT_H

#include <Arduino.h>

#include "ShiftRegisterDriver.h"

class WalkingBit
{
public:

    explicit WalkingBit(ShiftRegisterDriver& driver);

    void begin();

    void update();

private:

    static constexpr uint8_t KEY_COUNT = 48;
    static constexpr uint8_t BYTE_COUNT = KEY_COUNT / 8;

    static constexpr unsigned long STEP_TIME = 100;

    ShiftRegisterDriver& shiftRegister;

    uint8_t buffer[BYTE_COUNT];

    uint8_t currentBit;

    unsigned long lastStepTime;

    void clearBuffer();

    void setBit(uint8_t bit);

    void printState() const;
};

#endif
