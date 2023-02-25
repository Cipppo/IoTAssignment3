#ifndef __LIGHTDETECTIONSYSTEM__
#define __LIGHTDETECTIONSYSTEM__

#include "constants/Constants.h"
#include "model/hardware/led/Led.h"
#include "model/hardware/photoresistor/photores.h"
#include "Arduino.h"

class LightDetectionSystem{
    private:
        int photoresPin;
        Photores* photores;
    public:
        LightDetectionSystem(int photoresPin);
        void init();
        //PhotoResistor
        void readValue();
        //Getters
        Photores getPhotores();
        int getPhotoresPin();
        int getPhotoresValue();
        double getPhotoresValueInVolt();


};




#endif