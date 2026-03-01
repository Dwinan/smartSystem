# 🧪 Gas Detection with MQ Sensor (Analog)

## 📌 Project Overview

This project utilizes an **MQ gas sensor** to monitor gas levels and trigger an LED alert when the reading exceeds a threshold. The sensor outputs analog values based on the concentration of gas in the environment.

## 🔧 Components

- MQ gas sensor (MQ-2 / MQ-3 / MQ-4 / MQ-135, etc.)
- ESP8266 / NodeMCU
- LED
- Jumper wires, breadboard

## 🔌 Wiring

| Component     | ESP8266 Pin |
|---------------|-------------|
| MQ Sensor AOUT| A0          |
| LED           | D5          |

## ⚙️ Threshold

```cpp
const int AMBANG_GAS = 50;
