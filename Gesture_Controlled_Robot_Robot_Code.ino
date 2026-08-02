#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(2, 3); // RX, TX

#define in1 5 //Motor1 L298 Pin in1
#define in2 6 //Motor1 L298 Pin in1
#define in3 9 //Motor2 L298 Pin in1
#define in4 10 //Motoe2 L298 Pin in1

char bt_data; //variable to receive data from the serial port
int Speed = 150; //Write the Duty Cycle 0 to 255 Enable Pins for Motor Speed

void setup() {
  // put your setup code here, to run once:

Serial.begin(115200); //start serial communicartiosn at 9600bps
BT_Serial.begin(38400);

pinMode(in1, OUTPUT); //declare as output for L298 Pin in1
pinMode(in2, OUTPUT); //declare as output for L298 Pin in2
pinMode(in3, OUTPUT); //declare as output for L298 Pin in3
pinMode(in4, OUTPUT); //declare as output for L298 Pin in4

delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
if(BT_Serial.available() > 0){
  //if some data is sent, reads it and saves in state
  bt_data = BT_Serial.read();
  Serial.println(BT_Serial.read());
}

if(bt_data == 'f'){ //makes DC motors move forwards
  forward(); Speed=180;}
else if(bt_data == 'b'){ //makes motors move backwards
  backward(); Speed=180;}
else if(bt_data == 'l'){ //makes motors move turn left
  turnLeft(); Speed=250;}
else if(bt_data == 'r'){ //makes motors turn right
  turnRight(); Speed=250;}
else if(bt_data == 's'){ //makes motors stop
  stop();}


delay(50);
}

void forward(){
  digitalWrite(in1, LOW); //Right Motor forward Pin
  digitalWrite(in2, HIGH); //Right Motor backward Pin
  digitalWrite(in3, HIGH); //Left Motor backward Pin
  digitalWrite(in4, LOW); //Left Motor forward Pin
}

void backward(){
  digitalWrite(in1, HIGH); //Right Motor forward Pin
  digitalWrite(in2, LOW); //Right Motor backward Pin
  digitalWrite(in3, LOW); //Left Motor backward Pin
  digitalWrite(in4, HIGH); //Left Motor forward Pin
}

void turnRight(){
  digitalWrite(in1, HIGH); //Right Motor forward Pin
  digitalWrite(in2, LOW); //Right Motor backward Pin
  digitalWrite(in3, HIGH); //Left Motor backward Pin
  digitalWrite(in4, LOW); //Left Motor forward Pin
}

void turnLeft(){
  digitalWrite(in1, LOW); //Right Motor forward Pin
  digitalWrite(in2, HIGH); //Right Motor backward Pin
  digitalWrite(in3, LOW); //Left Motor backward Pin
  digitalWrite(in4, HIGH); //Left Motor forward Pin
}

void stop(){
  digitalWrite(in1, LOW); //Right Motor forward Pin
  digitalWrite(in2, LOW); //Right Motor backward Pin
  digitalWrite(in3, LOW); //Left Motor backward Pin
  digitalWrite(in4, LOW); //Left Motor forward Pin
}