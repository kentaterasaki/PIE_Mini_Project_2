
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9;  // Analog output pin that the LED is attached to

int sensorValue2 = 0;  // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)
int distance = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
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
  // read the analog in value:
  sensorValue2 = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue2, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue2);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  Serial.println(sensorToCm(sensorValue2));
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(200);

}


// 20 cm is output 139 sensor value is 560
// 150 cm is output 23 sensor value is 95 

