#ifndef __WIFINODE__
#define __WIFINODE__




class WiFiNode{
    private:
        char* ssid;
        char* password;
    public:
        WiFiNode(char* ssid, char* password);
        void connect();
        bool isConnected();
};









#endif