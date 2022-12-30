#include <Arduino.h>
#include "SerialCommunication/SerialComsHandler.h"


bool SerialComsHandler::read(){
    String line = Serial.readStringUntil("\n");
    if(line != ""){
        this->deSerializer.deSerialize(line);
        this->part = this->deSerializer.get("component");
        return true;
    }else{
        return false;
    }
}

String SerialComsHandler::getPart(){
    return this->part;
}

int SerialComsHandler::getValue(){
    return this->value;
}
