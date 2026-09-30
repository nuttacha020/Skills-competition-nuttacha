int BUTTON = 23;
int Counter = 0;
int LED = 22;

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
  Serial.println(Counter);
  if (button_State == 0){
    Counter = Counter+1;
    delay(50);
  }

  if (button_State){
  digitalWrite(LED, HIGH); 

  }
  if (Counter){
  digitalWrite(LED, LOW);
  }

}
