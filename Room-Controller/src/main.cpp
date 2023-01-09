#include <Arduino.h>
#include <ArduinoJson.h>

#include "Constants/Constants.h"
#include "Hardware/Led/Led.h"
#include "DataSerialization/DataDeSerializer.h"
#include "Hardware/Photores/Photores.h"
#include "SerialCommunication/SerialComsHandler.h"
#include "DataSerialization/ReceiveDatagram.h"
#include "Controller/Controller.h"

#define PIN 2



Controller* controller;


void changeTheState(){
  controller->getTimer()->changeState();
}

void setup(){
  Serial.begin(9600);
  controller = new Controller();
  controller->init();
  controller->getTimer()->getTimerOne()->attachInterrupt(changeTheState);
  //Serial.println("Tra 6 secondi il messaggio verra' letto");
}

void loop(){
  controller->getTimer()->waitForTheNextTick();
  controller->tick();
};