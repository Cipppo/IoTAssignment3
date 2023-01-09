#ifndef __TIMER__
#define __TIMER__

#include <TimerOne.h>
#include "TimerState.h"
#include "Constants/Constants.h"

class Timer{
    private:
        TimerOne* timer;
        volatile TimerState state;
    public:
        Timer();
        TimerOne* getTimerOne();
        void waitForTheNextTick();
        void changeState();
        TimerState getState();
};

#endif