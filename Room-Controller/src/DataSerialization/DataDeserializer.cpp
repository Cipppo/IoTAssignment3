#include "DataDeSerializer.h"


ReceiveDatagram* DataDeSerializer::getValue(){
    String json = Serial.readString();
    if(!json.equals("")){
        DynamicJsonDocument doc(256);
        deserializeJson(doc, json);
        int lightValue = doc["Light"];
        int servoValue = doc["Servo"];
        return new ReceiveDatagram(lightValue, servoValue);
    }
}
