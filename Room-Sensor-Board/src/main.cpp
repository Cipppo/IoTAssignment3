#include <Arduino.h>
#include<ESP8266WiFi.h>


#include "model/wifiNode/WiFiNode.h"
#include "constants/Constants.h"
#include "model/mqttClient/MQTTClient.h"
#include "model/hardware/pir/Pir.h"
#include "model/hardware/photoresistor/photores.h"
#include "serialization/DataSerialization.h"
#include "smartRoom/SmartRoom.h"


WiFiNode* wifi;
MQTTClient* mqtt;   
DataSerialization* serializer;
SmartRoom* smartRoom;

void setup() {

  Serial.begin(9600);
  smartRoom->init();
  wifi = new WiFiNode();
  mqtt = new MQTTClient();
  serializer = new DataSerialization();

}

void loop() {

  while(wifi->isConnected()){
    smartRoom->tick();
    String toSend = serializer->serialize("Light", smartRoom->isLight());
    mqtt->sendMessage(toSend);
    String toSend2 = serializer->serialize("Pir", smartRoom->getPeople());
    mqtt->sendMessage(toSend2);
    delay(1000);
  }


}