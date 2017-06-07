## Servo + LDR (Advanced)

**Code:**

```
#include <Servo.h>

int sensorPin1 = A3;    // select the input pin for the potentiometer
int sensorPin2 = A4;    // select the input pin for the potentiometer
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor

int difference = sensorValue1 - sensorValue2; // create variable to store difference between sensor values

Servo myservo; //create servo object to control a servo

void setup() {
  myservo.attach(11); // define pin used with servo motor
  Serial.begin(9600); // initialize Serial
}

void loop() {
  sensorValue1 = analogRead(sensorPin1); // update sensorValue1
  sensorValue2 = analogRead(sensorPin2); // update sensorValue2

  difference = abs(sensorValue1 - sensorValue2); // make the result always positive value

  printSensorValues();

  // creating condition for when sensorValue1 > sensorValue2 AND the difference is less than 15 to turn left
  if (sensorValue1 > sensorValue2 && difference >= 15) {
    myservo.write(170);
    delay(1500);

    // creating condition for when sensorValue1 < sensorValue2 AND the difference is less than 15 to turn right
  } else if (sensorValue1 < sensorValue2 && difference >= 15) {
    myservo.write(0);
    delay(1500);

    // creating condition for when the difference between sensor values is less than 15 to look forward
  } else {
    myservo.write(80);
    delay(1500);
  }

}

void printSensorValues() {

  // print "Sensor 1:(sensorValue1)"
  Serial.print("Sensor 1: ");
  Serial.print(sensorValue1);

  // print "Sensor 2:(sensorValue2)"
  Serial.print(" Sensor 2: ");
  Serial.print(sensorValue2);

  // print difference:(difference)"
  Serial.print(" Difference: ");
  Serial.print(difference);

  // print space to start new line on serial monitor
  Serial.println();

}
```

**Photos:**

<img width="744" alt="screen shot 2017-06-07 at 12 46 03 pm" src="https://user-images.githubusercontent.com/28915361/26900342-b6c75efe-4b86-11e7-9e1d-38efef8a9fa6.png">

Other photos are the same as "Servo + LDR" file.

**Video + Comments:**

Link: https://youtu.be/7JnzSjViCUw  

For this challenge I created a new variable that would store the difference between sensorValue1 and sensorValue2, and then used "abs" [difference = abs(sensorValue1 - sensorValue2)] to make the result always positive value. In addition to the two sensor values bieng printed, I added a third one that would tell me the difference value. This way I could easily see if the conditions I created where working with the value being read or calculated in my code. Since I had a 3 option in the set of condition to make the robot look forward, I had to be more specific when writing them. I added to the condition another premise saying that the difference should also be greater than or equal to 15 (&& difference >= 15) for the robot to turn, and a last one for anything else (or whenever the difference was less than 15) for the robot to look forward.
