# IoTAssignment3
The assignment goal is to design a smart room system.
The system includes:

### Room Sensor Board (ESP)
It keep tracks the actual state of the room using sensors.
It uses MQTT protocol to communicate to the main RoomService hosted on PC.

### Room Service (BackEnd)
Main node of the system, it retrieves all the informations from the room.

### Room Dashboard (FrontEnd)
It shows the room state.

### Room Controller (Arduino)
Manages the lights and the roller blinds, it's possible to control it from the Android Application and from the Room Dashboard.

### Room Mobile App
It gives the opportunity to control the roller blinds and the lights inside the room.


## Main Systems

### Light System
If the room is empty, the lights turn off.
If someone enters the room and the lights are off, the lights will turn on.
Lights can be turned on even using the Dashboard or the Mobile App.

### Roller Blinds System
The rollers blinds will raise only after 8.00 A.M. if someone enters the room.
The roller blinds will close only after 7.00 P.M. only if the room is empty, if it's not empty they will close as soon as possible.
They can be controlled by the Dashboard or the Mobile App even partially.

