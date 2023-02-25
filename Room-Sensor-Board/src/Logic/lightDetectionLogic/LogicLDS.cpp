#include "LogicLDS.h"




LightDetectionSystem* lds;

void initLDS(int photoresPin){
    lds = new LightDetectionSystem(photoresPin);
    lds->init();
}

void tickLDS(){
    lds->readValue();
}

int getLightValue(){
    return lds->getPhotoresValue();
}

float getLightInVoltValue(){
    return lds->getPhotoresValueInVolt();
}