#ifndef __CONSTANTS__
#define __CONSTANTS__

//---WIFI---
#define SSID "FBIVan"
#define PASSWORD "12345678"

//--MQTT--
#define RECONNECTION_DELAY 3000
#define MQTT_SERVER "broker.mqtt-dashboard.com"
#define TOPIC "light/mqtt"
#define PORT 1883

//--PIR--
#define CALIBRATION_TIME 10
//D5
#define PIR_PIN 14 

//--LED--
//D3
#define LED_PIN 0

//PHOTORESISTOR
//D4
#define PHOTO_PIN 2 

//--TIMER--
#define TIMER_SAMPLING pow(10, 6)


#endif