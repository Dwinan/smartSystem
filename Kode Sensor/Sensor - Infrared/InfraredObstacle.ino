#define INFRARED_PIN D2  
#define LED_PIN D5        

void setup() {
  Serial.begin(9600);
  pinMode(INFRARED_PIN, INPUT);  
  pinMode(LED_PIN, OUTPUT);      
  digitalWrite(LED_PIN, LOW);    

  Serial.println("Sensor Infrared Barrier Siap.");
}

void loop() {
  int deteksiHalangan = digitalRead(INFRARED_PIN);  

  if (deteksiHalangan == LOW) {
    Serial.println("🚧 Halangan Terdeteksi!");
    digitalWrite(LED_PIN, HIGH); 
  } else {
    Serial.println("✅ Tidak ada halangan.");
    digitalWrite(LED_PIN, LOW);  
  }

  delay(1000); 
}