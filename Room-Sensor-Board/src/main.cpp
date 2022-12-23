#include <Arduino.h>
#include<ESP8266WiFi.h>


#include "model/wifiNode/WiFiNode.h"
#include "constants/Constants.h"
#include "model/mqttClient/MQTTClient.h"
#include "model/hardware/pir/Pir.h"

Pir* pir;





void setup() {
    Serial.begin(9600);
    pinMode(PIR_PIN,INPUT);

    
    //give the sensor some time to calibrate
    Serial.print("Calibrating sensor... ");
    for(int i = 0; i < CALIBRATION_TIME; i++){
        Serial.print(".");
        delay(1000);
    }
    Serial.println(" done");
    Serial.println("PIR SENSOR READY.");
    delay(50);

}

void loop() {
    
  int detected = digitalRead(PIR_PIN);
  if (detected == HIGH){
    Serial.println("detected!");  
  }

}