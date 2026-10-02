  #include <DHT.h>

  #define DHTPIN 23
  #define DHTTYPE 11

  DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  float H = dht.readHumidity();
  float T = dht.readTemperature();

  String dhtData = String(H) + "," + String(T);

  Serial.println (dhtData);
  delay(1500);
}
