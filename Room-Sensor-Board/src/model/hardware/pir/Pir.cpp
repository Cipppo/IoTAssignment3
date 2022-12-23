#include <Arduino.h>

#include "Pir.h"
#include "constants/Constants.h"

Pir::Pir(int pin){
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

void Pir::calibrate(){
    Serial.println("Calibrating Sensor...");
    for(int i=1 ; i < CALIBRATION_TIME; i++){
        Serial.print(".");
        delay(1000);
    }
    Serial.println("");
    Serial.println("Calibration done!");
    delay(50);
}

bool Pir::scan(){
    int detection = analogRead(this->pin);
    if(detection == HIGH){
        return true;
    }else{
        return false;   
    }
}

bool Pir::detect(){
    if(this->scan()){
        return true;
    }else{
        return false;
    }
}