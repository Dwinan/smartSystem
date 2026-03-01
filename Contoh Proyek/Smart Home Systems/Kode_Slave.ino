// --- KONFIGURASI PIN ---
#define LDR_PIN A0
#define MQ2_PIN A1
#define LED_PIN 7
#define BUZZER_PIN 8

// --- KONFIGURASI AMBANG BATAS (THRESHOLD) ---
// Sesuaikan nilai ini agar lampu menyala pada tingkat kegelapan yang diinginkan
// Nilai LDR: Semakin gelap, nilai analog semakin KECIL.
const int CAHAYA_THRESHOLD = 550; // Contoh: nyala jika nilai analog < 400

// Sesuaikan nilai ini sesuai sensitivitas sensor MQ-2 Anda
const int ASAP_THRESHOLD = ;   // Contoh: alarm jika nilai analog > 350

void setup() {
  Serial.begin(9600);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Pin Analog tidak perlu pinMode sebagai INPUT
  
  digitalWrite(LED_PIN, LOW);    // Pastikan LED mati
  digitalWrite(BUZZER_PIN, LOW); // Pastikan Buzzer mati
  
  Serial.println("Sistem Lingkungan Siap.");
}

void loop() {
  // Baca nilai dari semua sensor
  int nilaiCahaya = analogRead(LDR_PIN);
  int nilaiAsap = analogRead(MQ2_PIN);

  // Kirim data ke Serial Monitor untuk debugging/kalibrasi
  Serial.print("Nilai LDR: ");
  Serial.print(nilaiCahaya);
  Serial.print(" | Nilai MQ2: ");
  Serial.println(nilaiAsap);

  // Panggil fungsi kontrol
  kontrolLampuTaman(nilaiCahaya);
  kontrolAlarmAsap(nilaiAsap);
  
  delay(500); // Cek sensor setiap setengah detik
}

// Fungsi ini mengontrol lampu taman berdasarkan LDR
void kontrolLampuTaman(int cahaya) {
  // Jika nilai sensor cahaya di bawah ambang batas (gelap)
  if (cahaya > CAHAYA_THRESHOLD) {  
    digitalWrite(LED_PIN, HIGH); // Nyalakan lampu
  } else {
    digitalWrite(LED_PIN, LOW); // Matikan lampu
  }
}

// Fungsi ini mengontrol buzzer berdasarkan MQ-2
void kontrolAlarmAsap(int asap) {
  // Jika nilai sensor asap di atas ambang batas (ada asap/gas)
  if (asap > ASAP_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH); // Nyalakan buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Matikan buzzer
  }
}