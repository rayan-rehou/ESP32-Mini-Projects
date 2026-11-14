# Multi-Mode LED Animation

8 LEDs in a row on a breadboard, driven by an ESP32, with two light animations. Each mode can be chosen with a push button or from a computer over USB.

![Multi-Mode LED Animation running on the real board](https://rayan-rehou.netlify.app/led-animation-demo.gif)

▶ [Watch the full videos and try the simulation](https://rayan-rehou.netlify.app/#led)

## Modes

| Mode | Button | Serial command | What the LEDs do |
|---|---|---|---|
| 1. Chase | Button 1 (GPIO 2) | `1` | One LED at a time runs from LED 1 to LED 8 and back, like a scanner |
| 2. Mirror | Button 2 (GPIO 4) | `2` | LEDs light in pairs from both ends to the middle (1+8, 2+7, 3+6, 4+5) and back out |
| Off | Button 3 (GPIO 15) | `0` | Stops the animation |

Each step lasts 100 ms. The selected mode keeps repeating until another one is chosen.

## Controlling it from a computer

Open the Serial Monitor in the Arduino IDE at **115200 baud** and send `1`, `2` or `0`.

## Wiring

| Part | ESP32 pin |
|---|---|
| LED 1 to LED 8 (each with a resistor) | GPIO 23, 22, 21, 19, 18, 5, 17, 16 |
| Button 1 / 2 / 3 | GPIO 2 / 4 / 15 |

The buttons use the ESP32's internal pull-down resistors (`INPUT_PULLDOWN`), so each one connects its pin to 3.3 V when pressed.

The LEDs are blue, green, red and yellow, repeated twice along the row.

## Code

[`Multi_Mode_LED_Animation.ino`](Multi_Mode_LED_Animation.ino), written in C++ with the Arduino framework.
