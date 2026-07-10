#ifndef KEYBOARD_ENGINE_H
#define KEYBOARD_ENGINE_H

#include <stdint.h>

class KeyboardEngine
{
public:
    static constexpr uint8_t FIRST_NOTE = 36;
    static constexpr uint8_t KEY_COUNT = 48;

    static constexpr uint8_t BYTE_COUNT = KEY_COUNT / 8;

    static constexpr uint8_t KEY_PRESSED   = 0;
    static constexpr uint8_t KEY_RELEASED  = 1;
    static constexpr uint8_t RELEASED_BYTE = 0xFF;

    static_assert((KEY_COUNT % 8) == 0, "KEY_COUNT must be divisible by 8.");

    KeyboardEngine();
    void begin();
    void noteOn(uint8_t midiNote);
    void noteOff(uint8_t midiNote);
    const uint8_t* getBuffer() const;

private:
    uint8_t state[BYTE_COUNT];
    bool isValidNote(uint8_t midiNote) const;
    uint8_t noteToIndex(uint8_t midiNote) const;
    uint8_t keyToByte(uint8_t keyIndex) const;
    uint8_t keyToBit(uint8_t keyIndex) const;
    void pressKey(uint8_t keyIndex);
    void releaseKey(uint8_t keyIndex);
};

#endif
