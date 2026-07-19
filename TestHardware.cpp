#include "TestHardware.h"

//--------------------------------------------------
// Constructor
//--------------------------------------------------

TestHardware::TestHardware(ShiftRegisterDriver& driver)
    : walkingBit(driver)
{
}

//--------------------------------------------------
// Initialize hardware tests
//--------------------------------------------------

void TestHardware::begin()
{
    walkingBit.begin();
}

//--------------------------------------------------
// Update hardware tests
//--------------------------------------------------

void TestHardware::update()
{
    walkingBit.update();
}
