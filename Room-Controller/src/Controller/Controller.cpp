#include "Controller.h"
#include "Arduino.h"

Controller::Controller(){
    this->timer = new Timer();
}

void Controller::init(){
    Serial.println("Init Called");
}

void Controller::tick(){
    Serial.println("Tick Called");
}

Timer* Controller::getTimer(){
    return this->timer;
}