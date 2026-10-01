int BUTTON = 23;
int LED = 22;
int Counter = 0;
bool ledState = false;
int lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  int buttonState = digitalRead(BUTTON);

  if (lastButtonState == HIGH && buttonState == LOW) {  // เพิ่งกด
    Counter = Counter + 1;
    ledState = !ledState;
    digitalWrite(LED, ledState);

    Serial.println(Counter);

    delay(50);  // debounce
  }

  lastButtonState = buttonState;
}