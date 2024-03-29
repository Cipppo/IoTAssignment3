
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
client = mqtt_client.Client(client_id)

#-------------FLASK-------------
app = Flask(__name__)
CORS(app)

#-------------ARDUINO-----------
ser = serial.Serial(port="/dev/ttyACM0", baudrate=9600)
light = 0
servoAlpha = 0
lightLevel = 0
detectedLight = 0
people = 0
opened = False
overrideLights = 0

def create_JSON_data(lightValue, servoValue):
    data = {
        "Light": lightValue, 
        "Servo": servoValue,
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
    if(servoAlpha < 180):
        return False
    else:
        return True

def is_daytime():
    if(int(get_hours()) >= 8 and int(get_hours()) < 19):
        return True
    else:
        return False 

def arduino_handler():
    global servoAlpha, opened, detectedLight, overrideLights
    lastLightRead = light
    lastServoRead = servoAlpha
    while True:
        if(detectedLight == 0 and is_daytime() and people == 1 and overrideLights == 0):
            data = create_JSON_data(1, servoAlpha)
            ser.write(data.encode())
            lastLightRead = 1
            overrideLights = 1
            print(data)
        if(people == 0 and is_daytime() and overrideLights == 1):
            data = create_JSON_data(0, servoAlpha)
            ser.write(data.encode())
            lastLightRead = 0
            overrideLights = 0
        if(light != lastLightRead and overrideLights == 0):
            data = create_JSON_data(light, servoAlpha)
            ser.write(data.encode())
            lastLightRead = light
            print(data)
            print("yo")
        if((not is_servo_open() and is_daytime() and opened == False)):
            servoAlpha = 180
            opened = True
            data = create_JSON_data(light, servoAlpha)
            print("Detected Morning opening")
            ser.write(data.encode())
            lastServoRead = servoAlpha
            print(data)
        if(is_servo_open() and not is_daytime() and opened == True and people == 0):
            servoAlpha = 180
            opened = False
            data = create_JSON_data(light, servoAlpha)
            print("Detected night close!")
            ser.write(data.encode())
            lastServoRead = servoAlpha
            print(data)
        if(lastServoRead != servoAlpha):
            data = create_JSON_data(light, servoAlpha)
            ser.write(data.encode())
            lastServoRead = servoAlpha
            print(data)
        time.sleep(0.2)
        



def startAll():
    server_thread = threading.Thread(target=server_handler).start()
    mqtt_thread = threading.Thread(target=mqtt_handler).start() 
    arduino_thread = threading.Thread(target=arduino_handler).start()

def connect_mqtt():
    global client
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect.")
    client.on_connect = on_connect
    client.connect(broker, port)
    return client

def checkMQTTConnection():
    global client
    if(client.is_connected()):
        return True
    else:
        return False

def subscribe_mqtt(client: mqtt_client):
    def on_message(client, userdata, msg):
        global detectedLight, people
        print(f"Received `{msg.payload.decode()}` from `{msg.topic}` topic")
        data = msg.payload.decode()
        data = json.loads(data)
        component = data['component']
        value = data['value']
        if(component == 'Light'):
            detectedLight = value
        elif(component == "Pir"):
            people = value

    client.subscribe(topic)
    client.on_message = on_message

@app.route("/api/led")
def led():
    global light
    status = request.args.get("LED")
    light = int(status)
    return status

@app.route("/api/slider", methods=['POST'])
def slider():
    global servoAlpha
    content = request.json
    data = content["body"]
    data = json.loads(data)
    servoAlpha = int(data["value"]) * 1.8
    return data["value"]


@app.route("/api/debug")
def debug():
    global light, servoAlpha, detectedLight
    data = {
        "Light" : light, 
        "Servo" : servoAlpha, 
        "LightLevel" : detectedLight,
        "People" : people,
    }
    return data

@app.route("/api/connection/check", methods=['POST'])
def checkConnection():
    if(checkConnection()):
        return 1
    else:
        return 0

    

startAll()

