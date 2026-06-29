# polivoks-midi-core
polivoks-midi-core
Reference MIDI Interface Core for the Polivoks Synthesizer
 
Overview
polivoks-midi-core is an open-source embedded project aimed at developing a reliable, maintainable and well-documented MIDI interface for the legendary Soviet analog synthesizer Polivoks.
The project is designed as a reference implementation rather than just another Arduino sketch.
Every architectural decision is documented and explained. The primary goal is long-term maintainability, portability and educational value.
 
Project Goals
•	Reliable MIDI to keyboard conversion.
•	Full polyphony.
•	Clean modular architecture.
•	Complete engineering documentation.
•	Easy hardware replication.
•	High code readability.
•	Portability across AVR microcontrollers.
•	Future support for additional vintage synthesizers.
 
Version 1.0 Objectives
The first stable release implements:
•	MIDI Note On / Note Off
•	48-key Polivoks keyboard
•	Active LOW outputs
•	Six cascaded 74HC595 shift registers
•	Full polyphony
•	Arduino Uno reference platform
•	Modular software architecture
•	Complete documentation
Version 1.0 serves as the reference implementation for future development.
 
Software Architecture
             MIDI IN
                 │
                 ▼
          MidiParser
                 │
                 ▼
        KeyboardEngine
                 │
                 ▼
    ShiftRegisterDriver
                 │
                 ▼
          6 × 74HC595
                 │
                 ▼
      Polivoks Keyboard Contacts
Each software module has exactly one responsibility.
 
Development Principles
This project follows several engineering principles:
•	Documentation First
•	Architecture First
•	Reliability First
•	Readability First
•	Maintainability
•	Testability
•	Portability
•	Modular Design
Every non-trivial design decision should be documented before implementation.
 
Repository Structure
docs/
firmware/
hardware/
tests/
tools/
Documentation is considered part of the source code.
 
Roadmap
Version 1.0
Reference implementation for Polivoks.
Version 1.1
Minor improvements, diagnostics and maintenance features.
Version 2.0
Support for configurable keyboard profiles.
Version 3.x
Universal framework for vintage synthesizer MIDI interfaces.
 
License
License selection (MIT or GPLv3) will be finalized before the first public release.
 
Project Status
Current Stage
Engineering documentation and architecture design.
No implementation is accepted before documentation.
 
"First understand the system. Then write the code."

<img width="467" height="741" alt="image" src="https://github.com/user-attachments/assets/b4c9b3c3-cc44-407c-8829-12e70e71ad12" />

