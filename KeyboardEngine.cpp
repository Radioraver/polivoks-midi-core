#include "KeyboardEngine.h"

KeyboardEngine::KeyboardEngine()
{
    begin();
}

void KeyboardEngine::begin()
{
    for (uint8_t i = 0; i < BYTE_COUNT; i++)
    {
        state[i] = RELEASED_BYTE;
    }
}

bool KeyboardEngine::isValidNote(uint8_t midiNote) const
{
    return (midiNote >= FIRST_NOTE) &&
           (midiNote < (FIRST_NOTE + KEY_COUNT));
}

uint8_t KeyboardEngine::noteToIndex(uint8_t midiNote) const { return midiNote - FIRST_NOTE; }
uint8_t KeyboardEngine::keyToByte(uint8_t keyIndex) const { return keyIndex / 8; }
uint8_t KeyboardEngine::keyToBit(uint8_t keyIndex) const { return keyIndex % 8; }

void KeyboardEngine::pressKey(uint8_t keyIndex)
{
    state[keyToByte(keyIndex)] &= ~(1U << keyToBit(keyIndex));
}

void KeyboardEngine::releaseKey(uint8_t keyIndex)
{
    state[keyToByte(keyIndex)] |= (1U << keyToBit(keyIndex));
}

void KeyboardEngine::noteOn(uint8_t midiNote)
{
    if (!isValidNote(midiNote)) return;
    pressKey(noteToIndex(midiNote));
}

void KeyboardEngine::noteOff(uint8_t midiNote)
{
    if (!isValidNote(midiNote)) return;
    releaseKey(noteToIndex(midiNote));
}

const uint8_t* KeyboardEngine::getBuffer() const
{
    return state;
}
