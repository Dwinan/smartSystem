#define VIBRATION_PIN D2    

void setup() {
  Serial.begin(9600);          
  pinMode(VIBRATION_PIN, INPUT); 

  Serial.println("Sensor Getar SW-420 Siap");
}

void loop() {
  int statusGetar = digitalRead(VIBRATION_PIN); 

  if (statusGetar == HIGH) {
    Serial.println("Getaran Terdeteksi!");
  } else {
    Serial.println("Tidak ada getaran.");
  }

  delay(200); 
}