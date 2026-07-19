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

private:

    uint8_t buttonPin;

    bool currentState;
    bool previousState;

    bool pressedEvent;
};

#endif
