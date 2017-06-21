## Prototyping 06/16

After removing all of the paint from tha parts I had ready from last class, I started building the legs of the robot and attaching the servo motors to test with code how they would move. While doing this I realized I was missing the right nuts and bolts, so I had to improvise with the ones I found on the hybrid lab and even using wire to attach the servo motor "horns." After this I ordered nuts, bolts and nylon Hex lock nuts.

Some photos can be found below and this is a video showing how the leg worked: https://youtu.be/kkIDmBfzg1M

Another really helpful thing was finding this article (http://makezine.com/2016/11/22/robot-quadruped-arduino-program/) explaining the logic behind programming a quadruped robot with arduino. This includes some theory about Passive vs. Active Stability, the Creep Gait, etc. that were VERY helpful. I definitely recommend reading it if you're working on a similar project.

**Code:**

```
#include <Servo.h>

Servo myservoa;

int pos = 0;

void setup() {
  myservoa.attach(4);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {
    // in steps of 1 degree
    myservoa.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservoa.write(pos);
    delay(15);
  }
}

```

**Images:**

<img width="538" alt="screen shot 2017-06-21 at 12 09 09 pm" src="https://user-images.githubusercontent.com/28915361/27402370-44a80fc6-567b-11e7-8298-889d54dd8bd2.png">

<img width="538" alt="screen shot 2017-06-21 at 12 18 01 pm" src="https://user-images.githubusercontent.com/28915361/27402508-b823e88a-567b-11e7-8bd3-e8ec2267e15b.png">
