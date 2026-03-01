# 🔥 Flame Detection with Flame Sensor Module

This project demonstrates how to detect fire or flame using a digital flame sensor with an Arduino-compatible board.

---

## 🔧 Components Used

- 1x Flame Sensor Module (IR-based)
- 1x Arduino (NodeMCU, ESP8266, Uno, etc.)
- Jumper wires
- Breadboard (optional)

---

## 🔌 Wiring

| Flame Sensor Pin | Arduino Pin |
|------------------|-------------|
| VCC              | 3.3V / 5V   |
| GND              | GND         |
| DO (Digital Out) | D2 (GPIO4)  |

---

## 🧠 How It Works
(LOW or HIGH depends on the sensor module)
- The flame sensor detects infrared light emitted by a fire or flame.
- When fire is detected, the sensor's digital output (DO) goes **LOW**.
- The Arduino reads this signal and prints a corresponding message to the Serial Monitor.

---