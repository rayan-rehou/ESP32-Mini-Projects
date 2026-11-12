#include <WiFi.h>
#include <WebServer.h>

// CHANGE THESE TWO VALUES
const char* homeSSID = "YOUR_WIFI_NAME";
const char* homePassword = "YOUR_WIFI_PASSWORD";

// Network created by the ESP32
const char* apSSID = "ESP32-Light";
const char* apPassword = "CHOOSE_A_PASSWORD"; // at least 8 characters

const int LED_PIN = 2;

WebServer server(80);

bool flashing = false;
bool lightOn = false;
unsigned long lastFlash = 0;
const unsigned long flashInterval = 500;

const char webpage[] = R"HTML(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>ESP32 Light</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
      background: #eef2f6;
      padding: 50px 15px;
    }
    button {
      padding: 16px 25px;
      margin: 10px;
      font-size: 20px;
      border: none;
      border-radius: 10px;
      color: white;
      cursor: pointer;
    }
    .on { background: #16803c; }
    .flash { background: #2563eb; }
    .off { background: #dc2626; }
  </style>
</head>
<body>
  <h1>ESP32 Light Control</h1>
  <p id="status">Choose an action</p>

  <button class="on" onclick="control('on')">Turn on</button>
  <button class="flash" onclick="control('flash')">Flash</button>
  <button class="off" onclick="control('off')">Turn off</button>

  <script>
    async function control(action) {
      try {
        const response = await fetch('/' + action, {
          method: 'POST'
        });

        if (!response.ok) throw new Error();

        document.getElementById('status').textContent =
          await response.text();
      } catch {
        document.getElementById('status').textContent =
          'Connection failed. Try again.';
      }
    }
  </script>
</body>
</html>
)HTML";

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Enable both STA and AP
  WiFi.mode(WIFI_AP_STA);

  // Create the ESP32 Wi-Fi network
  if (WiFi.softAP(apSSID, apPassword)) {
    Serial.print("ESP32 network: ");
    Serial.println(apSSID);

    Serial.print("AP website: http://");
    Serial.println(WiFi.softAPIP());
  } else {
    Serial.println("Failed to create ESP32 network.");
  }

  // Connect the ESP32 to your home Wi-Fi
  WiFi.setAutoReconnect(true);
  WiFi.begin(homeSSID, homePassword);

  Serial.print("Connecting to home Wi-Fi");

  unsigned long startTime = millis();

  while (WiFi.status() != WL_CONNECTED &&
         millis() - startTime < 20000) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Home Wi-Fi connected!");

    Serial.print("Home website: http://");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Could not connect to home Wi-Fi.");
    Serial.println("Check the Wi-Fi name and password.");
    Serial.println("You can still use ESP32-Light.");
  }

  // Main webpage
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html; charset=utf-8", webpage);
  });

  // Keep the LED on
  server.on("/on", HTTP_POST, []() {
    flashing = false;
    lightOn = true;
    digitalWrite(LED_PIN, HIGH);

    server.send(200, "text/plain", "Light is on");
  });

  // Start flashing
  server.on("/flash", HTTP_POST, []() {
    flashing = true;
    lightOn = true;
    digitalWrite(LED_PIN, HIGH);
    lastFlash = millis();

    server.send(200, "text/plain", "Light is flashing");
  });

  // Turn the LED off
  server.on("/off", HTTP_POST, []() {
    flashing = false;
    lightOn = false;
    digitalWrite(LED_PIN, LOW);

    server.send(200, "text/plain", "Light is off");
  });

  server.begin();
  Serial.println("Web server started.");
}

void loop() {
  server.handleClient();

  // Show the home IP after connecting or reconnecting
  static bool wasConnected = false;
  bool connected = (WiFi.status() == WL_CONNECTED);

  if (connected && !wasConnected) {
    Serial.print("Home Wi-Fi IP: http://");
    Serial.println(WiFi.localIP());
  }

  wasConnected = connected;

  // Flash without blocking the webpage
  if (flashing && millis() - lastFlash >= flashInterval) {
    lastFlash = millis();
    lightOn = !lightOn;
    digitalWrite(LED_PIN, lightOn ? HIGH : LOW);
  }
}
