#ifndef TEST_MANAGER_H
#define TEST_MANAGER_H

#include <Arduino.h>

enum class TestMode
{
    WalkingBit
};

class TestManager
{
public:

    void begin();

    void update();

private:

    TestMode currentMode = TestMode::WalkingBit;
};

#endif
