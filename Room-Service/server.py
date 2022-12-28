
from flask import Flask, render_template, request, jsonify
from flask_cors import CORS
import random
from paho.mqtt import client as mqtt_client
import time
import threading
import serial
import json

#-------------MQTT-------------
broker = 'broker.mqtt-dashboard.com'
port = 1883
topic = "light/mqtt"
client_id = f'python-mqtt-{random.randint(0, 1000)}'

#-------------FLASK-------------
app = Flask(__name__)
CORS(app)

#-------------ARDUINO-----------
ser = serial.Serial(port="/dev/ttyACM0", baudrate=9600)
systems = [0]
servoAlpha = 0
opened = False

def create_JSON_data(component, value):
    data = {
        "component": component, 
        "value": value,
    }
    json_str = json.dumps(data)
    #print(json_str + '\n')
    return json_str



def mqtt_handler():
    client = connect_mqtt()
    subscribe_mqtt(client)
    client.loop_forever()

def server_handler():
    app.debug = False
    app.run(port=5555)

def get_hours():
    t = time.localtime()
    return time.strftime("%H:%M:%S", t)[:2]

def is_servo_open():
    if(servoAlpha > 0):
        return True
    else:
        return False

def is_daytime():
    if(int(get_hours()) >= 8 and int(get_hours()) < 19):
        return True
    else:
        return False 

def arduino_handler():
    global servoAlpha, opened
    lastLightRead = systems[0]
    lastServoRead = servoAlpha
    while True:
        if(systems[0] != lastLightRead):
            data = create_JSON_data("lights", systems[0])
            ser.write(data.encode())
            lastLightRead = systems[0]
            print(data)
        if((not is_servo_open() and is_daytime() and opened == False)):
            servoAlpha = 180
            opened = True
            data = create_JSON_data("servo", servoAlpha)
            print("Detected Morning opening")
            ser.write(data.encode())
            lastServoRead = servoAlpha
            print(data)
        if(lastServoRead != servoAlpha):
            data = create_JSON_data("servo", servoAlpha)
            ser.write(data.encode())
            lastServoRead = servoAlpha
            print(data)
        time.sleep(0.2)
        



def startAll():
    server_thread = threading.Thread(target=server_handler).start()
    #mqtt_thread = threading.Thread(target=mqtt_handler).start() DISABLED FOR NO USING
    arduino_thread = threading.Thread(target=arduino_handler).start()

def connect_mqtt():
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect.")
    client = mqtt_client.Client(client_id)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client

def subscribe_mqtt(client: mqtt_client):
    def on_message(client, userdata, msg):
        print(f"Received `{msg.payload.decode()}` from `{msg.topic}` topic")
    client.subscribe(topic)
    client.on_message = on_message

@app.route("/api/led")
def led():
    status = request.args.get("LED")
    systems[0] = int(status)
    return status

@app.route("/api/slider", methods=['POST'])
def slider():
    global servoAlpha
    content = request.json
    data = content["body"]
    data = json.loads(data)
    servoAlpha = int(data["value"])
    return data["value"]

@app.route("/api/servoDebug", methods=["GET"])
def servoDebug():
    global servoAlpha
    content = request.args.get("servoDebug")
    servoAlpha = int(content)

@app.route("/api/timeDebug", methods=["GET"])
def timeDebug():
    content = request.args.get("time")
    return content
    

startAll()

