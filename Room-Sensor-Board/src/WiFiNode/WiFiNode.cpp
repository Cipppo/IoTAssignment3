#include <Arduino.h>
#include <ESP8266WiFi.h>


#include "WiFiNode.h"



WiFiNode::WiFiNode(char* ssid, char* password){
    this->ssid = ssid;
    this->password = password;
};

void WiFiNode::connect(){
    Serial.println("");
    Serial.println(String("Conneting to") + this->ssid);
    WiFi.begin(this->ssid, this->password);
    while(!this->isConnected()){
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Wifi connected at: ");
    Serial.println(WiFi.localIP());
};

bool WiFiNode::isConnected(){
    return WiFi.status() == WL_CONNECTED;
}

