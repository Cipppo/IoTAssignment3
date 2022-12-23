#ifndef __MQTTCLIENT__
#define __MQTTCLIENT__

#include <PubSubClient.h>


class MQTTClient{
    private:
        PubSubClient* client;
        String clientId;
        char* mqttServer;
        char* topic;
        int port;
    public:
        MQTTClient();
        void setup();
        void subscribe();
        void sendMessage(String msg);
        bool isClientConnected();
        void connect();


};




#endif