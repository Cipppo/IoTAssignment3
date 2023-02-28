#ifndef __DATASERIALIZER__
#define __DATASERIALIZER__

#include <ArduinoJson.h>

class DataSerialization{
private:
    int JsonSerializer();
public:
    String serialize(String component, int value);
};



#endif