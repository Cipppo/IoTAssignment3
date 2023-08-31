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

int peopleValue = 0;

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
    int lightValue = smartRoom->isLight();

    String toSend = serializer->serialize("Light", lightValue);
    String toSend2 = serializer->serialize("Pir", peopleValue);
    if(peopleValue == 1){
      Serial.println("Persona trovata, adesso aspetto");
      mqtt->sendMessage(toSend);
      mqtt->sendMessage(toSend2);
      delay(5000);
    }
    Serial.println(toSend2);
    delay(1000);
  }


}