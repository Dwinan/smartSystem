# 📏 Ultrasonic Distance Measurement with HC-SR04

This project uses an ultrasonic sensor (e.g., HC-SR04) to measure the distance between the sensor and an object using an Arduino-compatible board.

---

## 🔧 Components Used

- 1x HC-SR04 Ultrasonic Sensor
- 1x Arduino (NodeMCU, ESP8266, Uno, etc.)
- Jumper wires
- Breadboard (optional)

---

## 🔌 Wiring

| HC-SR04 Pin | Arduino Pin |
|-------------|-------------|
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | D0          |
| ECHO        | D1          |

---

## 🧠 How It Works

1. The TRIG pin sends a 10μs HIGH pulse to initiate measurement.
2. The ECHO pin receives the reflection duration from the object.
3. Distance is calculated using the speed of sound formula:
