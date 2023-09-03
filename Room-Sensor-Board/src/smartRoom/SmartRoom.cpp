#include "SmartRoom.h"






void SmartRoom::init(){
    initLDS(PHOTO_PIN);
    //initPDS(PIR_PIN, LED_PIN);
}

void SmartRoom::tick(){
    tickLDS();
    //tickPDS();


}

int SmartRoom::isLight(){
    int value = getLightInVoltValue();
    Serial.println(value);
    if(value < MINIMUM_LIGHT_VALUE){
        return 0;
    }else{
        return 1;
    }
}

int SmartRoom::getPeople(){
    getPresence();
    return 1;
}
