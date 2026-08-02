#include <SoftwareSerial.h>


SoftwareSerial BTSerial(2, 3); // RX, TX


void setup() {
Serial.begin(9600);
BTSerial.begin(38400);   // Typical AT mode baud rate


Serial.println("HC-05 AT Mode Test");
Serial.println("Type AT commands below:");
}


void loop() {
// Send Serial Monitor input to HC-05
if (Serial.available()) {
  BTSerial.write(Serial.read());
}


// Send HC-05 responses to Serial Monitor
if (BTSerial.available()) {
  Serial.write(BTSerial.read());
}
}
