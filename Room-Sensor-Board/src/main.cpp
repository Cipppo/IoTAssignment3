#include <Arduino.h>
#include<ESP8266WiFi.h>


#include "model/wifiNode/WiFiNode.h"
#include "constants/Constants.h"
#include "model/mqttClient/MQTTClient.h"



WiFiNode* wifi;
MQTTClient* mqttClient;




void setup() {
  Serial.begin(9600);
  wifi = new WiFiNode();
  mqttClient = new MQTTClient();
}

void loop() {

    mqttClient->sendMessage("messaggio");
    delay(1000);

}