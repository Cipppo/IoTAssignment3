#ifndef __DATASERIALIZER__
#define __DATASERIALIZER__

#include <ArduinoJson.h>

class DataSerializer{
private:
    StaticJsonDocument<200> doc;
public:
    String serialize(String key, int value);
};



#endif