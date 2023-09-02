#include <Arduino.h>
#include <Wire.h>
#include "BTTransmitter.h"


BTTransmitter::BTTransmitter(int rxPin, int txPin, char* name){
    this->rxPin = rxPin;
    this->txPin = txPin;
    this->name = name;
}

void BTTransmitter::init(){
    this->channel = new SoftwareSerial(this->rxPin, this->txPin);
    this->channel->begin(2400);
}

bool BTTransmitter::isAvailable(){
    String message = "";
    while(this->channel->available()){
        message = this->channel->readString();
        this->availableMessage = new Msg(message);
        message = "";
        return true;
    }
    return false;
}

Msg* BTTransmitter::read(){
    if(availableMessage != NULL){
        Msg* msg = availableMessage;
        availableMessage = NULL;
        return msg;
    }else{
        return NULL;
    }
}

void BTTransmitter::write(Msg val){
    this->channel->println(val.getContent());
}