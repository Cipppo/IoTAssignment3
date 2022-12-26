
from flask import Flask, render_template, request, jsonify
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

#-------------ARDUINO-----------
ser = serial.Serial(port="/dev/ttyACM0", baudrate=9600)
systems = [0]

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
    app.run(port=5555)

def arduino_handler():
    lastread = systems[0]
    while True:
        if(systems[0] != lastread):
            data = create_JSON_data("lights", systems[0])
            ser.write(data.encode())
            lastread = systems[0];
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
    content = request.json
    print(content["value"])
    return content["value"]

startAll()

