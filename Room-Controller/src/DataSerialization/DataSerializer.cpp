#include "DataSerializer.h"


void DataSerializer::serialize(String component, int value){
    String json;
    DynamicJsonDocument doc(256);
    doc["component"] = component;
    doc["value"] = value;
    serializeJson(doc, json);
    Serial.println(json);
}

