## Servo + LDR 

**Code:**

```
#include <Servo.h>

int sensorPin1 = A3;    // select the input pin for the potentiometer
int sensorPin2 = A4;    // select the input pin for the potentiometer
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor

Servo myservo; // create servo object to control a servo

void setup() {
  myservo.attach(11); // define pin used with servo motor
  Serial.begin(9600); // initialize Serial
}

void loop() {
  sensorValue1 = analogRead(sensorPin1); // update sensorValue1
  sensorValue2 = analogRead(sensorPin2); // update sensorValue2

  // print "Sensor 1:(sensorValue1)"
  Serial.print("Sensor 1: ");
  Serial.print(sensorValue1);

  // print "Sensor 2:(sensorValue2)"
  Serial.print(" Sensor 2: ");
  Serial.print(sensorValue2);

  // print space to start new line on serial monitor
  Serial.println();

  // creating condition for servo to turn left or right following light
  if (sensorValue1 > sensorValue2) {
    myservo.write(170);
    delay(1500);
  } else {
    myservo.write(0);
    delay(1500);
  }

}

```

**Photos:**

![img_0295](https://user-images.githubusercontent.com/28915361/26897623-006e7334-4b7e-11e7-8efb-c9ff9edc738b.JPG)

![img_0296](https://user-images.githubusercontent.com/28915361/26897624-007140aa-4b7e-11e7-9020-207be7988515.JPG)

![img_0297](https://user-images.githubusercontent.com/28915361/26897626-0073198e-4b7e-11e7-9efe-6751ba2fc25d.JPG)

![img_0299](https://user-images.githubusercontent.com/28915361/26897625-0071f1e4-4b7e-11e7-9b0d-5e64580db4f2.JPG)

![img_0300](https://user-images.githubusercontent.com/28915361/26897627-0073df90-4b7e-11e7-83fd-71dacc8619b0.JPG)

**Video + Comments:**

Link: https://youtu.be/llop9hv73dE

After adding the servo motor and 2 LDRs, I first wanted to make sure I could read the values of both LDRs so I made the code print them in the serial monitor. After that, I added a simple condition for when the value for sensorValue1 was greater thatn  sensorValue2 (sensorValue1 > sensorValue2), making the robot turn left or right based on which LDR had the highest value.
