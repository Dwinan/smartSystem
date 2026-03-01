#define MQ_SENSOR_PIN A0   
#define LED_PIN D5         

const int AMBANG_GAS = 50; 

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("Sensor MQ Siap (Analog Mode)");
}

void loop() {
  int nilaiGas = analogRead(MQ_SENSOR_PIN); 
  Serial.print("Nilai Gas: ");
  Serial.println(nilaiGas);

  if (nilaiGas > AMBANG_GAS) {
    Serial.println("🚨 Gas Melebihi Ambang!");
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.println("✅ Gas Normal.");
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);
}