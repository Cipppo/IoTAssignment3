#ifndef __CONTROLLER__ 
#define __CONTROLLER__

#include "Task/Task.h"
#include "Timer/Timer.h"
#include "Hardware/Servo/Servo.h"
#include "Hardware/Led/Led.h"
#include "Constants/Constants.h"
#include "SerialCommunication/SerialMsgHandler.h"
#include <ArduinoJson.h>
#include "Hardware/BTTtransmitter/BTTransmitter.h"


class Controller : Task{
    private:
        Timer* timer;   
        SerialMsgHandler* msgHandler;
        Servo* servo;
        Led* led;
        BTTransmitter* bluetooth;
        DynamicJsonDocument *serialMsg;
        SoftwareSerial* channel;
        DynamicJsonDocument *bluetoothMessage;
    public:
        Controller();
        void init();
        void tick();
        Timer* getTimer();
        bool readSerialMessage();
        String readBTMessage();
};

#endif