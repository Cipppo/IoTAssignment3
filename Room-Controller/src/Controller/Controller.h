#ifndef __CONTROLLER__ 
#define __CONTROLLER__

#include "Task/Task.h"
#include "Timer/Timer.h"
#include "Hardware/Servo/Servo.h"
#include "Hardware/Led/Led.h"
#include "Constants/Constants.h"
#include "SerialCommunication/SerialMsgHandler.h"

class Controller : Task{
    private:
        Timer* timer;   
        SerialMsgHandler* msgHandler;
        Servo* servo;
        Led* led;
    public:
        Controller();
        void init();
        void tick();
        Timer* getTimer();
};

#endif