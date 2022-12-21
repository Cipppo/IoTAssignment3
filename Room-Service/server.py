
from flask import Flask, render_template, request, jsonify


app = Flask(__name__)


visited = 0

@app.route("/")
def home():
    global visited
    visited = visited + 1
    return "Hello, World!" + str(visited)
 

@app.route("/api/led")
def led():
    status = request.args.get("LED")
    return status

@app.route("/api/slider", methods=['POST'])
def slider():
    content = request.json
    print(content["value"])
    return content["value"]

app.run(port = 5555)