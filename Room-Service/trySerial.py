import serial
import json
import time
import threading

ser = serial.Serial(port="/dev/ttyACM0", baudrate=9600)


def create_JSON_data(lightVal, servoVal):
    data = {
        "Light": lightVal, 
        "Servo": servoVal,
    }
    json_str = json.dumps(data)
    #print(json_str + '\n')
    return json_str




def handleReceive():
    while True:

        if(ser.inWaiting() > 0):
            try:
                msg = ser.readline().decode()
                json_parsed = json.loads(msg)
                value = json_parsed['value']
                print(value)
            except Exception as e:
                print("Rotto")
        time.sleep(0.5)

def handleSend():
        data = create_JSON_data(50, 80)
        print("Sending: " + data)
        ser.write(data.encode())
        time.sleep(0.2)


def run():
    #threading.Thread(target=handleReceive).start()
    #threading.Thread(target=handleSend).start()
    handleSend()


run()

