# ESP32 Environment Monitoring with Blynk


## Deskripsi Proyek
This project reads environmental data from multiple sensors using an ESP32 and sends the data to the Blynk IoT platform for remote monitoring. It also controls an LED and buzzer based on sensor conditions.

---

## Fitures
-  Reads temperature and humidity from a DHT22 sensor.
- Reads light intensity from an LDR sensor via ADC.
- Reads soil moisture level via analog sensor.
- Sends sensor data to Blynk app virtual pins for live monitoring.
- Controls an LED indicator based on light intensity.
- Activates a buzzer alarm if temperature is high, humidity is low, or soil is very dry.
- Outputs sensor readings and status messages on the serial monitor.
- Runs periodic sensor updates every 2 seconds.
---

## Component
- ESP32 Dev Board
- DHT22 Sensor (Temprature & Humidity)
- LDR Sensor (Light Dependent Resistor)
- Soil Moisture Sensor
- LED
- Buzzer

---

## Wiring / Pinout

| Komponen          | ESP32 Pin    |
|-------------------|--------------|
| DHT22             | GPIO 4       |
| LDR (ADC Input)   | GPIO 34      |
| Soil Moisture     | GPIO 16      |
| LED               | GPIO 5       |
| Buzzer            | GPIO 2       |

---

## Setup dan Initialization

1. Install these library on Arduino IDE:
   - `DHT sensor library` by Adafruit
   - `Blynk` library
   - `WiFi` (Included in ESP32 Core)
2. Replace BLYNK_AUTH_TOKEN with your own Blynk project authentication token.
3. Update ssid and pass with your WiFi network credentials.
4. Upload the code to your ESP32 board.
5. Open Serial Monitor at 115200 baud to see sensor readings and status logs.
6. Use the Blynk app to monitor temperature (V0), humidity (V1), soil moisture (V2), and light intensity (V3).
7. The LED will turn on if light intensity is above a threshold (500).
8. The buzzer will sound if temperature > 30°C, humidity < 40%, or soil moisture is very dry (value > 700).

---

## Notes
- Soil moisture sensor outputs analog voltage: higher value means drier soil.
- Adjust sensor thresholds in the code as needed for your environment.
- ADC2 pins may conflict with WiFi on ESP32, so monitor for instability or consider using ADC1 pins for analog sensors if issues arise.