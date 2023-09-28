#include <Servo.h>  // add servo library

Servo servo_down;  // create servo object to control a servo
Servo servo_up;    // create servo object to control a servo
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A2;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9;  // Analog output pin that the LED is attached to


int sensorValue2 = 0;  // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)
int distance = 0;

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

void loop() {

  // change the analog out value:
  analogWrite(analogOutPin, outputValue);
  for (int i = 50; i <= 80; i=i+1) {
    if (i%2==0){
      for (int j = 70; j >= 30; j-=1) {
      sensorValue2 = analogRead(analogInPin);
      outputValue = 12224*pow(sensorValue2,-1.017); // convert sensorValue to distance in cm
      if (outputValue > 20 and outputValue < 150){  // remove all values outside the range of the sensor
        outputValue = outputValue;
      }
      else {
        outputValue = 0;
      }
      Serial.print(j);
      Serial.print(" ");
      Serial.print(i);
      Serial.print(" ");
      Serial.println(outputValue);
      delay(1000);
      servo_down.write(i);        
      servo_up.write(j);
    }
    }
    else if(i%2==1) {
      for (int j = 20; j <= 90; j+=1) {
      sensorValue2 = analogRead(analogInPin);
      outputValue = 12224*pow(sensorValue2,-1.017); // convert sensorValue to distance in cm
      if (outputValue > 20 and outputValue < 150){  // remove all values outside the range of the sensor
        outputValue = outputValue;
      }
      else {
        outputValue = 0;
      }
      Serial.print(j);
      Serial.print(" ");
      Serial.print(i);
      Serial.print(" ");
      Serial.println(outputValue);
      delay(1000);
      servo_down.write(i);        
      servo_up.write(j);
    }
    }

  }

}


