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

int readLightValue(){
    int value = analogRead(PHOTO_PIN);
    double valueInVolt = ((double) value) * 5/1024;

    if(valueInVolt > MINIMUM_LIGHT_VALUE){
      return 1;
    }else{
      return 0;
    }
}


void setup() {

  Serial.begin(9600);
  //smartRoom->init();
  wifi = new WiFiNode();
  mqtt = new MQTTClient();
  serializer = new DataSerialization();

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PHOTO_PIN, INPUT);
}

void loop() {

  while(wifi->isConnected()){


    //smartRoom->isLight();
    if(digitalRead(BUTTON_PIN) == HIGH){
      Serial.println("Premuto ok");
      digitalWrite(LED_PIN, HIGH);

      int lightValue = readLightValue();
      String toSend = serializer->serialize("Light", lightValue);
      String toSend2 = serializer->serialize("Pir", 1);

      Serial.println("Persona trovata, adesso aspetto");
      mqtt->sendMessage(toSend);
      mqtt->sendMessage(toSend2);
      delay(5000);
      digitalWrite(LED_PIN, LOW);
      String toSend3 = serializer->serialize("Pir", 0);
      mqtt->sendMessage(toSend3);
      Serial.println("Rilascio");
    }


    delay(100);
  }


}