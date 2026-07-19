#include "Button.h"

Button::Button(uint8_t pin)
    : buttonPin(pin),
      currentState(HIGH),
      previousState(HIGH),
      pressedEvent(false)
{
}

void Button::begin()
{
    pinMode(buttonPin, INPUT_PULLUP);
}

void Button::update()
{
    previousState = currentState;

    currentState = digitalRead(buttonPin);

    pressedEvent =
        (previousState == HIGH) &&
        (currentState == LOW);
}

bool Button::isPressed() const
{
    return currentState == LOW;
}

bool Button::wasPressed() const
{
    return pressedEvent;
}
