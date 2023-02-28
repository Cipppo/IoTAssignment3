#include "SmartRoom.h"





void SmartRoom::init(){
    initLDS(PHOTO_PIN);
    initPDS(PIR_PIN, LED_PIN);
}

void SmartRoom::tick(){
    tickLDS();
    tickPDS();
}