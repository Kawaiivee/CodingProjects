#include <Servo.h>

Servo servo;

unsigned long echo = 0;
int ultraSoundSignal = 3; // Ultrasound signal pin
unsigned long ultrasoundValue = 0;
int x = 0;

void setup()
{
  Serial.begin(9600);
  servo.attach(10);
  servo.write(0);
  pinMode(ultraSoundSignal, OUTPUT);
}

unsigned long ping()
{ 
  pinMode(ultraSoundSignal, OUTPUT); // Switch signalpin to output
  digitalWrite(ultraSoundSignal, LOW); // Send low pulse 
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignal, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignal, LOW); // Holdoff
  pinMode(ultraSoundSignal, INPUT); // Switch signalpin to input
  digitalWrite(ultraSoundSignal, HIGH); // Turn on pullup resistor
  // please note that pulseIn has a 1sec timeout, which may
  // not be desirable. Depending on your sensor specs, you
  // can likely bound the time like this -- marcmerlin
  // echo = pulseIn(ultraSoundSignal, HIGH, 38000)
  echo = pulseIn(ultraSoundSignal, HIGH); //Listen for echo
  ultrasoundValue = (echo / 58.138) * .39; //convert to CM then to inches
  return ultrasoundValue;
}

void loop()
{
  x = ping();
  Serial.println(x);
  if(x > 0){
    servo.write(2.75*x);
  }
  delay(250); //delay 1/4 seconds.
}
