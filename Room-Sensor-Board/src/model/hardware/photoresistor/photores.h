#ifndef __PHOTORES__
#define __PHOTORES__



#include "constants/Constants.h"

class Photores{
    private:
        int pin;
        int value;
        double valueInVolt;
    public:
        Photores(int pin);
        void readValue();
        int getValue();
        double getValueInVolt();
        int getPin();
};



#endif