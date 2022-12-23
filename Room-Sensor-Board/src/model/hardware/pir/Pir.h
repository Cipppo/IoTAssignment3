#ifndef __PIR__
#define __PIR__

class Pir{
    private:
        int pin;
        bool scan();
    public:
        Pir(int pin);
        void calibrate();
        bool detect();
};

#endif