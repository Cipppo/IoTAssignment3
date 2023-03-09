#include "Controller.h"
#include "Arduino.h"

Controller::Controller(){
    this->timer = new Timer();
}

void Controller::init(){
    this->led = new Led(LED_PIN);
    this->servo = new Servo(SERVO_PIN);
}

void Controller::tick(){
    //USARE IL PORCODIO DI HANDLER DEI MESSAGGI 
}

Timer* Controller::getTimer(){
    return this->timer;
}