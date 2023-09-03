#include "SonarPeopleDetectionLogic.h"


SonarPeopleDetectionSystem* spds;

void initSPDS(int ledPin, int echoPin, int trigPin){
    spds = new SonarPeopleDetectionSystem(ledPin, echoPin, trigPin);
    spds->init();
}

void tickSPDS(){
    spds->detectPresence();
}

bool getPresence(){
    Serial.println(spds->getPresence());
    return true;
}