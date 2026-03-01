# ⚙️ Vibration Detection with SW-420 Sensor

This project demonstrates how to detect vibrations using the SW-420 vibration sensor module and an Arduino-compatible board.

---


## 🔧 Components Used

- 1x SW-420 Vibration Sensor Module
- 1x Arduino (ESP8266 / NodeMCU / Uno, etc.)
- 1x LED or Buzzer (optional, for output)
- Jumper wires
- Breadboard (optional)

---

## 🔌 Wiring

| SW-420 Pin | Arduino Pin |
|------------|-------------|
| VCC        | 3.3V / 5V   |
| GND        | GND         |
| DO         | D2 (GPIO4)  |

Optional:

| Output     | Arduino Pin |
|------------|-------------|
| LED/Buzzer | D5 (GPIO14) |

---

## 🧠 How It Works

1. The SW-420 module detects mechanical vibrations.
2. When vibration is detected, the digital output pin (DO) goes **HIGH**.
3. The microcontroller reads the signal from the DO pin and prints the result to the Serial Monitor.
4. Optional: you can add a buzzer or LED as an indicator when vibration is detected.
