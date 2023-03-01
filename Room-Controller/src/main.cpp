#include <Arduino.h>
#include <ArduinoJson.h>

#include "Constants/Constants.h"
#include "Hardware/Led/Led.h"
#include "DataSerialization/DataDeSerializer.h"
#include "Hardware/Photores/Photores.h"
#include "SerialCommunication/SerialMsgHandler.h"
#include "DataSerialization/ReceiveDatagram.h"
#include "Controller/Controller.h"

#define PIN 2


SerialMsgHandler* msgHandler;
Controller* controller;




void setup(){
  msgHandler->init();
  //Serial.println("Tra 6 secondi il messaggio verra' letto");
}

void loop(){
  
};