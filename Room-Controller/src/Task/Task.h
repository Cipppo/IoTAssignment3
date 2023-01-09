#ifndef __TASK__
#define __TASK__

class Task{
    virtual void init() = 0;
    virtual void tick() = 0;
};

#endif