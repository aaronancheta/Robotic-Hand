#include<Servo.h>

int pos = 0; // initialize position as 0

Servo myservo; // create servo object
void setup()
{
    pinMode(2, INPUT); //set pin 2 as an input pin
    pinMode(3, INPUT); // set pin 3 as an input pin
    myservo.attach(9); // attaches the servo on pin 9 to a servo object
}

void loop() 
{  
  // pulls string so hand can grab; turns servo clockwise
  while (digitalRead(2) == HIGH && pos < 360) 
  {
      pos++; // adds to 'pos' variable when button assigned to pin 2 is held down and it is not already turned clockwise all the way
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(15); // waits 15 ms for the servo to reach the position
  }
  
  // unwraps string so hand can let go; turns servo counter clockwise
  while (digitalRead(3) == HIGH && pos > 0) 
  {
      pos--; // decerements from 'pos' variable when button assigned to pin 3 is held down and it is not already turned counter clockwise all the way
      myservo.write(pos);  // tell servo to go to position in variable 'pos'
      delay(15); // waits 15 ms for the servo to reach the position
  }
}

