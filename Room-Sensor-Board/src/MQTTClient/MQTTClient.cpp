#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "Constants/Constants.h"
#include "MQTTClient.h"

MQTTClient::MQTTClient(char* mqttServer, String topic, int port){
    randomSeed(micros());
    this->mqttServer = mqttServer;
    this->topic = topic;
    this->port = port;
}

void MQTTClient::setup(){
    WiFiClient espclient;
    this->client = new PubSubClient(espclient);
    this->client->setServer(this->mqttServer, this->port);

}

bool MQTTClient::isClientConnected(){
    return this->client->connected();
}

void MQTTClient::subscribe(){
    client->subscribe(this->topic.c_str());
}

void MQTTClient::sendMessage(String msg){
    if(!isClientConnected()){
        this->connect();
    }
    int msg_length = msg.length() + 1;
    char out[msg_length];
    this->client->publish(this->topic.c_str(), out);
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