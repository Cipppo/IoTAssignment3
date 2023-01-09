#include "ReceiveDatagram.h"


ReceiveDatagram::ReceiveDatagram(int lightValue, int servoAngle){
    this->lightValue = lightValue;
    this->servoAngle = servoAngle;
}

int ReceiveDatagram::getLightValue(){
    return this->lightValue;
}

int ReceiveDatagram::getServoAngle(){
    return this->servoAngle;
}