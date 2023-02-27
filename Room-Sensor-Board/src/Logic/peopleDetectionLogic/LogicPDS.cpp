#include "LogicPDS.h"


PeopleDetectionSystem* pds;


void initPDS(int pirPin, int ledPin){
    pds = new PeopleDetectionSystem(pirPin, ledPin);
    pds->init();
}

void tickPDS(){
    pds->detectPresence();
}

bool getPresence(){
    return pds->getPresence();
}

