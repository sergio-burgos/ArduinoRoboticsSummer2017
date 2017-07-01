## Final Presentation! 06/26

Today we finally present our robots. During the weekend, I was able to make my robot perform different actions: Center all legs, take a bow, lean left, lean right, move up, move down, move forward,, move backwards, and dance. For each one of this actions I create a function so that it would be easier to control my robot just by calling those functions. The one I was most proud of was "move forward" because I found a way to make the spider robot move forward, even though it was not exactly what I had in mind. But... it works, and I want to celebrate that accomplishment. With the help of Luis, I was able to make my robot move using a different theory and relying on the 8 servos. I posted the code for this one too under "code_exploration."

Overall, I'm very happy with the outcome, and you can see more of my proccess, programs I wrote, and images below. My plan is to keep playind with it and practice how to succesfuly make the spider robot move using all of the servos and timing the movement (or rotations) of all of them.  

**Brief Conceptual Description:**

The spider robot I created is a quadruped robot that user servos to control the legs that allow this "spider" to move and imitate real spider movements. The idea is to create a robot that can use the rotations of servo motors to replicate this movements.

**Detailed Technical Description:**

This robot uses 8 servo motors that are connected to an Adafruit Servo Motor shield. With the use of the shield, the 8 servo motors used can be easily connected to Pins 4-11 and allow for the circuit built for the robot to be more durable and reliable. To power the servo motors, the battery used to power the Arduino board wasnt enough, so I used 4 AA batteries to make sure I had enough power to make the spider robot move. Finally, by converting angles between 0-180 degrees to pulse lengths with a range between 150-600, wich allowed me to apply the same theory we leared for servos but using a different library that was unique to the shield. 

**Circuit Image + Schematics:**

![untitled sketch_bb](https://user-images.githubusercontent.com/28915361/27760401-691ed39e-5dfb-11e7-9e4b-025440571875.jpg)

![untitled sketch 2_schem](https://user-images.githubusercontent.com/28915361/27760584-6f9aa84c-5e00-11e7-9738-2c89b90d7a85.jpg)


**Process/Planning hardware + software:**

![img_0868 copy](https://user-images.githubusercontent.com/28915361/27760384-3d7dc5ce-5dfb-11e7-855e-a13ed273fc3a.jpg)

**Presentation Day Photo!**

![img_0806](https://user-images.githubusercontent.com/28915361/27760416-8e7431b6-5dfb-11e7-8904-af970449748a.JPG)


> As you can see, I was both excited and scared. You never know what would make your robot stop working.

**Code:**

```
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
int pos = 0;

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();

  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

// you can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;

  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period");
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit");
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
//  center() ;
//  delay (1000);
  
//    bow();
//    delay(1000);
//  
//    center() ;
//    delay (1000);
//  
//    lean_left() ;
//    delay (1000);
//  
//    lean_right() ;
//    delay (1000);
//  
//    center() ;
//    delay (1000);
//  
    up();
    delay (100);
  
    down();
    delay(200);
//  
//    center();
//    delay(1000);
//
//  forward();
//  delay(40);

  //  backwards();
  //  delay(1000);
  //
  //  center() ;
  //  delay (1000);
  //
  //  dance();
  //  delay (1);
  //
//    bow();
//    delay(1000);

  //  test();
  //  delay(1000);

}


void center() {
  pwm.setPWM(4, 0, 350);
  pwm.setPWM(5, 0, 325);
  pwm.setPWM(6, 0, 350);
  pwm.setPWM(7, 0, 325);
  pwm.setPWM(8, 0, 350);
  pwm.setPWM(9, 0, 325);
  pwm.setPWM(10, 0, 350);
  pwm.setPWM(11, 0, 325);
}


void up() {
  pwm.setPWM(4, 0, 350);
  pwm.setPWM(5, 0, 600);
  pwm.setPWM(6, 0, 350);
  pwm.setPWM(7, 0, 600);
  pwm.setPWM(8, 0, 350);
  pwm.setPWM(9, 0, 600);
  pwm.setPWM(10, 0, 350);
  pwm.setPWM(11, 0, 600);
}


void down() {
  pwm.setPWM(4, 0, 350);
  pwm.setPWM(5, 0, 225);
  pwm.setPWM(6, 0, 350);
  pwm.setPWM(7, 0, 225);
  pwm.setPWM(8, 0, 350);
  pwm.setPWM(9, 0, 225);
  pwm.setPWM(10, 0, 350);
  pwm.setPWM(11, 0, 225);
}


void lean_left() {
  center();
  delay(50);
  pwm.setPWM(5, 0, 200);
  pwm.setPWM(11, 0, 200);
  delay(700);
  pwm.setPWM(5, 0, 400);
  pwm.setPWM(11, 0, 400);
  delay(700);
}


void lean_right() {
  center();
  delay(50);
  pwm.setPWM(7, 0, 200);
  pwm.setPWM(9, 0, 200);
  delay(700);
  pwm.setPWM(7, 0, 400);
  pwm.setPWM(9, 0, 400);
  delay(700);
}


void forward() {
  //sequence to change to forward position
  pwm.setPWM(6, 0, 200);
  delay(190);

  pwm.setPWM(10, 0, 550);

  delay(190);

  pwm.setPWM(4, 0, 550);
  delay(190);

  pwm.setPWM(8, 0, 150);
  delay(190);

  // push forward with back legs

  pwm.setPWM(4, 0, 350);
  pwm.setPWM(5, 0, 350);
  pwm.setPWM(6, 0, 350);
  pwm.setPWM(7, 0, 350);
  pwm.setPWM(8, 0, 350);
  pwm.setPWM(9, 0, 550); //*
  pwm.setPWM(10, 0, 350);
  pwm.setPWM(11, 0, 550); //*
  delay(10);
}


void backwards() {
  pwm.setPWM(10, 0, 150);
  delay(190);

  pwm.setPWM(6, 0, 550);
  delay(190);

  pwm.setPWM(8, 0, 550);
  delay(190);

  pwm.setPWM(4, 0, 200);
  delay(190);

}


void bow() {
  center();
  delay(50);
  pwm.setPWM(5, 0, 200);
  pwm.setPWM(7, 0, 200);
  delay(700);
  pwm.setPWM(5, 0, 400);
  pwm.setPWM(7, 0, 400);
  delay(700);
}

void dance() {
  pwm.setPWM(4, 0, 600);
  pwm.setPWM(5, 0, 600);
  pwm.setPWM(6, 0, 600);
  pwm.setPWM(7, 0, 600);
  pwm.setPWM(8, 0, 600);
  pwm.setPWM(9, 0, 600);
  pwm.setPWM(10, 0, 600);
  pwm.setPWM(11, 0, 600);
  delay(500);

  pwm.setPWM(4, 0, 200);
  pwm.setPWM(5, 0, 200);
  pwm.setPWM(6, 0, 200);
  pwm.setPWM(7, 0, 200);
  pwm.setPWM(8, 0, 200);
  pwm.setPWM(9, 0, 200);
  pwm.setPWM(10, 0, 200);
  pwm.setPWM(11, 0, 200);
  delay(500);
}


void test() {
  pwm.setPWM(11, 0, 400);
  //  pwm.setPWM(7, 0, 500);
  //  pwm.setPWM(9, 0, 500);
  //  pwm.setPWM(11, 0, 500);
  delay(1000);
  pwm.setPWM(11, 0, 200);
  //  pwm.setPWM(7, 0, 200);
  //  pwm.setPWM(9, 0, 200);
  //  pwm.setPWM(11, 0, 200);
  delay(1000);
}
```

**Code_Exploration:**

```
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
int pos = 0;

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();

  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

// you can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;

  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period");
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit");
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  center() ;
  delay (200);

  steps() ;
  delay (1000);

  //    bow();
  //    delay(1000);
  //
  //    center() ;
  //    delay (1000);
  //
  //    lean_left() ;
  //    delay (1000);
  //
  //    lean_right() ;
  //    delay (1000);
  //
  //    center() ;
  //    delay (1000);
  //
  //    up();
  //    delay (1000);
  //
  //    down();
  //    delay(1000);
  //
  //    center();
  //    delay(1000);
  //
  //  forward();
  //  delay(40);

  //  backwards();
  //  delay(1000);
  //
  //  center() ;
  //  delay (1000);
  //
  //  dance();
  //  delay (1);
  //
  //  bow();
  //  delay(1000);

  //  test();
  //  delay(1000);

}


void center() {
  pwm.setPWM(4, 0, 350);
  pwm.setPWM(5, 0, 325);
  pwm.setPWM(6, 0, 350);
  pwm.setPWM(7, 0, 325);
  pwm.setPWM(8, 0, 350);
  pwm.setPWM(9, 0, 325);
  pwm.setPWM(10, 0, 350);
  pwm.setPWM(11, 0, 325);
}


void up() {
  pwm.setPWM(4, 0, 350);
  pwm.setPWM(5, 0, 600);
  pwm.setPWM(6, 0, 350);
  pwm.setPWM(7, 0, 600);
  pwm.setPWM(8, 0, 350);
  pwm.setPWM(9, 0, 600);
  pwm.setPWM(10, 0, 350);
  pwm.setPWM(11, 0, 600);
}


void down() {
  pwm.setPWM(4, 0, 350);
  pwm.setPWM(5, 0, 225);
  pwm.setPWM(6, 0, 350);
  pwm.setPWM(7, 0, 225);
  pwm.setPWM(8, 0, 350);
  pwm.setPWM(9, 0, 225);
  pwm.setPWM(10, 0, 350);
  pwm.setPWM(11, 0, 225);
}


void lean_left() {
  center();
  delay(50);
  pwm.setPWM(5, 0, 200);
  pwm.setPWM(11, 0, 200);
  delay(700);
  pwm.setPWM(5, 0, 400);
  pwm.setPWM(11, 0, 400);
  delay(700);
}


void lean_right() {
  center();
  delay(50);
  pwm.setPWM(7, 0, 200);
  pwm.setPWM(9, 0, 200);
  delay(700);
  pwm.setPWM(7, 0, 400);
  pwm.setPWM(9, 0, 400);
  delay(700);
}


void forward() {
  //sequence to change to forward position
  pwm.setPWM(6, 0, 200);
  delay(190);

  pwm.setPWM(10, 0, 550);

  delay(190);

  pwm.setPWM(4, 0, 550);
  delay(190);

  pwm.setPWM(8, 0, 150);
  delay(190);

  // push forward with back legs

  pwm.setPWM(4, 0, 350);
  pwm.setPWM(5, 0, 350);
  pwm.setPWM(6, 0, 350);
  pwm.setPWM(7, 0, 350);
  pwm.setPWM(8, 0, 350);
  pwm.setPWM(9, 0, 550); //*
  pwm.setPWM(10, 0, 350);
  pwm.setPWM(11, 0, 550); //*
  delay(10);
}


void backwards() {
  pwm.setPWM(10, 0, 150);
  delay(190);

  pwm.setPWM(6, 0, 550);
  delay(190);

  pwm.setPWM(8, 0, 550);
  delay(190);

  pwm.setPWM(4, 0, 200);
  delay(190);

}


void bow() {
  center();
  delay(50);
  pwm.setPWM(5, 0, 200);
  pwm.setPWM(7, 0, 200);
  delay(700);
  pwm.setPWM(5, 0, 400);
  pwm.setPWM(7, 0, 400);
  delay(700);
}

void dance() {
  pwm.setPWM(4, 0, 600);
  pwm.setPWM(5, 0, 600);
  pwm.setPWM(6, 0, 600);
  pwm.setPWM(7, 0, 600);
  pwm.setPWM(8, 0, 600);
  pwm.setPWM(9, 0, 600);
  pwm.setPWM(10, 0, 600);
  pwm.setPWM(11, 0, 600);
  delay(500);

  pwm.setPWM(4, 0, 200);
  pwm.setPWM(5, 0, 200);
  pwm.setPWM(6, 0, 200);
  pwm.setPWM(7, 0, 200);
  pwm.setPWM(8, 0, 200);
  pwm.setPWM(9, 0, 200);
  pwm.setPWM(10, 0, 200);
  pwm.setPWM(11, 0, 200);
  delay(500);
}


void test() {
  pwm.setPWM(11, 0, 400);
  //  pwm.setPWM(7, 0, 500);
  //  pwm.setPWM(9, 0, 500);
  //  pwm.setPWM(11, 0, 500);
  delay(1000);
  pwm.setPWM(11, 0, 200);
  //  pwm.setPWM(7, 0, 200);
  //  pwm.setPWM(9, 0, 200);
  //  pwm.setPWM(11, 0, 200);
  delay(1000);
}

void steps() {
  //  pwm.setPWM(4, 0, 350);
  //  pwm.setPWM(6, 0, 350);
  //  pwm.setPWM(8, 0, 350);
  //  pwm.setPWM(10, 0, 350);
  //  delay(1000);

  pwm.setPWM(5, 0, 350);
  pwm.setPWM(7, 0, 550);
  pwm.setPWM(9, 0, 550);
  pwm.setPWM(11, 0, 550);
  delay(1000);

  pwm.setPWM(8, 0, 150);
  delay(1000);

  pwm.setPWM(9, 0, 550);
  delay(1000);

  pwm.setPWM(5, 0, 600);
  delay(1000);


// other leg

//  pwm.setPWM(10, 0, 550);
//  delay(1000);
//
//  pwm.setPWM(11, 0, 550);
//  delay(1000);
//
//  pwm.setPWM(5, 0, 600);
//  delay(1000);

  //  pwm.setPWM(5, 0, 550);
  //  pwm.setPWM(7, 0, 550);
  //  pwm.setPWM(9, 0, 350);
  //  pwm.setPWM(11, 0, 550);
  //  delay(1000);
  //
  //  pwm.setPWM(4, 0, 550);
  //  delay(1000);
  //
  //  pwm.setPWM(5, 0, 550);
  //  pwm.setPWM(7, 0, 550);
  //  pwm.setPWM(9, 0, 350);
  //  pwm.setPWM(11, 0, 550);
  //  delay(1000);
  //
  //  pwm.setPWM(6, 0, 150);
  //  delay(1000);
  //
  //  pwm.setPWM(5, 0, 550);
  //  pwm.setPWM(7, 0, 350);
  //  pwm.setPWM(9, 0, 550);
  //  pwm.setPWM(11, 0, 550);
  //  delay(1000);
  //
  //  pwm.setPWM(10, 0, 550);
  //  delay(1000);

}
```
