## Prototyping 06/19

During the weekend I worked on finishing building the robot and making sure the structure worked. I got it done by Sunday night, so I wanted to work during class on Monday on making sure the robot moved using a breadboard to make all the circuit I needed to power and control the servo motors. To build this structure I used nuts, bolts, and nylon hex lock nuts I bought on amazon, but then realized they were not the best for this project. I then went to Harrison & Boninni to get the 4-40 nuts, bolts, and nylon hex lock nuts that fit perfectly. 

During class I created sample code that would test the robot's ability to make different coordinated movements, as well as help me start understanding more what degrees I need to consider for specific movements and the time (or delay) I had to assign after each function created for a robot's action. 

Here's a video showing how the robot worked: https://youtu.be/MoS8wETw3yw

**Code:**

```
#include <Servo.h>    // include servo library

// Define 8 Servos
Servo myServo1; // Front Left Pivot Servo
Servo myServo2; // Front Left Lift Servo
Servo myServo3; // Back Left Pivot Servo
Servo myServo4; // Back Left Lift Servo
Servo myServo5; // Back Right Pivot Servo
Servo myServo6; // Back Right Lift Servo
Servo myServo7; // Front Right Pivot Servo
Servo myServo8; // Front Right Lift Servo

void setup() {
  // Attach servos to Arduino Pins
  myServo1.attach(3);
  myServo2.attach(4);
  myServo3.attach(6);
  myServo4.attach(5);
  myServo5.attach(7);
  myServo6.attach(8);
  myServo7.attach(9);
  myServo8.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  center_servos();
  delay(1000);
  //dance();
  //delay(500);
  lean_left();
  delay(1000);
  center_servos();
  delay(1000);
  lean_right();
  delay(1000);
  center_servos();
  delay(1000);
  bow ();
  delay(1000);
}


// Other functions -------------------------------------------------------------------

void center_servos() {
  myServo1.write(90);
  myServo2.write(90);
  myServo3.write(90);
  myServo4.write(90);
  myServo5.write(90);
  myServo6.write(90);
  myServo7.write(90);
  myServo8.write(90);
}


void bow() {
  center_servos();
  delay(200);
  myServo2.write(15);
  myServo8.write(15);
  delay(700);
  myServo2.write(90);
  myServo8.write(90);
  delay(700);
}


void lean_left() {
  myServo2.write(15);
  myServo4.write(15);
  myServo6.write(150);
  myServo8.write(150);
}


void lean_right() {
  myServo2.write(150);
  myServo4.write(150);
  myServo6.write(15);
  myServo8.write(15);
}


void wave() {
  center_servos();
  myServo4.write(45);
  myServo6.write(45);
  delay(200);
  myServo8.write(0);
  delay(200);
  myServo7.write(180);
  delay(200);
  myServo7.write(30);
  delay(300);
  myServo7.write(180);
  delay(300);
  myServo7.write(30);
  delay(300);
  //  myServo7.write(s41);
  //delay(300);
  //myServo8.write(s42);
  center_servos();
}


void dance() {
  center_servos();
  delay(100);
  lean_left();
  delay(300);
  lean_right();
  delay(300);
  lean_left();
  delay(300);
  lean_right();
  delay(300);
  lean_left();
  delay(300);
  lean_right();
  delay(300);
  lean_left();
  delay(300);
  lean_right();
  delay(800);
  center_servos();
  delay(300);
  bow();
  center_servos();
}

```

**Images:**

<img width="643" alt="screen shot 2017-06-26 at 10 32 19 am" src="https://user-images.githubusercontent.com/28915361/27552061-c400f070-5a5a-11e7-8588-8c698c09c883.png">

> Image from structure built during the weekend.

<img width="593" alt="screen shot 2017-06-26 at 10 28 18 am" src="https://user-images.githubusercontent.com/28915361/27551946-4c8a2eda-5a5a-11e7-84ca-33f943293db5.png">
<img width="591" alt="screen shot 2017-06-26 at 10 28 30 am" src="https://user-images.githubusercontent.com/28915361/27551948-4c8d7c20-5a5a-11e7-85d7-bf4b37e32f8b.png">
<img width="592" alt="screen shot 2017-06-26 at 10 28 46 am" src="https://user-images.githubusercontent.com/28915361/27551947-4c8c11dc-5a5a-11e7-8936-155811e8dcec.png">

> Images from robot tested during class.
