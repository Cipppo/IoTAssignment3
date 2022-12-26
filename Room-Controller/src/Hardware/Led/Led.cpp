#include "Led.h"
#include "Arduino.h"



Led::Led(int pin){
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
}

void Led::turnOff(){
    digitalWrite(this->pin, LOW);
}

void Led::turnOn(){
    digitalWrite(this->pin, HIGH);
}

int Led::getPin(){
    return this->pin;
}

int Led::readValue(){
    return digitalRead(this->pin);
}