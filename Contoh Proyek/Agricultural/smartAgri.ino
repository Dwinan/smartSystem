#include <DHT.h>
#include <Servo.h>

#define DHTPIN 4
#define DHTTYPE DHT11

#define TRIG_PIN 10
#define ECHO_PIN 9

#define LED_PIN 6
#define SERVO_PIN A3

DHT dht(DHTPIN, DHTTYPE);
Servo feederServo;

const float suhuMinimum = 33.0; // suhu kandang minimum

const int batasPakan = 15;      // cm
bool sedangMemberiPakan = false;

unsigned long lastFeedTime = 0;
const unsigned long feedCooldown = 10000; // 10 detik

float bacaJarak()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.034 / 2;

  return distance;
}

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  dht.begin();

  feederServo.attach(SERVO_PIN);
  feederServo.write(0);

  Serial.println("================================");
  Serial.println("SMART FARM SYSTEM STARTED");
  Serial.println("================================");
}

void loop()
{
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();

  if (isnan(suhu) || isnan(kelembapan))
  {
    Serial.println("Gagal membaca DHT11!");
    delay(2000);
    return;
  }

  if (suhu < suhuMinimum)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }

  float jarakPakan = bacaJarak();

  Serial.println("--------------------------------");
  Serial.print("Suhu        : ");
  Serial.print(suhu);
  Serial.println(" C");

  Serial.print("Kelembapan  : ");
  Serial.print(kelembapan);
  Serial.println(" %");

  Serial.print("Jarak Pakan : ");
  Serial.print(jarakPakan);
  Serial.println(" cm");

  if (suhu < suhuMinimum)
  {
    Serial.println("Status Lampu : ON (Pemanas Aktif)");
  }
  else
  {
    Serial.println("Status Lampu : OFF");
  }

  if (jarakPakan > batasPakan)
  {
    Serial.println("Pakan Menipis!");

    if (millis() - lastFeedTime > feedCooldown)
    {
      Serial.println("Servo Membuka Tempat Pakan");

      feederServo.write(90);
      delay(2000);

      Serial.println("Servo Menutup Tempat Pakan");

      feederServo.write(0);

      lastFeedTime = millis();
    }
    else
    {
      Serial.println("Menunggu Cooldown...");
    }
  }
  else
  {
    Serial.println("Stok Pakan Masih Aman");
  }

  Serial.println("--------------------------------\n");

  delay(2000);
}