#include <Arduino.h>

#include "Led.h"




Led::Led(int pin){
    this->pin = pin;
}

void Led::turnOn(){
    digitalWrite(this->pin, HIGH);
}

void Led::turnOff(){
    digitalWrite(this->pin, LOW);
}

