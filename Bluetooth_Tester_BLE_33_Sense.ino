#include <Arduino_BMI270_BMM150.h>

#define BT_Serial Serial1

float x, y, z;

int flag = 0;

void setup() {

  Serial.begin(115200);   // USB Serial Monitor
  BT_Serial.begin(9600);  // HC-05 data mode

  while (!Serial);

  Serial.println("Nano 33 BLE Sense Controller");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.println("IMU Ready");
}


void loop() {

  Read_accelerometer();


  // Forward
  if (x < -0.8 && flag == 0) {
    flag = 1;
    BT_Serial.write('f');
    Serial.println("Forward");
  }


  // Backward
  if (x > 0.8 && flag == 0) {
    flag = 1;
    BT_Serial.write('b');
    Serial.println("Backward");
  }


  // Left
  if (y < -0.8 && flag == 0) {
    flag = 1;
    BT_Serial.write('l');
    Serial.println("Left");
  }


  // Right
  if (y > 0.8 && flag == 0) {
    flag = 1;
    BT_Serial.write('r');
    Serial.println("Right");
  }


  // Stop
  if ((x > -0.3 && x < 0.3) &&
      (y > -0.3 && y < 0.3) &&
      flag == 1) {

    flag = 0;
    BT_Serial.write('s');
    Serial.println("Stop");
  }


  delay(100);
}


void Read_accelerometer() {

  if (IMU.accelerationAvailable()) {

    IMU.readAcceleration(x, y, z);

    Serial.print("X: ");
    Serial.print(x);

    Serial.print("\tY: ");
    Serial.print(y);

    Serial.print("\tZ: ");
    Serial.println(z);
  }
}
