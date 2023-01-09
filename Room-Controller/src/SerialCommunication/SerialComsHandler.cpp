#include <Arduino.h>
#include "SerialCommunication/SerialComsHandler.h"



bool SerialComsHandler::read(){

}

String SerialComsHandler::getPart(){
    return this->part;
}

int SerialComsHandler::getValue(){
    return this->value;
}

void SerialComsHandler::write(String key, int value){
    
}

void SerialComsHandler::writeStr(String string){
    Serial.println(string);
}