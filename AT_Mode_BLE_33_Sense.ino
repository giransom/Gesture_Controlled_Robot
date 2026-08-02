void setup() {
  Serial.begin(9600);

  // Wait for Serial Monitor
  while (!Serial);

  // HC-05 AT mode baud rate
  Serial1.begin(38400);

  Serial.println("HC-05 AT Mode Test");
  Serial.println("Type AT commands below:");
}

void loop() {
  // Send Serial Monitor input to HC-05
  while (Serial.available()) {
    Serial1.write(Serial.read());
  }

  // Send HC-05 response to Serial Monitor
  while (Serial1.available()) {
    Serial.write(Serial1.read());
  }
}
