#include <Arduino.h>
#include <Wire.h>
#include "BTTransmitter.h"


BTTransmitter::BTTransmitter(int rxPin, int txPin, char* name){
    this->rxPin = rxPin;
    this->txPin = txPin;
    this->name = name;
}