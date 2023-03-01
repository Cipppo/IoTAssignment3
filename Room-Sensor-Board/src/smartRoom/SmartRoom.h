#ifndef __SMARTROOM__
#define __SMARTROOM__

#include "Logic/lightDetectionLogic/LogicLDS.h"
#include "Logic/peopleDetectionLogic/LogicPDS.h"
#include "constants/Constants.h"
#include "Arduino.h"



class SmartRoom{

    public:
        SmartRoom();
        void init();
        void tick();
        int isLight();
        int getPeople();
    
};








#endif