#include "PeopleDetectionSystem.h"



PeopleDetectionSystem::PeopleDetectionSystem(int pirPin, int ledPin){
    this->pirPin = pirPin;
    this->ledPin = ledPin;
}

void PeopleDetectionSystem::init(){
    this->pir = new Pir(this->pirPin);
    this->led = new Led(this->ledPin);
}

void PeopleDetectionSystem::detectPresence(){
    this->isPresent = this->pir->detect();
}

void PeopleDetectionSystem::turnOnLed(){
    this->led->turnOn();
}

void PeopleDetectionSystem::turnOffLed(){
    this->led->turnOff();
}

Pir PeopleDetectionSystem::getPir(){
    return *this->pir;
}

Led PeopleDetectionSystem::getLed(){
    return *this->led;
}

int PeopleDetectionSystem::getPirPin(){
    return this->pirPin;
}

int PeopleDetectionSystem::getLedPin(){
    return this->ledPin;
}

bool PeopleDetectionSystem::getPresence(){
    return this->isPresent;
}