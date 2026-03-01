const int soilMoisturePin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("Monitoring Sensor Kelembaban Tanah");
  Serial.println("----------------------------------");
}

void loop() {

  int moistureValue = analogRead(soilMoisturePin);

  Serial.print("Nilai sensor kelembaban: ");
  Serial.println(moistureValue);
 
  if (moistureValue > 700) {
    Serial.println("Status: Sangat Kering!");
  } else if (moistureValue > 400) {
    Serial.println("Status: Agak Kering.");
  } else if (moistureValue > 200) {
    Serial.println("Status: Lembab.");
  } else {
    Serial.println("Status: Sangat Basah!");
  }

  delay(2000);
}