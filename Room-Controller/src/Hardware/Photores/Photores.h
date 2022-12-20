#ifndef __PHOTORES__
#define __PHOTORES__

#include "Hardware/Component/Component.h"
#include "Constants/Constants.h"

class Photores: public Component{
    private:
        int pin;
    public:
        Photores(int pin);
        double readValue();
        int getPin();
};



#endif