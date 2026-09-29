int BUTTON = 19;
int Counter = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int BUTTON_State = digitalRead(BUTTON);
  Serial.println(Counter);
  if (BUTTON_State == 0){
    Counter = Counter+1;
    delay(1000);
  }
}
