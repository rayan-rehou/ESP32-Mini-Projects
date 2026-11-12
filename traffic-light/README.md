# Button-Controlled Traffic Light

Press **ON** and the LEDs light up in sequence: green, then yellow 5 seconds later, then red 2 seconds after that. Press **OFF** and all three turn off.

Demo video, photos of the real build and a clickable simulation: [rayan-rehou.netlify.app/#traffic](https://rayan-rehou.netlify.app/#traffic)

## Wiring

| Part | ESP32 pin | Connection |
|---|---|---|
| Green LED | GPIO 18 | through a resistor to GND |
| Yellow LED | GPIO 21 | through a resistor to GND |
| Red LED | GPIO 19 | through a resistor to GND |
| ON button | GPIO 22 | other side to GND |
| OFF button | GPIO 5 | other side to GND |

Both buttons use the ESP32's internal pull-up (`INPUT_PULLUP`): the pin reads HIGH at rest and LOW while the button is pressed.

## How it works

`loop()` keeps checking both buttons:

- **ON pressed:** green HIGH → `delay(5000)` → yellow HIGH → `delay(2000)` → red HIGH → `delay(7000)`
- **OFF pressed:** all three LEDs LOW

Notes:

- Each LED stays on when the next one lights up, so after the sequence all three are on until OFF is pressed.
- `delay()` blocks the loop, so the OFF button is only read once the sequence has finished.

## Run it

1. Open `Traffic_LIGHTS.ino` in the Arduino IDE.
2. Select the board **ESP32 Dev Module** and the right COM port.
3. Upload, then press ON.
