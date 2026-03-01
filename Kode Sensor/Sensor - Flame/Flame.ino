#define FLAME_SENSOR_PIN D2  

void setup() {
  Serial.begin(9600);
  pinMode(FLAME_SENSOR_PIN, INPUT); 

  Serial.println("Sensor Api Siap Digunakan");
}

void loop() {
  int statusApi = digitalRead(FLAME_SENSOR_PIN); 

  if (statusApi == LOW) {
    Serial.println("Api terdeteksi!");
  } else {
    Serial.println("Tidak ada api.");
  }

  delay(500); 
}