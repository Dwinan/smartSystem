# 🌡️ DHT22 Temperature and Humidity Monitoring

This project uses the DHT22 sensor to monitor temperature and humidity in real-time using an Arduino-compatible board.

---

## 🔧 Components Used

- 1x DHT22 Temperature & Humidity Sensor
- 1x Arduino (NodeMCU, ESP8266, Uno, etc.)
- Jumper wires
- Breadboard (optional)

---

## 🔌 Wiring

| DHT22 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 3.3V or 5V  |
| DATA      | D3          |
| GND       | GND         |

📝 Use a 10kΩ pull-up resistor between VCC and DATA if readings are unstable.

---

## 🧠 How It Works

1. The Arduino reads temperature and humidity data from the DHT22 sensor.
2. If readings fail (NaN), it prints an error message.
3. If temperature ≥ 40°C, it gives a warning.
4. Otherwise, it states that the system is safe.

