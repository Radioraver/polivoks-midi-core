#ifndef MidiParser.h
#define MidiParser.h

#include <Arduino.h>

class MidiParser
{
public:

    // Ініціалізація MIDI
    void begin();

    // Обробка вхідних MIDI-повідомлень
    void update();

    // Ознаки останньої MIDI-події
    bool isNoteOn() const;
    bool isNoteOff() const;

    // Номер MIDI-ноти
    uint8_t getNote() const;

private:

    bool noteOnReceived = false;
    bool noteOffReceived = false;

    uint8_t currentNote = 0;
};

#endif
