#include "LogicPDS.h"


PeopleDetectionSystem* pds;


void initPDS(int pirPin, int ledPin){
    pds = new PeopleDetectionSystem(pirPin, ledPin);
    pds->init();
}

void tickPDS(){
    pds->detectPresence();
    if(pds->getPresence() == true){
        pds->turnOnLed();
    }else{
        pds->turnOffLed();
    }
}

bool getPresence(){
    return pds->getPresence();
}

