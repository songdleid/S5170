//This code is to control the speed of a DC motor by a potentiometer using l298n driver
//We read the value from the analog input, calibrate it then inject to the module
//Refer to Surtrtech youtube channel for more information

#include <Servo.h>
Servo myservo;

int in1 = 8; //Declaring where our module is wired
int in2 = 9;
int ConA = 11;// Don't forget this is a PWM DI/DO
int speed1;
int val;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);  
  pinMode(11, OUTPUT);
  myservo.attach(3);
}

void TurnMotorA() {
  // Set the direction of the motor
  digitalWrite(in1, LOW);  // LOW for one direction
  digitalWrite(in2, HIGH); // HIGH for the opposite direction

  // Read the potentiometer value (0 to 1023)
  int potValue = analogRead(A0);
  
  // Scale the potentiometer value (0-1023) to a PWM range (0-255)
  // The map function scales the potentiometer value to the PWM range for motor control
  int speed1 = map(potValue, 0, 1023, 0, 255); //<---- Change these values to scale the pot (as in you want the motor to have max power at shorter range of motion)
  // Set the motor speed using PWM
  analogWrite(ConA, speed1);
}


void TurnServo(){
val = analogRead(A1);
val = map(val, 0, 1023, 0, 180);
myservo.write(val);
delay(15);
}

void loop() {
TurnMotorA(); //one function that keeps looping you can add another one with different direction or stop

TurnServo();

}
