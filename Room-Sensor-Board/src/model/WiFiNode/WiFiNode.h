#ifndef __WIFINODE__
#define __WIFINODE__




class WiFiNode{
    private:
        char* ssid;
        char* password;
    public:
        WiFiNode();
        void connect();
        void setup();
        bool isConnected();
};









#endif