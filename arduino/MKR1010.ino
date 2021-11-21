#include "secrets.h"
#include <WiFiNINA.h> 

#define SENSOR_PIN A0
#define MAX_SENSOR_VALUE 660
#define MIN_SENSOR_VALUE 245

const char ssid[] = WIFI_SSID;
const char password[] = WIFI_PASSWORD;

void setup() {
    Serial.begin(9600);
    while (!Serial);

    WiFi.begin(ssid, password);

    Serial.print("Connecting to WiFi...");

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("Connection established!");
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP()); 
}

void loop() {
    int sensorValue = analogRead(SENSOR_PIN);
    int normalizedSensorValue = map(sensorValue, MIN_SENSOR_VALUE, MAX_SENSOR_VALUE, 100, 0); // remap the sensor values to a 0-100 scale, going from dry to wet

    Serial.println(normalizedSensorValue);

    if (normalizedSensorValue < 25) {
        // The soil is too dry, water the plant
    } else {
        // Everything is ok
    }
    
}