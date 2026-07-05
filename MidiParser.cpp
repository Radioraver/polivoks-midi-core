#include "MidiParser.h"

#include <MIDI.h>

// Створення стандартного MIDI-інтерфейсу бібліотеки
MIDI_CREATE_DEFAULT_INSTANCE();

void MidiParser::begin()
{
    // Працюємо з MIDI-каналом №1
    MIDI.begin(1);

    noteOnReceived = false;
    noteOffReceived = false;
}

void MidiParser::update()
{
    // Скинути прапорці перед прийомом нового повідомлення
    noteOnReceived = false;
    noteOffReceived = false;

    // Якщо нових повідомлень немає — вихід
    if (!MIDI.read())
    {
        return;
    }

    midi::MidiType messageType = MIDI.getType();

    switch (messageType)
    {
        case midi::NoteOn:
            currentNote = MIDI.getData1();
            noteOnReceived = true;
            break;

        case midi::NoteOff:
            currentNote = MIDI.getData1();
            noteOffReceived = true;
            break;

        default:
            break;
    }
}

bool MidiParser::isNoteOn() const
{
    return noteOnReceived;
}

bool MidiParser::isNoteOff() const
{
    return noteOffReceived;
}

uint8_t MidiParser::getNote() const
{
    return currentNote;
}
