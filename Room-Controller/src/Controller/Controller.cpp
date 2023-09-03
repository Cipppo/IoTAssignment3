#include "Controller.h"
#include "Arduino.h"


Controller::Controller(){
    this->timer = new Timer();
    this->init();
}

void Controller::init(){
    this->led = new Led(LED_PIN);
    this->servo = new Servo(SERVO_PIN);
    this->serialMsg = new DynamicJsonDocument(128);
    //this->bluetooth = new BTTransmitter(RX_PIN, TX_PIN);
    this->channel = new SoftwareSerial(RX_PIN, TX_PIN);
    this->channel->begin(9600);
    MsgService.init();

}

bool Controller::readSerialMessage(){
   if (MsgService.isMsgAvailable()){
    Msg* msg = MsgService.receiveMsg();
    char ar[256];
    msg->getContent().toCharArray(ar, msg->getContent().length());
    deserializeJson(*this->serialMsg, ar);
    delete msg;
    return true;
   }else{
    return false;
   }
}


void Controller::tick(){
    if(this->readSerialMessage()){
        String lightValue = (*this->serialMsg)[LIGHT];
        String servoValue = (*this->serialMsg)[SERVO];
        Serial.println(lightValue);
        Serial.println(servoValue);
        Serial.println("");
        if(lightValue.toInt() == ON){
            this->led->turnOn();
        }
        if(lightValue.toInt() == OFF){
            this->led->turnOff();
        }
        this->servo->setAngle(servoValue.toInt());
    }
    
    String message = "";
    while(this->channel->available() > 0){
        char messageIncoming = (char) this->channel->read();
        message = message + messageIncoming;
    }   
    if(message != ""){
        
        if(message == LEDON){
            this->led->turnOn();
        }else if(message == LEDOFF){
            this->led->turnOff();
        }else{
            int servoValue = (message.toInt() * 180) / 100 ;
            this->servo->setAngle(servoValue);
        }
        message = "";
    }

}

Timer* Controller::getTimer(){
    return this->timer;
}