const int Led_1 = 23;
const int Led_2 = 22;
const int Led_3 = 21;
const int Led_4 = 19;
const int Led_5 = 18;
const int Led_6 = 5;
const int Led_7 = 17; // TX2
const int Led_8 = 16; // RX2

const int Button_1 = 2;
const int Button_2 = 4;
const int Button_3 = 15;

int mode = 0;

void setup() {
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  pinMode(Led_4, OUTPUT);
  pinMode(Led_5, OUTPUT);
  pinMode(Led_6, OUTPUT);
  pinMode(Led_7, OUTPUT);
  pinMode(Led_8, OUTPUT);

  pinMode(Button_1, INPUT_PULLDOWN);
  pinMode(Button_2, INPUT_PULLDOWN);
  pinMode(Button_3, INPUT_PULLDOWN);

  Serial.begin(115200);
}

void loop() {

  // NEW: listen to the PC
  if (Serial.available() > 0) {          // did a message arrive?
    char c = Serial.read();              // read it
    if (c == '1') mode = 1;
    if (c == '2') mode = 2;
    if (c == '0') mode = 0;
  }

  if (digitalRead(Button_1) == HIGH) {
    mode = 1;
  }

  if (mode == 1) {
    digitalWrite(Led_1, HIGH);
    delay(100);
    digitalWrite(Led_1, LOW);

    digitalWrite(Led_2, HIGH);
    delay(100);
    digitalWrite(Led_2, LOW);

    digitalWrite(Led_3, HIGH);
    delay(100);
    digitalWrite(Led_3, LOW);

    digitalWrite(Led_4, HIGH);
    delay(100);
    digitalWrite(Led_4, LOW);

    digitalWrite(Led_5, HIGH);
    delay(100);
    digitalWrite(Led_5, LOW);

    digitalWrite(Led_6, HIGH);
    delay(100);
    digitalWrite(Led_6, LOW);

    digitalWrite(Led_7, HIGH);
    delay(100);
    digitalWrite(Led_7, LOW);

    digitalWrite(Led_8, HIGH);
    delay(100);
    digitalWrite(Led_8, LOW);

    digitalWrite(Led_7, HIGH);
    delay(100);
    digitalWrite(Led_7, LOW);

    digitalWrite(Led_6, HIGH);
    delay(100);
    digitalWrite(Led_6, LOW);

    digitalWrite(Led_5, HIGH);
    delay(100);
    digitalWrite(Led_5, LOW);

    digitalWrite(Led_4, HIGH);
    delay(100);
    digitalWrite(Led_4, LOW);

    digitalWrite(Led_3, HIGH);
    delay(100);
    digitalWrite(Led_3, LOW);

    digitalWrite(Led_2, HIGH);
    delay(100);
    digitalWrite(Led_2, LOW);
  }

  if (digitalRead(Button_2) == HIGH) {
    mode = 2;
  }

  if (mode == 2) {
    digitalWrite(Led_1, HIGH);
    digitalWrite(Led_8, HIGH);
    delay(100);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_8, LOW);

    digitalWrite(Led_2, HIGH);
    digitalWrite(Led_7, HIGH);
    delay(100);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_7, LOW);

    digitalWrite(Led_3, HIGH);
    digitalWrite(Led_6, HIGH);
    delay(100);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_6, LOW);

    digitalWrite(Led_4, HIGH);
    digitalWrite(Led_5, HIGH);
    delay(100);
    digitalWrite(Led_4, LOW);
    digitalWrite(Led_5, LOW);

    digitalWrite(Led_3, HIGH);
    digitalWrite(Led_6, HIGH);
    delay(100);
    digitalWrite(Led_3, LOW);
    digitalWrite(Led_6, LOW);

    digitalWrite(Led_2, HIGH);
    digitalWrite(Led_7, HIGH);
    delay(100);
    digitalWrite(Led_2, LOW);
    digitalWrite(Led_7, LOW);

    digitalWrite(Led_1, HIGH);
    digitalWrite(Led_8, HIGH);
    delay(100);
    digitalWrite(Led_1, LOW);
    digitalWrite(Led_8, LOW);
  }

  if (digitalRead(Button_3) == HIGH) {
    mode = 0;
  }
}
