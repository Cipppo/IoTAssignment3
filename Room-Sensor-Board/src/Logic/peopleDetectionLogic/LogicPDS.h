#ifndef __LOGICPDS__
#define __LOGICPDS__


#include "functionalities/peopleDetectionSystem/PeopleDetectionSystem.h"
#include "Arduino.h"
#include "constants/Constants.h"


void initPDS(int pirPin, int ledPin);
void tickPDS();
bool getPresence();



#endif