#include <AFMotor.h>
#include <SoftwareSerial.h>

//Left and Right Motor initialize (can use more motors)
AF_DCMotor LMOTOR(4);
AF_DCMotor RMOTOR(3);

//Bluetooth TX and RX initialize to pin 9 and 10 (unused servo pins on L239D motor shield...should replace to unused analog pins)
SoftwareSerial BT(9,10);

void setup() {
  Serial.begin(9600);

  //Bluetooh HC-06 communication initialize
  BT.begin(9600);
  Serial.println("BT ready!");
  
  //Motor setup
  LMOTOR.setSpeed(0);
  RMOTOR.setSpeed(0);

  LMOTOR.run(RELEASE);
  RMOTOR.run(RELEASE);
  Serial.println("Motors ready!");
}

char c;
char lastc;
int delayTimer = 25;

void mloop(){
  delay(10);
}

void loop() {
  //Serial.println("Bluetooth Read");
  if (BT.available()){
    c=(BT.read());
    Serial.println(c);
    selector(c);
  }
  else{
    selector(lastc);
  }
  lastc = c;
}

//picks motor function
void selector(char choice){
  switch(choice){
    case 'F':
      forward();
    case 'B':
      backward();
    case 'L':
      left();
    case 'R':
      right();
    case 'S':
      stopped();
    default:
      break;
 }
}

//direction
int f = FORWARD;
int b = BACKWARD;
void forward(){
  LMOTOR.run(b);
  RMOTOR.run(b);
  LMOTOR.setSpeed(200);
  RMOTOR.setSpeed(200);
  //delay(delayTimer);
}

void backward(){
  LMOTOR.run(f);
  RMOTOR.run(f);
  LMOTOR.setSpeed(200);
  RMOTOR.setSpeed(200);
  //delay(delayTimer);
}

void left(){
  LMOTOR.run(b);
  RMOTOR.run(f);
  LMOTOR.setSpeed(127);
  RMOTOR.setSpeed(127);
  //delay(delayTimer);
}

void right(){
  LMOTOR.run(f);
  RMOTOR.run(b);
  LMOTOR.setSpeed(127);
  RMOTOR.setSpeed(127);
  //delay(delayTimer);
}

void stopped(){
  LMOTOR.run(RELEASE);
  RMOTOR.run(RELEASE);
  LMOTOR.setSpeed(0);
  RMOTOR.setSpeed(0);
  //delay(delayTimer);
}

