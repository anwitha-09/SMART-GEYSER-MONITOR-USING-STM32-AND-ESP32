# STM32-ESP32-FIREBASE-GEYSER-MONITOR

A smart geyser monitoring system using STM32 and ESP32, which reads sensor data and uploads it live to Firebase Realtime Database, displayed via a web-based dashboard.

---

## Features

- Monitors geyser temperature in real-time  
- Detects water presence using float sensor  
- Sends sensor data to Firebase via ESP32  
- Displays live data on a responsive HTML dashboard  
- Alerts if temperature exceeds threshold  
- Offline detection and reconnection handling  

---

## Components Used

| Component            | Quantity | Description                             |
|----------------------|----------|-----------------------------------------|
| STM32F407VG          | 1        | Reads sensors, sends data to ESP32      |
| ESP32 Dev Board      | 1        | Connects to WiFi & uploads to Firebase  |
| DS18B20              | 1        | Digital temperature sensor              |
| FS37A Float Sensor   | 1        | Magnetic water level sensor             |
| Resistors            | 1        | 4.7kΩ for DS18B20 pull-up               |
| Breadboard + Wires   | -        | For prototyping                         |

---

## Connection Table

| STM32 Pin     | Connected To           | Function                            |
|---------------|------------------------|-------------------------------------|
| PA9 (TX)      | ESP32 GPIO16 (RXD2)    | Serial data to ESP32                |
| PA10 (RX)     | ESP32 GPIO17 (TXD2)    | Serial data from ESP32              |
| GPIO (any)    | DS18B20 DATA           | Temperature sensor input            |
| GPIO (any)    | FS37A output           | Water level detection (0/1)         |
| 3.3V          | DS18B20 + FS37A VCC    | Power supply                        |
| GND           | Common GND             | Ground for all devices              |

---

## Tools Used

- STM32CubeIDE (STM32 code + UART config)  
- Arduino IDE (ESP32 Firebase code)  
- Firebase Realtime Database (Cloud storage)  
- HTML/CSS/JS (Dashboard UI)  
- VS Code / Sublime Text (for HTML editing)  

---

## Methodology

1. STM32 reads data from DS18B20 and FS37A  
2. Data formatted as: `temperature,water_level\n`  
3. Sent via UART to ESP32  
4. ESP32 receives, parses, and uploads to Firebase  
5. HTML Dashboard fetches live data and displays it in real time  

---

## Firebase Configuration

**ESP32 Code Setup:**
```cpp
#define FIREBASE_HOST "geysersystem-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "7JmWPiU1mXe0HaHcLDLsXWhzFafgsr9yBdbi0d9J"
