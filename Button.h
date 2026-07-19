#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{
public:

    explicit Button(uint8_t pin);

    void begin();
    void update();

    bool isPressed() const;

    bool wasPressed() const;
    bool wasReleased() const;

private:

    static constexpr unsigned long DEBOUNCE_TIME = 20;

    uint8_t buttonPin;

    bool rawState;
    bool lastRawState;
    bool stableState;

    bool pressedEvent;
    bool releasedEvent;

    unsigned long lastChangeTime;
};

#endif
