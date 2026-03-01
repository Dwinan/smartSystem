#include <DHT.h>
#include <Servo.h>

// =======================
// Konfigurasi Pin
// =======================
#define DHTPIN 2
#define DHTTYPE DHT11

#define GAS_PIN A0
#define LED_PIN 7
#define SERVO_PIN 9

// =======================
// Objek
// =======================
DHT dht(DHTPIN, DHTTYPE);
Servo ventilasi;

// =======================
// Variabel
// =======================
float suhu;
float kelembaban;
int gasValue;

// Ambang batas
const float BATAS_SUHU_DINGIN = 15.0;
const int BATAS_GAS = 500;

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

  dht.begin();

  ventilasi.attach(SERVO_PIN);
  ventilasi.write(0);

  Serial.println("=== SMART FARMING SYSTEM ===");
}

void loop() {

  // Membaca DHT11
  suhu = dht.readTemperature();
  kelembaban = dht.readHumidity();

  // Membaca sensor gas
  gasValue = analogRead(GAS_PIN);

  // Cek pembacaan sensor
  if (isnan(suhu) || isnan(kelembaban)) {
    Serial.println("Gagal membaca DHT11!");
    delay(2000);
    return;
  }

  // ======================
  // Menampilkan Data
  // ======================
  Serial.println("--------------------");

  Serial.print("Suhu       : ");
  Serial.print(suhu);
  Serial.println(" C");

  Serial.print("Kelembaban : ");
  Serial.print(kelembaban);
  Serial.println(" %");

  Serial.print("Gas        : ");
  Serial.println(gasValue);

  // ======================
  // DHT11 Mengontrol LED
  // ======================
  if (suhu < BATAS_SUHU_DINGIN) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON (Suhu Dingin)");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");
  }

  // ======================
  // Sensor Gas Mengontrol Servo
  // ======================
  if (gasValue > BATAS_GAS) {
    ventilasi.write(90);
    Serial.println("Ventilasi TERBUKA");
  } else {
    ventilasi.write(0);
    Serial.println("Ventilasi TERTUTUP");
  }

  delay(2000);
}