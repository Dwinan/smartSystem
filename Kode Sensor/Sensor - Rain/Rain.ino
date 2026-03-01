#define RAIN_SENSOR_PIN D6   
#define LED_PIN D5           

void setup() {
  Serial.begin(9600);
  pinMode(RAIN_SENSOR_PIN, INPUT);  
  pinMode(LED_PIN, OUTPUT);         
  digitalWrite(LED_PIN, LOW);       

  Serial.println("Sensor Hujan Siap Digunakan");
}

void loop() {
  int statusHujan = digitalRead(RAIN_SENSOR_PIN); 

  if (statusHujan == LOW) {
    Serial.println("💧 Hujan Terdeteksi!");
    digitalWrite(LED_PIN, HIGH); 
  } else {
    Serial.println("🌤️ Tidak Ada Hujan.");
    digitalWrite(LED_PIN, LOW);  
  }

  delay(500); 
}