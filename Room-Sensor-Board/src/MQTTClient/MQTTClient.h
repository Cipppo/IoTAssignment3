#ifndef __MQTTCLIENT__
#define __MQTTCLIENT__

#include <PubSubClient.h>


class MQTTClient{
    private:
        PubSubClient* client;
        String clientId;
        char* mqttServer;
        String topic;
        int port;
        void callback(char* topic, byte* payload, unsigned int length);
    public:
        MQTTClient(char* mqttServer, String topic, int port);
        void setup();
        void subscribe();
        void sendMessage(String msg);
        bool isClientConnected();
        void connect();


};




#endif