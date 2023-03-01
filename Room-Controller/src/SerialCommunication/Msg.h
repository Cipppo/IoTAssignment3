#ifndef __MSG__
#define __MSG__


#include "Arduino.h"



class Msg{
    private:
        String content;
    public:
        Msg(String content);
        String getContent();
};



#endif