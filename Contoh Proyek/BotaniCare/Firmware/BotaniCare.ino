#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define DHTPIN 4         // GPIO4 untuk DHT
#define DHTTYPE DHT22
#define LDRPIN 34       // GPIO34 (ADC input) untuk LDR
#define SOILPIN 16       
#define LEDPIN 5         // GPIO5 untuk LED
#define BUZZER 2

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;


void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int ldrValue = analogRead(LDRPIN);
  int soilValue = analogRead(SOILPIN); 
  bool warning = false;

  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca data dari sensor DHT!");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" °C, Humidity: ");
  Serial.print(h);
  Serial.print(" %, LDR: ");
  Serial.print(ldrValue);
  Serial.print(", Soil: ");
  Serial.println(soilValue);

  Blynk.virtualWrite(V0, t);         // Suhu
  Blynk.virtualWrite(V1, h);         // Kelembaban udara
  Blynk.virtualWrite(V3, ldrValue);  // Nilai LDR
  Blynk.virtualWrite(V2, soilValue); // Kelembaban tanah
  Blynk.virtualWrite(V4, statusTanah); // status tanah

  if (ldrValue  > 500) {
    digitalWrite(LEDPIN, HIGH); 
  } else {
  digitalWrite(LEDPIN, LOW);  
  }

  if (t > 30 || h < 40) {
    Serial.println("🚨 Peringatan! Suhu tinggi atau kelembaban rendah!");
    warning = true;
  }

   if (soilValue > 700) {
    Serial.println("Status: Sangat Kering!");
    warning = true;
  } else if (soilValue > 400) {
    Serial.println("Status: Agak Kering.");
  } else if (soilValue > 200) {
    Serial.println("Status: Lembab.");
  } else {
    Serial.println("Status: Sangat Basah!");
  }

  if (warning) {
    tone(BUZZER, 2000); 
  } else {
    noTone(BUZZER);
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();

  pinMode(SOILPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);


  timer.setInterval(2000L, sendSensor); 
}

void loop() {
  Blynk.run();
  timer.run();
}
