# ESP32 Mini Projects

Small ESP32 projects I built and tested on a real breadboard (2026), programmed in C++ with the Arduino framework.

![Multi-Mode LED Animation running on the real board](https://rayan-rehou.netlify.app/led-animation-demo.gif?v=2)

| Project | What it does | Demo |
|---|---|---|
| [Multi-Mode LED Animation](multi-mode-led-animation/) | 8 LEDs with two light animations, chosen with 3 push buttons or from a computer over USB serial | [Watch and try it](https://rayan-rehou.netlify.app/#led) |
| [Wi-Fi LED Controller](wifi-led-controller/) | The ESP32 hosts a web page, and a phone turns an LED on, makes it flash, or turns it off | [Watch and try it](https://rayan-rehou.netlify.app/#wifi) |
| [Button-Controlled Traffic Light](traffic-light/) | Push buttons start and stop a green → yellow → red LED sequence | [Watch and try it](https://rayan-rehou.netlify.app/#traffic) |

## Hardware

- ESP32 DevKit (board: **ESP32 Dev Module** in the Arduino IDE)
- Breadboard and jumper wires
- LEDs with current-limiting resistors
- Push buttons

## What I practiced

- Digital outputs (LEDs) and inputs (buttons with `INPUT_PULLUP` and `INPUT_PULLDOWN`)
- Timing sequences with `delay()` and, for the Wi-Fi controller, non-blocking timing with `millis()`
- Receiving commands from a computer over USB serial
- Wi-Fi on the ESP32: creating an access point and serving a web page on port 80

These are the building blocks for my **Smart Temperature Monitor**, which reads a DHT22 sensor and sends its readings online.

Portfolio: [rayan-rehou.netlify.app](https://rayan-rehou.netlify.app)
