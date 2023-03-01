#include "SerialMsgHandler.h"
#include "Arduino.h"



String content;
SerialMsgHandler MsgService;

bool SerialMsgHandler::isMsgAvailable(){
  this->serialEvent();
  return msgAvailable;
}

Msg* SerialMsgHandler::receiveMsg(){
  if (msgAvailable){
    Msg* msg = currentMsg;
    msgAvailable = false;
    currentMsg = NULL;
    content = "";
    return msg;  
  } else {
    return NULL; 
  }
}

void SerialMsgHandler::init(){
  Serial.begin(9600);
  content.reserve(256);
  content = "";
  currentMsg = NULL;
  msgAvailable = false;  
}

void SerialMsgHandler::serialEvent() {
  /* reading the content */
  while (Serial.available()) {
      content = Serial.readString();
      MsgService.currentMsg = new Msg(content);
      MsgService.msgAvailable = true;   
  }
}