#include "photores.h"
#include "Arduino.h"



Photores::Photores(int pin){
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

int Photores::getValue(){
    return this->value;
}

double Photores::getValueInVolt(){
    return this->valueInVolt;
}

void Photores::readValue(){
    this->value = analogRead(this->pin);
    this->valueInVolt = ((double) value) * 5/1024;
}

int Photores::getPin(){
    return this->pin;
}