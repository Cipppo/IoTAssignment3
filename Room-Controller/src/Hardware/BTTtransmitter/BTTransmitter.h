#ifndef __BTTRANSMITTER__
#define __BTTRANSMITTER__

#include "Hardware/Component/Component.h"
#include <SoftwareSerial.h>
#include <Wire.h>

class BTTransmitter : public Component{
    private:
        int rxPin;
        int txPin;
        SoftwareSerial channel;
    
    public:
        BTTransmitter(int rxPin, int txPin, char name);
        bool isAvailable();
        char read();
        void write(char string);
};







#endif