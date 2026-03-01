# 🌱 Soil Moisture Sensor Monitoring 

This project reads soil moisture levels using an analog sensor and provides real-time feedback via the Serial Monitor. It's a simple yet effective way to understand how dry or wet the soil is, which can be useful for smart irrigation or environmental monitoring systems.

## 🔧 Components Used

- 1x Arduino UNO (or compatible board)
- 1x Soil Moisture Sensor (analog type)
- Jumper wires

## 🔌 Wiring

| Sensor Pin | Arduino Pin |
|------------|-------------|
| VCC        | 5V          |
| GND        | GND         |
| AOUT       | A0          |

> 📌 *Make sure you’re using the analog output (AOUT) of the sensor.*

## How It Works
The soil moisture sensor reads analog values from the soil:
- High value → Dry soil
- Medium value → Damp soil
- Low value → Wet soil

The Arduino evaluates the value and prints messages to the Serial Monitor:
- Above 700 → "Very Dry"
- 401–700 → "Slightly Dry"
- 201–400 → "Moist"
- 0–200 → "Very Wet"

