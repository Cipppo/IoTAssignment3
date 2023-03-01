#ifndef __SERIALMSGHANDLER__
#define __SERIALMSGHANDLER__

#include "Arduino.h"
#include "Msg.h"

class SerialMsgHandler{
    public:
        Msg* currentMsg;
        Msg* message;
        bool msgAvailable;
        void init();
        bool isMsgAvailable();
        Msg* receiveMsg();
        void serialEvent();


};




#endif