#ifndef __DATASERIALIZER__
#define __DATASERIALIZER__

#include <ArduinoJson.h>

class DataSerializer{
private:
    int JsonSerializer();
public:
    void serialize(String component, int value);
};



#endif