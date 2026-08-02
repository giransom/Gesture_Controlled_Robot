#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3);  // RX, TX

void setup() {
 Serial.begin(115200);
 BT.begin(38400);
}

void loop() {

 if (BT.available()) {
   String msg = BT.readStringUntil('\n');

   Serial.print("Received: ");
   Serial.println(msg);
 }

}
