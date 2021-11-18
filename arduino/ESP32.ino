#include "secrets.h"
#include <WiFi.h>

const char ssid[] = WIFI_SSID;
const char password[] = WIFI_PASSWORD;

void setup() {
    Serial.begin(9600);
    while (!Serial);

    WiFi.mode(WIFI_STA);
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
    
}