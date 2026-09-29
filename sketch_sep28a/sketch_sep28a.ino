#define BUTTON 18
#define LED_PIN 19

const unsigned long LED_ON_TIME = 1000;

bool ledState = false;
bool lastButtonState = HIGH;
bool currentButtonState;
unsigned long lastStartTime =0;

void setup() {

  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("Lab 3 : Toggle LED + Auto Off");
}

void loop() {

  currentButtonState = digitalRead(BUTTON);

  // ตรวจจับขอบขาลง Released -> Pressed
  if (lastButtonState == HIGH && currentButtonState == LOW) {

    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);

    if (ledState) {
      lastStartTime = millis();           // บันทึกเวลาที่เปิดไฟ
      Serial.println("LED ON");
    } else {
      Serial.println("LED OFF (manual)");
    }
    delay(200);                          // debounce แบบง่าย
  }
  lastButtonState = currentButtonState;

  if (ledState && (millis() - lastStartTime >= LED_ON_TIME)) {
    ledState = false;
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED Off (auto)");
  }
}