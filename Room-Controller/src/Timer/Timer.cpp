#include "Timer.h"

Timer::Timer(){
    this->timer = new TimerOne();
    this->timer->initialize(SAMPLING_TIME);
    this->state = STOP;
}

TimerOne* Timer::getTimerOne(){
    return this->timer;
}

void Timer::waitForTheNextTick(){
    while(this->state == STOP){ }
    this->state = STOP;
}

void Timer::changeState(){
    this->state = this->state == STOP ? GO : STOP;
}

TimerState Timer::getState(){
    return this->state;
}