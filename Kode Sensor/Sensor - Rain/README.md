# 🌧️ Rain Sensor Detection with LED Indicator

## A. English

### 📌 Project Overview

This project uses a **Rain Sensor** to detect rain and activates an LED as an alert. When rain is detected, a message is printed to the Serial Monitor and the LED is turned on.

### 🔧 Components

- Rain Sensor (digital type)
- NodeMCU / ESP8266
- LED (or buzzer)
- Jumper wires, breadboard

### 🔌 Wiring

| Component      | ESP8266 Pin |
|----------------|-------------|
| Rain Sensor    | D6          |
| LED            | D5          |

### 📋 How It Works

- The sensor outputs `LOW` when rain is detected, and `HIGH` when it's dry.
- The microcontroller reads the digital signal from the sensor.
- If `LOW`, rain is detected → LED is turned on.
- If `HIGH`, no rain → LED stays off.