#ifndef __DATADESERIALIZER__
#define __DATADESERIALIZER__

#include <ArduinoJson.h>

class DataDeSerializer{
    private:
        StaticJsonDocument<200> doc;
    public:
        void deSerialize(String serializedData);
        int get(String key);
};


#endif