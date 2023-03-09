#ifndef __SERIALMSGHANDLER__
#define __SERIALMSGHANDLER__

#include "Arduino.h"
#include "Msg.h"
#include "DataSerialization/ReceiveDatagram.h"
#include "DataSerialization/DataDeSerializer.h"

class SerialMsgHandler{
    private:
        ReceiveDatagram* datagram;
        DataDeSerializer* deSerializer;
    public:
        SerialMsgHandler();
        bool getMessage();
        int getLightValue();
        int getServoValue();


};




#endif