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



**Video + Comments:**

Link: https://youtu.be/phjiAjb6BE8  

Link 2: https://youtu.be/9t-70CrKMbw

After building my robot, I realized it would've been impossible to have the distance measuring sensor facing the front without redesigning my lego robot. I decided to check out a small breadboard to add more legos to hold it and place the distance measuring sensor on that second one that could now be reading what was in front of my robot.

For the code, I combined the code I wrote for one of the previous excercises where I made my robot perform a sequence. Using the code we were given for the distance measuring sensor, I incorporated that into my code and made sure I could have both actions being performed when running the program (reading distance and printing it + making the robot run a sequence). After making sure this two worked, I created a condition using the value being read by the sensor and defining that if distance >= 20 cm, the robot could keep moving forward, and if distance < 20, the robot would stop the motors, turn right, and stop one more time before it started moving forward again.

After testing it, I realized I needed to give the motor that was making the robot turn more power to make it do it successfuly. In te second code I added, instead of assignning the speed in setup, I do it inside the loop function. This way I was able to make the motor spin faster (and with more power) when making the robot turn.
