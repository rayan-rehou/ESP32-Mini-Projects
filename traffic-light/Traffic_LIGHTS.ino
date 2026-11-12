const int LED_Yellow = 21;
const int LED_Red = 19;
const int LED_Green = 18;
const int Button_ON = 22;
const int Button_OFF = 5;

void setup() {
  pinMode(21, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(Button_ON, INPUT_PULLUP);
  pinMode(Button_OFF, INPUT_PULLUP);

}
void loop() {
  if (digitalRead(Button_ON) == LOW) {
    digitalWrite(LED_Green, HIGH);
    delay(5000);
    digitalWrite(LED_Yellow, HIGH);
    delay(2000);
    digitalWrite(LED_Red, HIGH);
    delay(7000);
  }
  if (digitalRead(Button_OFF) == LOW) {
    digitalWrite(LED_Green, LOW);
    digitalWrite(LED_Yellow, LOW);
    digitalWrite(LED_Red, LOW);
  }
}
