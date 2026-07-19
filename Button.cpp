#include "Button.h"

Button::Button(uint8_t pin)
    : buttonPin(pin),
      rawState(HIGH),
      lastRawState(HIGH),
      stableState(HIGH),
      pressedEvent(false),
      releasedEvent(false),
      lastChangeTime(0)
{
}

void Button::begin()
{
    pinMode(buttonPin, INPUT_PULLUP);
}

void Button::update()
{
    pressedEvent = false;
    releasedEvent = false;

    rawState = digitalRead(buttonPin);

    // Контакт змінився
    if (rawState != lastRawState)
    {
        lastChangeTime = millis();

        lastRawState = rawState;
    }

    // Час Debounce минув
    if ((millis() - lastChangeTime) >= DEBOUNCE_TIME)
    {
        if (stableState != rawState)
        {
            stableState = rawState;

            if (stableState == LOW)
            {
                pressedEvent = true;
            }
            else
            {
                releasedEvent = true;
            }
        }
    }
}

bool Button::isPressed() const
{
    return stableState == LOW;
}

bool Button::wasPressed() const
{
    return pressedEvent;
}

bool Button::wasReleased() const
{
    return releasedEvent;
}
