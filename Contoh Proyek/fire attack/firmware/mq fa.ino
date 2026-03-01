// Definisi pin yang digunakan pada Arduino
const int MQ_SENSOR_AO_PIN = A0; // Pin Analog Output (AO) sensor MQ terhubung ke pin A0
const int BUZZER_PWM_PIN = 9;    // Buzzer (aktif/pasif) terhubung ke pin digital D9 (pin PWM)
const int RELAY_CONTROL_PIN = 7; // Pin digital D7 untuk mengontrol input modul relay

// Definisi frekuensi nada untuk alarm (dalam Hertz)
const int ALARM_TONE_FREQ = 1200; // Nada 1.2 KHz (suara alarm yang khas)

// Ambang batas (threshold) untuk deteksi gas dari sensor MQ (pin AO).
// PENTING: Nilai ini HARUS DIKALIBRASI DI PERANGKAT FISIK Anda.
// Semakin TINGGI konsentrasi gas, nilai AO dari sensor MQ akan semakin TINGGI.
// Maka, kita akan mencari nilai MINIMUM yang mengindikasikan adanya gas berbahaya.
const int MQ_THRESHOLD = 400; // <<< HARUS DIKALIBRASI DI PERANGKAT FISIK >>>
                              // Nilai ini sangat bervariasi tergantung jenis gas, jarak, dan sensitivitas sensor.
                              // Umumnya berkisar antara 200-700.

void setup()
{
    // Memulai komunikasi serial untuk debugging dan pemantauan (penting saat kalibrasi fisik)
    Serial.begin(9600);

    // Mengatur pin kontrol relay sebagai output
    pinMode(RELAY_CONTROL_PIN, OUTPUT);

    // Memastikan relay non-aktif di awal
    // Asumsi relay aktif LOW (HIGH = non-aktif)
    digitalWrite(RELAY_CONTROL_PIN, HIGH); // Atur HIGH jika relay Anda aktif LOW (untuk non-aktif)

    Serial.println("----------------------------------");
    Serial.println("Sistem Pencegah Kebakaran Aktif!");
    Serial.println("Siap Menerima Data Sensor Gas MQ (AO)");
    Serial.println("----------------------------------");
}

void loop()
{
    // Membaca nilai analog dari pin Analog Output (AO) sensor MQ.
    int mqValue = analogRead(MQ_SENSOR_AO_PIN);

    // Menampilkan nilai gas ke Serial Monitor
    Serial.print("Nilai Gas MQ (AO): ");
    Serial.println(mqValue);

    // Logika deteksi gas
    if (mqValue > MQ_THRESHOLD)
    {
        // Aktifkan buzzer
        tone(BUZZER_PWM_PIN, ALARM_TONE_FREQ);
        delay(400);
        noTone(BUZZER_PWM_PIN);
        delay(300);

        // Aktifkan relay (asumsi aktif LOW)
        digitalWrite(RELAY_CONTROL_PIN, LOW); // Relay aktif -> LED menyala

        Serial.println("!!!! ALARM KEBAKARAN AKTIF: KONSENTRASI GAS BERBAHAYA TERDETEKSI !!!!");
        Serial.println(">>> Relay AKTIF: Mensimulasikan Perangkat Eksternal (LED Menyala) <<<");
    }
    else
    {
        // Jika tidak ada bahaya, pastikan buzzer dan relay mati
        noTone(BUZZER_PWM_PIN);
        digitalWrite(RELAY_CONTROL_PIN, HIGH); // Non-aktifkan relay (asumsi aktif LOW) -> LED mati

        // Serial.println("Konsentrasi Gas Normal"); // Bisa di-komen untuk mengurangi output di Serial Monitor
    }

    delay(100);
}