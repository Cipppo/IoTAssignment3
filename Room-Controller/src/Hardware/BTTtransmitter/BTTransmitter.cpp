#include <Arduino.h>
#include <Wire.h>
#include "BTTransmitter.h"
#include <SoftwareSerial.h>


BTTransmitter::BTTransmitter(int rxPin, int txPin, char name){
    this->rxPin = rxPin;
    this->txPin = txPin;
};

