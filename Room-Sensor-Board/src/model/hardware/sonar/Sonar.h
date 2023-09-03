#ifndef __SONAR__
#define __SONAR__

#include <Arduino.h>
class Sonar{
    private:
        int trigPin;
        int pin;
        void sendImpulse();
    public:
        Sonar(int trigPing, int echoPin);
        float readValue();
        int getEchoPin();
        int getTrigPin();
};

#endif