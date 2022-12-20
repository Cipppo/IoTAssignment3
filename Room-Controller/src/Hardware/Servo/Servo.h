#ifndef __SERVO__
#define __SERVO__


#include "Hardware/Component/Component.h"
#include "Constants/Constants.h"
#include "ServoTimer2.h"


class Servo: public Component{
    private:
        int pin;
        int angle;
        ServoTimer2* servoMotor;
    public:
        Servo(int pin);
        void setAngle(int angle);
        int getAngle();
};



#endif