#ifndef __CONTROLLER__ 
#define __CONTROLLER__

#include "Task/Task.h"
#include "Timer/Timer.h"

class Controller : Task{
    private:
        Timer* timer;
    public:
        Controller();
        void init();
        void tick();
        Timer* getTimer();
};

#endif