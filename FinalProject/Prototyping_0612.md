## Prototyping 06/12

While looking for different models to get inspired by, I found one that had a robot working with only 8 servo motors. This was great because last class Sabine and I were talking about the number of servos we needed and how that was going to be a challenge, so I decided to go with this design. I also bought a pack of 10 servo motors and started thinking about how I would need them to move when the robot is built.

At first I couldn't get 2 servo motors to move at the same time, so I thought it was gi oing to be challenging to create a sequence that would make them move and at different times. But after looking at servo tutorials I found one example by BARRAGAN (http://barraganstudio.com) that I modified to test my motors, and it worked!

**Materials:**

- 1 Arduino Uno
- 8 servo motors
- Laser-cutted structure
- Battery Adapter
- Batteries
- Breadboard or shield?
- Remote control (probably one from Amazon)

**Steps:**

1. Laser cut structure design at CCA
2. Build one "leg" of the robot and attach servo motors to test.
3. Finish building rest of the structure.
4. Attach the Arduino Uno
5. Figure it if breadboard is needed, or if it's better to buil a shield.
6. Add all servo motors and complete building the robot.
7. Test code again for only one "leg" and change pin number to test all attached "legs."
8. Create program for front legs, and then test it (if it works) with the back ones.
9. Create sequence to make robot walk.
10. (Maybe) add distance measuring sensor.
11. Attach battery holder + Battteries to power arduino and servos without cable.
12. Try to control robot with a remote control.

**Code:**

```
#include <Servo.h>

Servo myservoa;  // create servo object to control a servo
Servo myservob;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservoa.attach(3);  // attaches the servo on pin 3 to the servo object
  myservob.attach(4);  // attaches the servo on pin 4 to the servo object
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

**Video:**

Link : https://youtu.be/dr_Y2hTiPtc
