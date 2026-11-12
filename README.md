# ESP32 Mini Projects

Two small ESP32 projects I built and tested on a real breadboard with a teammate (2026), programmed in C++ with the Arduino framework.

| Project | What it does | Demo |
|---|---|---|
| [Button-Controlled Traffic Light](traffic-light/) | Push buttons start and stop a green → yellow → red LED sequence | [Watch and try it](https://rayan-rehou.netlify.app/#traffic) |
| [Wi-Fi LED Controller](wifi-led-controller/) | The ESP32 hosts a web page, and a phone turns an LED on, makes it flash, or turns it off | [Watch and try it](https://rayan-rehou.netlify.app/#wifi) |

## Hardware

- ESP32 DevKit (board: **ESP32 Dev Module** in the Arduino IDE)
- Breadboard and jumper wires
- LEDs with current-limiting resistors
- Push buttons (traffic light)

## What I practiced

- Digital outputs (LEDs) and inputs (buttons with `INPUT_PULLUP`)
- Timing a sequence with `delay()`
- Wi-Fi on the ESP32: creating an access point and serving a web page on port 80

These are the first steps toward my **Smart Temperature Monitor**, which reads a DHT22 sensor and sends its readings online.

Portfolio: [rayan-rehou.netlify.app](https://rayan-rehou.netlify.app)
