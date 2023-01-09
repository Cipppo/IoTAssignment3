#ifndef __DATADESERIALIZER__
#define __DATADESERIALIZER__

#include <ArduinoJson.h>
#include "ReceiveDatagram.h"

class DataDeSerializer{
    private:
        int JsonDeserializer();
    public:
        ReceiveDatagram* getValue();
};


#endif