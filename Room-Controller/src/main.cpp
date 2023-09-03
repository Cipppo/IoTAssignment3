#include <Arduino.h>
#include <ArduinoJson.h>

#include "Constants/Constants.h"
#include "Hardware/Led/Led.h"
#include "Hardware/Photores/Photores.h"
#include "SerialCommunication/SerialMsgHandler.h"
#include "Controller/Controller.h"
#include "SerialCommunication/Msg.h"
#define PIN 2


SerialMsgHandler* msgHandler;
Controller* controller;


void changeState(){
  controller->getTimer()->changeState();
}

void setup(){
  Serial.begin(9600);
  controller = new Controller();
  controller->init();
  controller->getTimer()->getTimerOne()->attachInterrupt(changeState);
}

void loop(){

 controller->getTimer()->waitForTheNextTick();
 controller->tick();
};