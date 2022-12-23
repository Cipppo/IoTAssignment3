#include <Arduino.h>
#include <ESP8266WiFi.h>


#include "WiFiNode.h"
#include "constants/Constants.h"



WiFiNode::WiFiNode(){
    this->ssid = SSID;
    this->password = PASSWORD;
    this->setup();
    this->connect();
};

void WiFiNode::setup(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(this->ssid, this->password);
}

void WiFiNode::connect(){
    while(!this->isConnected()){
        Serial.print(".");
        delay(500);
    }
    Serial.println("WiFi Connected!");
};

bool WiFiNode::isConnected(){
    return WiFi.status() == WL_CONNECTED;
}

