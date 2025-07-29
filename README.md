# GEYSER-MONITORING-SYSTEM

A real-time IoT-based geyser monitoring system using STM32 and ESP32 that measures water level and temperature, and updates data to Firebase for remote visualization.

---

## Features

- Real-time temperature monitoring from DS18B20 sensor
- Dry-run protection via P43 water level sensor
- Data transmission from STM32 to ESP32 over UART
- Live dashboard using Firebase Realtime Database
- Automatic alerts for over-threshold temperature or no water
- Fully responsive web UI for monitoring

---

## Components Used

- STM32F103C8T6 (Blue Pill)
- ESP32 Dev Module
- DS18B20 Temperature Sensor
- P43 Water Level Sensor
- Resistors, connecting wires, breadboard
- USB to TTL converter (for STM32 programming)
- Power supply module

---

## Connections

| STM32 Pin | Connected To                |
|-----------|-----------------------------|
| PA9       | ESP32 RX (GPIO16)           |
| PA10      | ESP32 TX (GPIO17)           |
| PA1       | DS18B20 Data                |
| GND       | DS18B20 GND, P43 GND        |
| 3.3V      | DS18B20 VCC, P43 VCC        |
| PB0       | P43 Digital Output          |

| ESP32 Pin | Connected To                |
|-----------|-----------------------------|
| GPIO16    | STM32 TX (PA9)              |
| GPIO17    | STM32 RX (PA10)             |
| 3.3V      | Firebase + Sensor Power     |
| GND       | Common Ground               |

---

## Tools & Libraries

- STM32CubeIDE (STM32 code development)
- Arduino IDE (ESP32 code)
- FirebaseESP32 library
- DS18B20 OneWire library
- PlatformIO (optional)
- Firebase Realtime Database
- Web-based HTML + CSS + JS Dashboard

---

## Methodology

1. STM32 reads sensor data:
   - DS18B20 provides temperature
   - P43 indicates water presence
2. STM32 sends data over UART to ESP32
3. ESP32 receives data and pushes to Firebase
4. Web dashboard fetches and displays live data
5. Alerts are shown based on threshold logic

---

## Firebase Configuration

**ESP32 Code Setup:**

```cpp
#define FIREBASE_HOST "geysersystem-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "7JmWPiU1mXe0HaHcLDLsXWhzFafgsr9yBdbi0d9J"
