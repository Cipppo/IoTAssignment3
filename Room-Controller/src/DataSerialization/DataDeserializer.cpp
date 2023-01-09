#include <ArduinoJson.h>


#include "DataDeSerializer.h"



void DataDeSerializer::deSerialize(String serializedData){
    DeserializationError error = deserializeJson(this->doc, serializedData);
    if(error){
        Serial.println("Si e' rotto o non e' stato ricevuto");
    }
}

int DataDeSerializer::get(String key){
    return this->doc[key];
}