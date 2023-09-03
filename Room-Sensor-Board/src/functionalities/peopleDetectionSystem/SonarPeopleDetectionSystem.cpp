#include "SonarPeopleDetectionSystem.h"



SonarPeopleDetectionSystem::SonarPeopleDetectionSystem(int ledPin, int echoPin, int trigPin){
    this->ledPin = ledPin;
    this->echoPin = echoPin;
    this->trigPin = trigPin;
}

void SonarPeopleDetectionSystem::init(){
    this->sonar = new Sonar(this->trigPin, this->echoPin);
    this->led = new Led(this->ledPin);
}

void SonarPeopleDetectionSystem::detectPresence(){
    this->distance = this->sonar->readValue();
}

void SonarPeopleDetectionSystem::turnOnLed(){
    this->led->turnOn();
}

void SonarPeopleDetectionSystem::turnOffLed(){
    this->led->turnOff();
}


bool SonarPeopleDetectionSystem::getPresence(){
    Serial.println(this->distance);
    return true;
}