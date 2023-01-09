#ifndef __SERIALCOMSHANDLER__
#define __SERIALCOMSHANDLER__

#include "DataSerialization/DataDeSerializer.h"
#include "DataSerialization/DataSerializer.h"

class SerialComsHandler{
    private:
        DataDeSerializer deSerializer;
        DataSerializer serializer;
        String part;
        int value;
    public:
        //SerialComsHandler();
        String getPart();
        int getValue();
        bool read();
        void write(String key, int value);
        void writeStr(String string);
};



#endif