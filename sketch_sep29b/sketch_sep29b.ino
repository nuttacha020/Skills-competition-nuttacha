int BUTTON = 23;
int Counter = 0;
int LED = 22;

bool ledState = false; //ประกาศตัวแปร เริ่มต้น = ดับ
bool lastButtonState = HIGH; //สถานะค่าปุ่มรอบที่แล้ว
bool currentButtonState; //เก็บสถานะปุ่มเมื่อรอบที่แล้ว

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button_State = digitalRead(BUTTON);

  if (lastButtonState == HIGH && currantButton  == LOW) {
    Counter = Counter +1;
    ledState = !ledState;
    digitalWrite(LED, ledState);

    Serial.println(Counter);

    delay(50);
  }
  lastButtonState = currentButtonState;
}
