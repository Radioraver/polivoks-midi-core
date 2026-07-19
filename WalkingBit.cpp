#include "WalkingBit.h"

//--------------------------------------------------
// Constructor
//--------------------------------------------------

WalkingBit::WalkingBit(ShiftRegisterDriver& driver)
    : shiftRegister(driver),
      currentBit(0),
      lastStepTime(0)
{
}

//--------------------------------------------------
// Initialize test
//--------------------------------------------------

void WalkingBit::begin()
{
    clearBuffer();

    setBit(0);

    shiftRegister.update(buffer);
}

//--------------------------------------------------
// Update test
//--------------------------------------------------

void WalkingBit::update()
{
    if ((millis() - lastStepTime) < STEP_TIME)
    {
        return;
    }

    lastStepTime = millis();

    currentBit++;

    if (currentBit >= KEY_COUNT)
    {
        currentBit = 0;
    }

    clearBuffer();

    setBit(currentBit);

    shiftRegister.update(buffer);
}

//--------------------------------------------------
// Clear output buffer
//--------------------------------------------------

void WalkingBit::clearBuffer()
{
    for (uint8_t i = 0; i < BYTE_COUNT; i++)
    {
        buffer[i] = 0x00;
    }
}

//--------------------------------------------------
// Set one output bit
//--------------------------------------------------

void WalkingBit::setBit(uint8_t bit)
{
    uint8_t byteIndex = bit / 8;

    uint8_t bitIndex = bit % 8;

    buffer[byteIndex] |= (1 << bitIndex);
}
