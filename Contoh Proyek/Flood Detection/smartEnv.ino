#define RAIN_SENSOR 34
#define WATER_SENSOR 35

#define LED_PIN 26
#define BUZZER_PIN 25

void setup() {
  Serial.begin(115200);

  pinMode(RAIN_SENSOR, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("=== SISTEM DETEKSI BANJIR ===");
}

void loop() {

  int rainValue = digitalRead(RAIN_SENSOR);
  int waterValue = analogRead(WATER_SENSOR);

  bool ledStatus = false;

  // ===== RAIN DROP =====
  if (rainValue == LOW) {
    Serial.println("STATUS CUACA : HUJAN");
    ledStatus = true;
  } else {
    Serial.println("STATUS CUACA : TIDAK HUJAN");
  }

  // ===== WATER LEVEL =====
  Serial.print("Nilai Water Level : ");
  Serial.println(waterValue);

  if (waterValue >= 2400) {

    Serial.println("!!! BAHAYA TINGGI (100%) !!!");

    digitalWrite(BUZZER_PIN, HIGH);
    ledStatus = true;

  }
  else if (waterValue >= 2300) {

    Serial.println("!!! BAHAYA BANJIR (75%) !!!");

    digitalWrite(BUZZER_PIN, HIGH);
    ledStatus = true;

  }
  else if (waterValue >= 2200) {

    Serial.println("!!! WASPADA BANJIR (50%) !!!");

    digitalWrite(BUZZER_PIN, HIGH);
    ledStatus = true;

  }
  else {

    Serial.println("AMAN");

    digitalWrite(BUZZER_PIN, LOW);

  }

  // ===== LED =====
  digitalWrite(LED_PIN, ledStatus);

  Serial.println("----------------------");

  delay(1000);
}