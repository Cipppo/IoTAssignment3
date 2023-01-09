import serial
import json
import time
import threading

ser = serial.Serial(port="/dev/ttyACM0", baudrate=9600)


def create_JSON_data(component, value):
    data = {
        "component": component, 
        "value": value,
    }
    json_str = json.dumps(data)
    #print(json_str + '\n')
    return json_str




def handleReceive():
    while True:

        line = ser.readline()
        line_s = line.decode()
        print("Ho tirato su questo dato: "+line_s)
        time.sleep(0.2)

def handleSend():
    while True:
        data = create_JSON_data("lights", 1)
        ser.write(data.encode())
        time.sleep(0.2)


def run():
    #threading.Thread(target=handleReceive).start()
    threading.Thread(target=handleSend).start()


run()