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
    // Оновити MIDI
    midi.update();

    // Обробка Note On
    if (midi.isNoteOn())
    {
        keyboard.noteOn(midi.getNote());

        shiftRegister.update(keyboard.getBuffer());
    }

    // Обробка Note Off
    if (midi.isNoteOff())
    {
        keyboard.noteOff(midi.getNote());

        shiftRegister.update(keyboard.getBuffer());
    }
}
