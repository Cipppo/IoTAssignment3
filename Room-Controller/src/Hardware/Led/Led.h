
#ifndef __LED__
#define __LED__

#include "Hardware/Component/Component.h"


class Led: public Component{
    private:
        int pin;
    public:
        Led(int pin);
        void turnOn();
        void turnOff();
        int getPin();
        int readValue();
};

#endif