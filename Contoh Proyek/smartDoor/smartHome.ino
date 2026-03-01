#define BLYNK_TEMPLATE_ID "TMPL6Z5t5MYo-"
#define BLYNK_TEMPLATE_NAME "UAP Embedded"
#define BLYNK_AUTH_TOKEN "Osq8xPc94LlxsZXfPT_AlhwWKVUQ-FMr"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Kredensial WiFi
char ssid[] = "NANNAN";
char pass[] = "bayarrrr";

// Deklarasi Pin
#define LDR_PIN A0
#define TRIG_PIN D1
#define ECHO_PIN D2
#define LED_PIN D5
#define SERVO_PIN D6

Servo pintuServo;
BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  
  // Setup Pin Mode
  pinMode(LDR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  pintuServo.attach(SERVO_PIN);
  pintuServo.write(0); // Posisi awal pintu tertutup (0 derajat)

  // Mulai koneksi Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Atur timer agar membaca sensor setiap 1 detik
  timer.setInterval(1000L, bacaSensor);
}

void bacaSensor() {
  // ----------------------------------------------------
  // 1. Logika Sensor LDR & LED (Lampu Pintar)
  // ----------------------------------------------------
  int nilaiCahaya = analogRead(LDR_PIN);
  Blynk.virtualWrite(V1, nilaiCahaya); // Kirim data cahaya ke Blynk
  
  // Asumsi: Nilai semakin besar jika semakin gelap (tergantung modul)
  // Sesuaikan nilai '500' dengan sensitivitas ruangan aslimu
  if (nilaiCahaya > 500) { 
    digitalWrite(LED_PIN, HIGH); // Nyalakan lampu
  } else {
    digitalWrite(LED_PIN, LOW);  // Matikan lampu
  }

  // ----------------------------------------------------
  // 2. Logika Sensor Ultrasonic & Servo (Pintu Pintar)
  // ----------------------------------------------------
  long duration;
  int distance;

  // Tembakkan sinyal ultrasonic
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Hitung waktu pantulan
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // Konversi ke cm
  
  Blynk.virtualWrite(V2, distance); // Kirim data jarak ke Blynk

  // Jika jarak kurang dari 15 cm, buka pintu
  if (distance > 0 && distance < 15) {
    pintuServo.write(90); // Pintu buka
  } else {
    pintuServo.write(0);  // Pintu tutup
  }

  // Tampilkan di Serial Monitor untuk debugging
  Serial.print("Cahaya: "); Serial.print(nilaiCahaya);
  Serial.print(" | Jarak: "); Serial.print(distance); Serial.println(" cm");
}

void loop() {
  Blynk.run();
  timer.run();
}