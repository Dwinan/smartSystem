#include <Servo.h>
#include <DHT.h>

// === PIN DEFINISI ===
#define LDR_PIN A0
#define PIR_PIN 6
#define MQ_PIN A3
#define DHT_PIN 8
#define DHT_TYPE DHT22

#define LED_MERAH 2
#define LED_KUNING 4
#define RELAY_PIN 13
#define SERVO_PIN 3

// === OBJEK DAN VARIABEL ===
Servo myServo;
DHT dht(DHT_PIN, DHT_TYPE);

void setup()
{
    Serial.begin(9600);

    pinMode(LDR_PIN, INPUT);
    pinMode(PIR_PIN, INPUT);
    pinMode(MQ_PIN, INPUT);

    pinMode(LED_MERAH, OUTPUT);
    pinMode(LED_KUNING, OUTPUT);
    pinMode(RELAY_PIN, OUTPUT);

    myServo.attach(SERVO_PIN);
    myServo.write(0); // posisi awal

    dht.begin();

    Serial.println("Smart Home System Siap...");
}

void loop()
{
    // === BACA SENSOR ===
    int ldrValue = analogRead(LDR_PIN);    // 0 - 1023
    int mqValue = analogRead(MQ_PIN);      // 0 - 1023
    bool pirStatus = digitalRead(PIR_PIN); // HIGH jika deteksi gerakan

    float suhu = dht.readTemperature();    // Celcius
    float kelembaban = dht.readHumidity(); // %

    // === OUTPUT BERDASARKAN SENSOR ===
    // LDR - LED Merah (Nyala saat gelap)
    if (ldrValue < 500)
    {
        digitalWrite(LED_MERAH, HIGH);
    }
    else
    {
        digitalWrite(LED_MERAH, LOW);
    }

    // PIR - Relay (Aktif saat gerakan terdeteksi)
    if (pirStatus == HIGH)
    {
        digitalWrite(RELAY_PIN, HIGH); // Aktifkan relay
    }
    else
    {
        digitalWrite(RELAY_PIN, LOW); // Matikan relay
    }

    // MQ - Servo (Gerak saat gas terdeteksi)
    if (mqValue > 400)
    {
        myServo.write(90); // gerakkan servo
    }
    else
    {
        myServo.write(0); // kembali ke posisi awal
    }

    // DHT22 - LED Kuning (Nyala saat suhu > 30 derajat)
    if (suhu > 30)
    {
        digitalWrite(LED_KUNING, HIGH);
    }
    else
    {
        digitalWrite(LED_KUNING, LOW);
    }

    // === TAMPILKAN DI SERIAL MONITOR ===
    Serial.println("===== DATA SENSOR =====");
    Serial.print("LDR (Cahaya): ");
    Serial.println(ldrValue);
    Serial.print("PIR (Gerakan): ");
    Serial.println(pirStatus ? "TERDETEKSI" : "TIDAK");
    Serial.print("MQ (Gas): ");
    Serial.println(mqValue);
    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.println(" °C");
    Serial.print("Kelembaban: ");
    Serial.print(kelembaban);
    Serial.println(" %");
    Serial.println("========================\n");

    delay(1000); // Delay 1 detik
}