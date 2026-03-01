# 🚧 Infrared Obstacle Detection using IR Sensor

This project demonstrates how to detect nearby obstacles using an Infrared (IR) obstacle avoidance sensor with an Arduino-compatible board.

---


## 🔧 Components Used

- 1x Infrared Obstacle Avoidance Sensor
- 1x Arduino board (ESP8266, NodeMCU, Uno, etc.)
- 1x LED (as visual indicator)
- Jumper wires
- Breadboard (optional)

---

## 🔌 Wiring

| IR Sensor Pin | Arduino Pin |
|---------------|-------------|
| VCC           | 3.3V / 5V   |
| GND           | GND         |
| OUT           | D2 (GPIO4)  |

| Component     | Arduino Pin |
|---------------|-------------|
| LED           | D5 (GPIO14) |

---

## 🧠 How It Works

- The IR sensor emits and receives infrared light.
- When an object is near, reflected IR light is detected, and the sensor's digital output goes **LOW**.
- The Arduino reads this signal and turns on an LED (or other indicator) when an obstacle is detected.
- A message is printed to the Serial Monitor showing the detection status.
