#ifndef __BTTRANSMITTER__
#define __BTTRANSMITTER__

#include "Hardware/Component/Component.h"
#include <SoftwareSerial.h>
#include <Wire.h>
#include "SerialCommunication/Msg.h"

class BTTransmitter : public Component{
    private:
        int rxPin;
        int txPin;
        SoftwareSerial* channel;
        Msg* availableMessage;
        char* name;
    
    public:
        BTTransmitter(int rxPin, int txPin, char* name);
        void init();
        bool isAvailable();
        Msg* read();
        void write(Msg string);
};







#endif