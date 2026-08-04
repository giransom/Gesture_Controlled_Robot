from flask import Flask, request
import numpy as np
import cv2

app = Flask(__name__)

# Store the newest image received
latest_frame = None

@app.route("/")
def home():
    return "ESP32 Camera Server Running!"

@app.route("/upload", methods=["POST"])
def upload():

    global latest_frame

    if request.data:

        img_array = np.frombuffer(request.data, np.uint8)

        frame = cv2.imdecode(img_array, cv2.IMREAD_COLOR)

        if frame is None:
            return "Invalid image", 400

        latest_frame = frame

        print("Frame received!")

        return "OK", 200

    return "No image received", 400


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)