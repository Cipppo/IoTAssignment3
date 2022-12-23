#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "constants/Constants.h"
#include "MQTTClient.h"

static WiFiClient espclient;

MQTTClient::MQTTClient(){
    randomSeed(micros());
    this->mqttServer = MQTT_SERVER;
    this->topic = TOPIC;
    this->port = PORT;
    this->setup();
}

void MQTTClient::setup(){
    this->client = new PubSubClient(espclient);
    this->client->setServer(this->mqttServer, this->port);

}

bool MQTTClient::isClientConnected(){
    return this->client->connected();
}

void MQTTClient::subscribe(){
    client->subscribe(this->topic);
}

void MQTTClient::sendMessage(String msg){
    if(!isClientConnected()){
        this->connect();
    }
    int msg_length = msg.length() + 1;
    char out[msg_length];
    msg.toCharArray(out, msg_length);
    this->client->publish(this->topic, out);
}

void MQTTClient::connect(){
    while(!this->isClientConnected()){
        Serial.println("Attempting MQTT connection...");
        this->clientId = String(this->mqttServer) + String(random(0xffffff), HEX);
        if(this->client->connect(clientId.c_str())){
            Serial.println("Connected !");
            this->subscribe();
        }else{
            Serial.print("Failed, rc=");
            Serial.print(this->client->state());
            Serial.println("Trying again in 3 seconds");
            delay(RECONNECTION_DELAY);
        }
    }
}