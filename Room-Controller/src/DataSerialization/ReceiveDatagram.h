#ifndef __RECEIVEDATAGRAM__
#define __RECEIVEDATAGRAM__

class ReceiveDatagram{
    private:
        int lightValue;
        int servoAngle;
    public:
        ReceiveDatagram(int lightValue, int servoAngle);
        int getLightValue();
        int getServoAngle();
};





#endif