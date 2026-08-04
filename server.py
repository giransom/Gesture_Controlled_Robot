from flask import Flask, request, send_file
import os

app = Flask(__name__)

latest_image = "latest.jpg"


@app.route("/")
def home():
    return "ESP32 Camera Server Running"


@app.route("/upload", methods=["POST"])
def upload():
    image = request.data

    with open(latest_image, "wb") as f:
        f.write(image)

    return "OK"


@app.route("/latest.jpg")
def latest():
    if os.path.exists(latest_image):
        return send_file(latest_image, mimetype="image/jpeg")

    return "No image yet", 404


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8080)