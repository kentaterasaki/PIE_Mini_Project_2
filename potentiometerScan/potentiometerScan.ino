#include <Servo.h>  // add servo library

Servo servo_down;  // create servo object to control a servo
Servo servo_up;    // create servo object to control a servo
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A2;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9;  // Analog output pin that the LED is attached to


int sensorValue2 = 0;  // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)
int distance = 0;
float x = 0;
float y = 0;
int servo_angle = 0;

int potPin0 = A0;
int potPin1 = A1;
int val0;    // variable to read the value from the analog pin
int val1;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  servo_down.attach(5);  // attaches the servo on pin 5 to the servo object
  servo_up.attach(6); // attaches the servo on pin 5 to the servo object
}

int sensorToCm(int sensorValue){
 if (sensorValue > 560){
  distance = 0;
 }
 else if (sensorValue <95){
  distance = 0;
 }
 else { 
  distance = map(sensorValue, 95, 560, 20, 150);
 }
 return distance;
}
void loop() {

  //read Pot Value
  val0 = analogRead(potPin0);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = analogRead(potPin1);
  val0 = map(val0, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val1 = map(val1,0,1023,0,180);
  servo_down.write(val0);               // sets the servo position according to the scaled value
  servo_up.write(val1);                          // waits for the servo to get there read the analog in value:
  sensorValue2 = analogRead(analogInPin);

  Serial.print(sensorValue2);
  Serial.print(" ");
  // map it to the range of the analog out:
  // Serial.println(sensorValue2);
  outputValue = map(sensorValue2, 0, 1023, 0, 255);
  // change the analog out value:
  x=sensorValue2;
  x=pow(x,-1.017);
  //Serial.println(x);
  y = 12224*pow(sensorValue2,-1.017);
  Serial.println(y);
  analogWrite(analogOutPin, outputValue);
  delay(1000);

}


// 20 cm is output 128 sensor value is 520
// 150 cm is output 23 sensor value is 95 

