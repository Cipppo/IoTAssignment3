#ifndef __SONARPEOPLEDETECTIONLOGIC__
#define __SONARPEOPLEDETECTIONLOGIC__

#include <Arduino.h>
#include "functionalities/peopleDetectionSystem/SonarPeopleDetectionSystem.h"
#include "constants/Constants.h"

void initSPDS(int ledPin, int echoPin, int trigPin);
void tickSPDS();
bool getPresence();

#endif