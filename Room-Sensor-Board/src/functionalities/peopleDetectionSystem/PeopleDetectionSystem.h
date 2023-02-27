#ifndef __PEOPLEDETECTIONSYSTEM__
#define __PEOPLEDETECTIONSYSTEM__



#include "constants/Constants.h"
#include "model/hardware/pir/Pir.h"
#include "model/hardware/led/Led.h"
#include "Arduino.h"

class PeopleDetectionSystem{
    private:
        Pir* pir;
        Led* led;
        int ledPin;
        int pirPin;
        bool isPresent;
    public:
        PeopleDetectionSystem(int pirPin, int ledPin);
        void init();
        //Pir
        void detectPresence();
        //Led
        void turnOnLed();
        void turnOffLed();
        //Getters
        Pir getPir();
        Led getLed();
        int getPirPin();
        int getLedPin();
        bool getPresence();
};












#endif