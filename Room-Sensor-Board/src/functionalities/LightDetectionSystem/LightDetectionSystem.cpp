#include "LightDetectionSystem.h"




LightDetectionSystem::LightDetectionSystem(int photoresPin){
    this->photoresPin = photoresPin;
}

void LightDetectionSystem::init(){
    this->photores = new Photores(this->photoresPin);
}

void LightDetectionSystem::readValue(){
    this->photores->readValue();
}

Photores LightDetectionSystem::getPhotores(){
    return *this->photores;
}


int LightDetectionSystem::getPhotoresPin(){
    return this->photoresPin;
}

int LightDetectionSystem::getPhotoresValue(){
    return this->photores->getValue();
}

double LightDetectionSystem::getPhotoresValueInVolt(){
    return this->photores->getValueInVolt();
}