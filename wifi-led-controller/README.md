# Wi-Fi LED Controller

The ESP32 runs a web server so an LED can be controlled from a phone.

On startup the board creates its own Wi-Fi network, **ESP32-Light**, and also tries to join a home network. A phone connected to ESP32-Light opens **http://192.168.4.1** and gets a page called **"ESP32 Light Control"** with three buttons:

- **Turn on:** LED on
- **Flash:** LED blinks on a timer
- **Turn off:** LED off

Each tap sends an HTTP request to the ESP32 (web server on port 80), which sets GPIO 2 and replies with a short status such as "Light is off".

Demo video filmed on the real board, plus a recreation of the page: [rayan-rehou.netlify.app/#wifi](https://rayan-rehou.netlify.app/#wifi)

## Serial Monitor output

```
ESP32 network: ESP32-Light
AP website: http://192.168.4.1
Connecting to home Wi-Fi.......
Could not connect to home Wi-Fi.
Check the Wi-Fi name and password.
You can still use ESP32-Light.
Web server started.
```

## Hardware

- ESP32 DevKit
- LED and resistor on GPIO 2

## Code

[`WiFi_LED_Controller.ino`](WiFi_LED_Controller.ino) (Arduino framework, uses the built-in `WiFi` and `WebServer` libraries).

Before uploading, set these values at the top of the sketch:

- `homeSSID` / `homePassword`: your home Wi-Fi (optional; the ESP32-Light network works without it)
- `apPassword`: password for the ESP32-Light network (at least 8 characters)

The flashing runs in `loop()` with `millis()` instead of `delay()`, so the web page stays responsive while the LED blinks.
