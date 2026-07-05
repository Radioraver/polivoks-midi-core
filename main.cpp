#include <Arduino.h>

#include "KeyboardEngine.h"
#include "ShiftRegisterDriver.h"
#include "MidiParser.h"


//--------------------------------------------------
// Створення модулів
//--------------------------------------------------

KeyboardEngine keyboard;

ShiftRegisterDriver shiftRegister;

MidiParser midi;


//--------------------------------------------------
// Ініціалізація системи
//--------------------------------------------------

void setup()
{
    keyboard.begin();

    shiftRegister.begin();

    midi.begin();
}


//--------------------------------------------------
// Головний цикл
//--------------------------------------------------

void loop()
{
    midi.update();

    bool keyboardChanged = false;

    if (midi.isNoteOn())
    {
        keyboard.noteOn(midi.getNote());
        keyboardChanged = true;
    }

    if (midi.isNoteOff())
    {
        keyboard.noteOff(midi.getNote());
        keyboardChanged = true;
    }

    if (keyboardChanged)
    {
        shiftRegister.update(keyboard.getBuffer());
    }
}
