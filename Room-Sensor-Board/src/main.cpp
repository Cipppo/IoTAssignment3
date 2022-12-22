#include <Arduino.h>



#include "WiFiNode/WiFiNode.h"
#include "Constants/Constants.h"
#include "MQTTClient/MQTTClient.h"

WiFiNode wifi = WiFiNode("FBIVan", "12345678");
MQTTClient mqttclient = MQTTClient("broker.mqtt-dashboard.com", "light/mqtt", 1883);

void setup() {
    Serial.begin(9600);
    wifi.connect();
    mqttclient.setup();
}

void loop() {
    if(!mqttclient.isClientConnected()){
        mqttclient.connect();
    }else{
        mqttclient.sendMessage("dp");
    }
    delay(1000);
}