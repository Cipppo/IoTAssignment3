#ifndef __PHOTORES__
#define __PHOTORES__



#include "constants/Constants.h"

class Photores{
    private:
        int pin;
    public:
        Photores(int pin);
        int readValue();
        int getPin();
};



#endif