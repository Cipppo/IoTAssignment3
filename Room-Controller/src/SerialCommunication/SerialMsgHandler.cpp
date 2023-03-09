#include "SerialMsgHandler.h"
#include "Arduino.h"



SerialMsgHandler::SerialMsgHandler(){
  this->deSerializer = new DataDeSerializer();
}


bool SerialMsgHandler::getMessage(){
  while(Serial.available()){
    this->datagram = this->deSerializer->getValue();
    return true;
  }
}

int SerialMsgHandler::getLightValue(){
  this->datagram->getLightValue();
}

int SerialMsgHandler::getServoValue(){
  this->datagram->getServoAngle();
}
