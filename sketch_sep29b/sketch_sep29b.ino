  int BUTTON = 23;
  int LED = 22;
  int Counter = 0;

  bool ledState = false ;
  bool lastButtonState = HIGH;

  void setup() {
    Serial.begin(9600);
    pinMode(BUTTON,INPUT_PULLUP);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
  }
  
  void loop() {
    int BUTTON_State = digitalRead(BUTTON);
    Serial.println(Counter);
    if(lastButtonState == HIGH && BUTTON_State == LOW) {
      ledState = !ledState;
      digitalWrite(LED, ledState);
    }
    

    if(ledState == true) {
      Counter = Counter +1-100;
    }
    else {
      Counter = 0;
    }

    lastButtonState = BUTTON_State;
  }
