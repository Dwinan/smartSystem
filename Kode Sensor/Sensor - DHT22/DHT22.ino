#include <DHT.h> 
#define DHTPIN D3         
#define DHTTYPE DHT22     
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Sistem Pemantauan Suhu dan Kelembaban");
  Serial.println("-----------------------------------");

  dht.begin();
  Serial.println("Sensor DHT22 siap digunakan.");
}

void loop() {

  float kelembaban = dht.readHumidity();
  float suhu = dht.readTemperature(); 

  if (isnan(kelembaban) || isnan(suhu)) {
    Serial.println("Gagal membaca dari sensor DHT22!");
    return;
  }

  Serial.print("Kelembaban: ");
  Serial.print(kelembaban);
  Serial.print(" %  |  Suhu: ");
  Serial.print(suhu);
  Serial.println(" *C");

  if (suhu >= 40 ) {
    Serial.println("!!! SUHU TIDAK NORMAL !!!");
  } else {
    Serial.println("Suhu normal. Sistem aman.");
  }

  delay(1000);
}