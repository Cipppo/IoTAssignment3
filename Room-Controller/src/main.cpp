#include <Arduino.h>
#include <ArduinoJson.h>

#include "Constants/Constants.h"
#include "Hardware/Led/Led.h"
#include "DataSerialization/DataDeSerializer.h"
#include "Hardware/Photores/Photores.h"
#include "SerialCommunication/SerialComsHandler.h"

#define PIN 2

SerialComsHandler* comsHandler;

void setup(){
  Serial.begin(9600);
}

void loop(){
  comsHandler->read();
  delay(1000);
};