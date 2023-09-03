#ifndef __SONARPEOPLEDETECTIONSYSTEM__
#define __SONARPEOPLEDETECTIONSYSTEM__

#include "model/hardware/sonar/Sonar.h"
#include "model/hardware/led/Led.h"

#include "Arduino.h"
#include "constants/Constants.h"

class SonarPeopleDetectionSystem{
    private: 
        Sonar* sonar;
        bool isPresent;
        Led* led;
        int ledPin;
        int trigPin;
        int echoPin;
        float distance;
    public: 
    SonarPeopleDetectionSystem(int ledPin, int echoPin, int trigPin);
    void init();
    void detectPresence();
    void turnOnLed();
    void turnOffLed();
    bool getPresence();
};




#endif