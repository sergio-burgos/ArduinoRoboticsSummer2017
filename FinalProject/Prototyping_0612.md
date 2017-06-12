## Prototyping 06/12

While looking for different models to get inspired by, I found one that had a robot working with only 8 servo motors. This was great because last class Sabine and I were talking about the number of servos we needed and how that was going to be a challenge, so I decided to go with this design. I also bought a pack of 10 servo motors and started thinking about how I would need them to move when the robot is built.

At first I couldn't get 2 servo motors to move at the same time, so I thought it was gi oing to be challenging to create a sequence that would make them move and at different times. But after looking at servo tutorials I found one example by BARRAGAN <http://barraganstudio.com that I modified to test my motors, and it worked! I

**Code:**

```
#include <Servo.h>

Servo myservoa;  // create servo object to control a servo
Servo myservob;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservoa.attach(3);  // attaches the servo on pin 2 to the servo object
  myservob.attach(4);  // attaches the servo on pin 2 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoa.write(pos);              // tell servo to go to position in variable 'pos'
    myservob.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservoa.write(pos);              // tell servo to go to position in variable 'pos'
    myservob.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

```

Refine your final project proposal. Research and/or do some prototyping. The goal is to answer some questions quickly about how complicated your project is, and whether it is feasible. Research parts, make a tentative parts list, make a list of steps you will have to take. These are suggested steps - take whatever steps seem appropriate to your project. Ask me for help if you need it.
