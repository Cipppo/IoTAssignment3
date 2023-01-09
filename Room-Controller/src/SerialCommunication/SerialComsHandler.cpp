#include <Arduino.h>
#include "SerialCommunication/SerialComsHandler.h"



bool SerialComsHandler::read(){
    String line = Serial.readStringUntil('\n');
    if(line != ""){
        this->deSerializer.deSerialize(line);
        this->part = this->deSerializer.get("component");
        this->value = this->deSerializer.get("value");
        Serial.println(value);
        return true;
    }else{
        //Serial.println("no");
        return false;
    }
}

String SerialComsHandler::getPart(){
    return this->part;
}

int SerialComsHandler::getValue(){
    return this->value;
}

void SerialComsHandler::write(String key, int value){
    String line = this->serializer.serialize(key, value);
    Serial.println(line);
}

void SerialComsHandler::writeStr(String string){
    Serial.println(string);
}