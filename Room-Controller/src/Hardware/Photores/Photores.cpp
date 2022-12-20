#include "Photores.h"
#include "Arduino.h"



Photores::Photores(int pin){
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

double Photores::readValue(){
    int value = analogRead(this->pin);
    double valueInVolt = ((double) value) * 5/1024;
    return valueInVolt;
}

int Photores::getPin(){
    return this->pin;
}