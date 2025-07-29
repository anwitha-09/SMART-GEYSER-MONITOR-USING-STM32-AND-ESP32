# GEYSER-MONITORING-SYSTEM

Conventional geysers lack automatic safety mechanisms.  
Risks include dry run damage, overheating, and energy waste.  
This project introduces a smart system using STM32, P43 sensor, and DS18B20.  
Web dashboard via Firebase enables remote alerts and monitoring.

---

## Features

- Prevent dry run operation using P43 water level sensor
- Real-time temperature monitoring with DS18B20
- Simulate geyser ON/OFF using LED and relay module
- Threshold-based automatic control logic using STM32
- UART communication between STM32 and ESP32
- Live data pushed to Firebase and displayed on dashboard
- Fully responsive and synced UI built with HTML and Firebase

---

## Components Used

- Microcontroller: STM32F4 (STM32F103C8T6)
- Sensors:  
  - P43 (water level – digital GPIO)  
  - DS18B20 (temperature – 1-Wire)
- Output:  
  - LED (simulated geyser)  
  - Relay Module (controls geyser simulation)
- Communication:  
  - UART (STM32 ↔ ESP32)  
  - Wi-Fi / HTTP (ESP32 ↔ Firebase)
- Software:  
  - VS Code (Embedded C – HAL)  
  - Firebase Realtime Database  
  - HTML + JS for Dashboard UI

---

## Connections

| Component          | Connection                              |
|--------------------|------------------------------------------|
| P43 Sensor         | PB0 (STM32 GPIO – Digital Input)         |
| DS18B20 Sensor     | PA1 (STM32 – 1-Wire Input)               |
| LED (Simulated ON) | STM32 GPIO Output + Relay Driver         |
| STM32 TX (PA9)     | ESP32 RX (GPIO16)                        |
| STM32 RX (PA10)    | ESP32 TX (GPIO17)                        |
| 3.3V, GND          | Shared between STM32, sensors, ESP32     |

---

## Tools & Libraries

- STM32CubeIDE or VS Code (Embedded C – STM32 HAL)
- Arduino IDE (ESP32 Wi-Fi Firebase code)
- FirebaseESP32 library
- OneWire & DallasTemperature libraries
- Firebase Realtime Database
- HTML + CSS + JS for dashboard
- Chrome for UI visualization

---

## Methodology

**Sensor Integration**  
- Connect P43 to detect water presence  
- Connect DS18B20 for temperature monitoring

**Signal Processing**  
- Use STM32 to read sensor values via GPIO and 1-Wire  

**Control Logic Implementation**  
- If water level is low, geyser stays OFF (relay + LED)  
- If temperature exceeds threshold, geyser turns OFF

**Simulation Output**  
- LED and relay module indicate ON/OFF state of geyser  

**Testing & Validation**  
- Verified system response to various water/temp conditions

**Communication Flow**  
- P43 → STM32 (Digital GPIO)  
- DS18B20 → STM32 (1-Wire protocol)  
- STM32 → ESP32 (UART)  
- ESP32 → Firebase (Wi-Fi / HTTP)

---

## Firebase Configuration

```cpp
#define FIREBASE_HOST "geysersystem-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "7JmWPiU1mXe0HaHcLDLsXWhzFafgsr9yBdbi0d9J"
