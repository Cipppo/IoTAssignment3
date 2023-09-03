#ifndef __LOGICLDS__
#define __LOGICLDS__

#include "functionalities/LightDetectionSystem/LightDetectionSystem.h"
#include "Arduino.h"
#include "constants/Constants.h"

void initLDS(int photoresPin);
void tickLDS();
int getLightValue();
float getLightInVoltValue();

#endif