
#include "DataSerializer.h"
#include <ArduinoJson.h>

String DataSerializer::serialize(String key, int value){
    this->doc[key] = value;
    char jsonStr[200];
    serializeJson(this->doc, jsonStr);
    return String(jsonStr);
}

