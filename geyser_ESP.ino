#include "arduino_secrets.h"

#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>

#define RXD2 16  // STM32 TX â ESP32 RX
#define TXD2 17  // STM32 RX â ESP32 TX

// WiFi Credentials
#define WIFI_SSID "Realme"
#define WIFI_PASSWORD "happy123"

// Firebase Credentials
#define FIREBASE_HOST "YOUR_FIREBASE_HOST_URL"
#define FIREBASE_AUTH "YOUR_FIREBASE_AUTH_TOKEN"


FirebaseData fbdo;
FirebaseConfig config;
FirebaseAuth auth;

String incomingData = "";
float temperature = 0.0;
int water_level = 0;

// â Static threshold defined in ESP32
const float THRESHOLD = 32.0;

void parseSTM32(String data);

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi connected! IP: " + WiFi.localIP().toString());

  config.database_url = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  // Read from STM32 (e.g., "28.6,1\n")
  while (Serial2.available()) {
    char c = Serial2.read();
    if (c == '\n') {
      parseSTM32(incomingData);
      incomingData = "";
    } else {
      incomingData += c;
    }
  }

  delay(1000);
}

void parseSTM32(String data) {
  int comma = data.indexOf(',');
  if (comma > 0) {
    temperature = data.substring(0, comma).toFloat();
    water_level = data.substring(comma + 1).toInt();

    // ð¹ Print to Serial Monitor
    Serial.print("Received from STM32 -> ");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" Â°C | Water Level: ");
    Serial.println(water_level == 0 ? "Present" : "Not Present");

    // â Send to Firebase
    Firebase.setFloat(fbdo, "/sensor_data/temperature", temperature);
    Firebase.setInt(fbdo, "/sensor_data/water_level", water_level);
    Firebase.setFloat(fbdo, "/sensor_data/threshold", THRESHOLD);

    Serial.println("Uploaded to Firebase:");
    Serial.printf("Temp: %.2f Â°C, Water: %d, Threshold: %.1f\n", temperature, water_level, THRESHOLD);
  }
}