#include <Arduino.h>
#include <ArduinoJson.h>

#include "Constants/Constants.h"
#include "Hardware/Led/Led.h"
#include "DataSerialization/DataDeSerializer.h"

Led* led;
DataDeSerializer deSerializer;

void setup() {
  Serial.begin(9600);
  led = new Led(LED_PIN);
}

void loop() {
  String line = Serial.readStringUntil("\n");
  if(line != ""){
    deSerializer.deSerialize(line);

    int valore = deSerializer.get("value");

    if(valore == 0 && led->readValue() == HIGH){
      digitalWrite(led->getPin(), LOW);
    }else if (valore == 1 && led->readValue() == LOW) {
      digitalWrite(led->getPin(), HIGH);
    }
  }


}