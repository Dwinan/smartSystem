#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// --- KONFIGURASI PIN ---
#define SS_PIN 10
#define RST_PIN 9
#define IR_PIN 2
#define SERVO_PALANG_PIN 5

// --- KONFIGURASI LAINNYA ---
const long EXIT_TRIGGER_TIME = 1000; // Waktu mobil harus berhenti di IR untuk keluar (ms)

// --- INISIALISASI PERANGKAT ---
MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo servoPalang;

// --- VARIABEL STATUS ---
byte rfidStatus = 0; // 0=Idle, 1=Gagal, 2=Berhasil
byte irStatus = HIGH; // Menyimpan status sensor IR
bool palangTerbuka = false;
bool objekPernahLewat = false;
unsigned long waktuIRTertutup = 0;
bool sedangMenungguKeluar = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  pinMode(IR_PIN, INPUT_PULLUP); // Menggunakan internal pull-up untuk stabilitas
  
  servoPalang.attach(SERVO_PALANG_PIN);
  servoPalang.write(90); // Pastikan palang tertutup saat mulai

  Serial.println("Sistem Palang Parkir Siap.");
}

void loop() {
  bacaSensor();
  kontrolPalang();
  delay(3000);
}

void bacaSensor() {
  // 1. Baca RFID
  rfidStatus = 0; // Reset status setiap loop
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uid.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      uid.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    uid.toUpperCase();
    
    // GANTI DENGAN UID KARTU ANDA
    if (uid.substring(1) == "99 5A A3 04") { 
      rfidStatus = 2; // Berhasil
      Serial.println("Kartu Diterima!");
    } else {
      rfidStatus = 1; // Gagal
      Serial.println("Kartu Ditolak!");
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }

  // 2. Baca Sensor IR
  irStatus = digitalRead(IR_PIN);
}

void kontrolPalang() {
  // --- LOGIKA MEMBUKA PALANG ---
  // A. Buka karena RFID (Masuk)
  if (rfidStatus == 2 && !palangTerbuka) {
    bukaPalang();
  } 
  
  // B. Buka karena ada mobil mau keluar
  // Jika palang tertutup dan ada objek menghalangi IR
  if (!palangTerbuka && irStatus == LOW) {
    if (!sedangMenungguKeluar) {
      sedangMenungguKeluar = true;
      waktuIRTertutup = millis();
    }
    // Jika objek sudah menghalangi selama lebih dari EXIT_TRIGGER_TIME
    if (millis() - waktuIRTertutup > EXIT_TRIGGER_TIME) {
      bukaPalang();
      Serial.println("Membuka palang untuk mobil keluar...");
    }
  } else {
    // Reset jika tidak ada objek yang menghalangi
    sedangMenungguKeluar = false;
  }

  // --- LOGIKA MENUTUP PALANG ---
  // Jika palang terbuka dan ada objek yang lewat (IR terhalang)
  if (palangTerbuka && irStatus == LOW) {
    objekPernahLewat = true;
  }
  
  // Jika palang terbuka, objek sudah pernah lewat, dan sekarang IR tidak terhalang lagi
  if (palangTerbuka && objekPernahLewat && irStatus == HIGH) {
    tutupPalang();
  }
}

void bukaPalang() {
  Serial.println("Palang Terbuka");
  palangTerbuka = true;
  objekPernahLewat = false; // Reset status lewat
  servoPalang.write(180);
}

void tutupPalang() {
  Serial.println("Palang Tertutup");
  palangTerbuka = false;
  servoPalang.write(90);
}