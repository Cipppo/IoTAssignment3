#ifndef __SERIALCOMSHANDLER__
#define __SERIALCOMSHANDLER__

#include "DataSerialization/DataDeSerializer.h"

class SerialComsHandler{
    private:
        DataDeSerializer deSerializer;
        String part;
        int value;
    public:
        //SerialComsHandler();
        String getPart();
        int getValue();
        bool read();
};



#endif