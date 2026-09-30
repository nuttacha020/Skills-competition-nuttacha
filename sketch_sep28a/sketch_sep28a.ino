#define BUTTON 23
#define LED 22

bool ledState = false;
bool lastButtonState = HIGH;
bool currentButtonState;

void setup() {

  Serial.begin(115200);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

}

void loop() {
  currentButtonState = digitalRead(BUTTON);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    ledState = !ledState;
    digitalWrite(LED, ledState);
  
  if (ledState == true) {
    Serial.println("LED ON");
  }
  else {
    Serial.println("LED OFF");
  }

  delay(50);
  }
  lastButtonState = currentButtonState;
}