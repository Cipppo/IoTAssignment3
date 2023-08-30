#ifndef __SERIALMSGHANDLER__
#define __SERIALMSGHANDLER__

#include "Arduino.h"
#include "Msg.h"


class SerialMsgHandler{
    public:
        Msg* currentMsg;
        bool msgAvailable;
        void init();
        bool isMsgAvailable();
        Msg* receiveMsg();
        void serialEvent();
        void sendMsg(String msg);

};

extern SerialMsgHandler MsgService;


#endif