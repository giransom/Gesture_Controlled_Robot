#include <Wire.h>
#include <SoftwareSerial.h>

// Bluetooth
SoftwareSerial BT(2, 3); // RX, TX

const int MPU = 0x68;

int16_t AcX, AcY, AcZ;

char lastCommand = 's';

void setup() {
  Serial.begin(9600);
  BT.begin(38400);

  Wire.begin();

  // Wake up MPU6050
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Serial.println("System Ready");
}

void loop() {

  readMPU();

  char command = getDirection(AcX, AcY);

  // send ONLY if changed (prevents spam + lag)
  if (command != lastCommand) {
    lastCommand = command;

    BT.write(command);

    Serial.print("Sent: ");
    Serial.println(command);
  }

  delay(100);
}

void readMPU() {

  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU, 6, true);

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();

  // normalize to readable range
  AcX = map(AcX, -1700, 1700, 0, 180);
  AcY = map(AcY, -1700, 1700, 0, 180);

  Serial.print("X: ");
  Serial.print(AcX);
  Serial.print("  Y: ");
  Serial.println(AcY);
}

char getDirection(int x, int y) {

  // Forward
  if (x < 60) {
  Serial.println('f');
  return 'f';}

  // Backward
  if (x > 130){
  Serial.println('b');
  return 'b';
  } 

  // Left
  if (y < 60){
  Serial.println('l');  
  return 'l';}

  // Right
  if (y > 130) {
  Serial.println('r');  
  return 'r';}

  // Center (stop)
  return 's';
}