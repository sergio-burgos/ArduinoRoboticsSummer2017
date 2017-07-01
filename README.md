# ArduinoRoboticsSummer2017

```
void setup() { // initialize digital pin 10 and 11 as an output. 
pinMode(10, OUTPUT); 
pinMode(11, OUTPUT); 
}

// the loop function runs over and over again forever. I used a different delay time for each LED to easily identify pin 10 and 11 based on their behavior. 
void loop() { digitalWrite(10, HIGH); // turn the LED 10 on (HIGH is the voltage level) 
delay(1000); // wait for a second 
digitalWrite(10, LOW); // turn the LED 10 off by making the voltage LOW 
delay(1000); // wait for a second

digitalWrite(11, HIGH); // turn the LED 11 on (HIGH is the voltage level) 
delay(500); // wait for half a second 
digitalWrite(11, LOW); // turn the LED 11 off by making the voltage LOW 
delay(500); // wait for half a second 
}
```

**5/25 - Anlog Input Tutorial with LDR notes:**

When putting together the circuit we needed for this excercise, I decided to use an additional LED instead of the built-in one to practice making the connections needed for an external LED, and also to make it easier for me to see any changes (since the built-in LED is really small). 

**5/25 - Analog Input + Serial Print notes:**

Based on the room I was in, when adding the LDR + resistor to measure the voltage, I saw the value go from 4-65. I started playing with covering the LDR to see how the values changed and get an idea of how much light affected those values.

**5/25 - Anlog Input On/Off notes:**

For this excercise, I created a condition for the code to turn the ledPin on if the sensorValue was greater or equal to 40, and for anything else, to to turn the ledPin off. Creating this condition was easier because I only needed to assign a value that I saw worked for the room I was in, based on what was showing in the serial monitor window.

**5/26 - Anlog Input On/Blink/Off notes:**

For this last excercise, I created a structure with two conditions. One if the sensorValue was greater or equal to 40, which would turn the ledPin on, and a second one if the sensorValue was less or equal to 10, which would turn the ledPin on. I finally added under "else" a code to make the ledPin blink and changed the delay to 100 milliseconds to make the blinking delay consistent and easier to identify.

**6/1 - Robot Sequence notes:**

For this program I followed the LED blink example and used it to create a sequence where my robot would move forward , stop , move backwards, and then stop again. All of these directions I was giving to the motors where for half a second, so that I could have more control over the code I wrote and to avoid my robot from falling apart.

Photos and videos are added on the assignment file.

**6/1 - Robot Pushbutton 1 notes:**

For this program, I created an if condition that would verify the value of buttonState to see if it was >= 1. The reason why I'm checking if buttonState is 1 is because the values I get on the serial monitor are 0 (for when button is not pressed) and 1 (for when button is pressed). This way I can create a logical condition that would read the value 1 as an instruction to make the robot perform a sequence when the button is pressed, and then wait for the next time the button is pressed to perform the sequence again.

Video added on the assignment file.


**6/1 - Robot Pushbutton 2 notes:**

I'm not sure if I created the right program. It does what was asked for the homework, but the logic might not be the right one. I modified the code I hade for the previous excercise and in addition to creating the if condition to make the robot perform the sequence after buttonState was "1" (or when the button was pressed), and added a while loop that would continue for as long as the condition that I define was true, which in this case would always be true since when button is released the value of the variable pushButton goes back to "0".

Video added on the assignment file.

**6/2 - Robot Pushbutton Exploration (Not part of the HW) notes:**

In this code I get the robot to start/stop when the pushbutton is pressed. I got this code to work by following this tutorial I found on YouTube: https://www.youtube.com/watch?v=1C-3P_hmd70. I looked at different tutorials to understand the logic to make the robot perform the sequence when the button was pressed at least once, and then stop when it was pressed again. I took the code I had for the Robor_PushButton_2 file and added some of the code I saw on the YouTube tutorial and was able to successfully make it work. Although, I identified a delay that doesn't make the robot stop as soon as the button is pressed. What I have to do to make it stop is press the button and hold it down. I'm not really sure why this happens, but it was fun getting it to do what I wanted it to do.

The first video shows the robot on the floor and moving, but since it was hard to show in detail what happened when I pressed the button, I added a second one of me holding the robot and just showing its behavior.

Videos added on the assignment file.

**6/5 - Robot Obstacles notes:**

After building my robot, I realized it would've been impossible to have the distance measuring sensor facing the front without redesigning my lego robot. I decided to check out a small breadboard to add more legos to hold it and place the distance measuring sensor on that second one that could now be reading what was in front of my robot.

For the code, I combined the code I wrote for one of the previous excercises where I made my robot perform a sequence. Using the code we were given for the distance measuring sensor, I incorporated that into my code and made sure I could have both actions being performed when running the program (reading distance and printing it + making the robot run a sequence). After making sure this two worked, I created a condition using the value being read by the sensor and defining that if distance >= 20 cm, the robot could keep moving forward, and if distance < 20, the robot would stop the motors, turn right, and stop one more time before it started moving forward again.

After testing it, I realized I needed to give the motor that was making the robot turn more power to make it do it successfuly. In te second code I added, instead of assignning the speed in setup, I do it inside the loop function. This way I was able to make the motor spin faster (and with more power) when making the robot turn.

Photos and videos added on the assignment file.

**6/7 - Servo + LDR notes:**

After adding the servo motor and 2 LDRs, I first wanted to make sure I could read the values of both LDRs so I made the code print them in the serial monitor. After that, I added a simple condition for when the value for sensorValue1 was greater thatn  sensorValue2 (sensorValue1 > sensorValue2), making the robot turn left or right based on which LDR had the highest value.

Photos and video added on the assignment file.


**6/7 - Servo + LDR (Advanced) notes:**

For this challenge I created a new variable that would store the difference between sensorValue1 and sensorValue2, and then used "abs" [difference = abs(sensorValue1 - sensorValue2)] to make the result always positive value. In addition to the two sensor values bieng printed, I added a third one that would tell me the difference value. This way I could easily see if the conditions I created where working with the value being read or calculated in my code. Since I had a 3 option in the set of condition to make the robot look forward, I had to be more specific when writing them. I added to the condition another premise saying that the difference should also be greater than or equal to 15 (&& difference >= 15) for the robot to turn, and a last one for anything else (or whenever the difference was less than 15) for the robot to look forward.

Video added on the assignment file.


**6/9 - Project Proposal notes:**

After thinking of different ideas, I remembered a robot I saw last year at AT&T Shape Expo that made me feel like I could never do anything like that. It was a spider-looking robot with many motors that created limbs or legs, and it looked amazing when it started walking. After googling for "Spider Robot," I found many variations of that idea and realized that most people were using servo motors. Since the last time I did a project with arduino I only worked with DC motors, I wanted to challenge myself to work on a project that would help understand a little more about how servo motors work and what I can do with them.

I think the logic behind programming with servo motors can be interesting, because it requires coordination and precision. This project would also require finding, printing or creating parts that I could assemble to create a spider-looking structure. I would ideally look for a strong material so I could keep this robot after the class is done. And, if I succeed in this first part of making this robot perform a sequence that really looks like a spider, I would like to either add a distance measuring sensor or create a remote control to turn this into a toy I can play with anytime.


**6/12 - Spider Robot Prototyping:**

While looking for different models to get inspired by, I found one that had a robot working with only 8 servo motors. This was great because last class Sabine and I were talking about the number of servos we needed and how that was going to be a challenge, so I decided to go with this design. I also bought a pack of 10 servo motors and started thinking about how I would need them to move when the robot is built.

At first I couldn't get 2 servo motors to move at the same time, so I thought it was gi oing to be challenging to create a sequence that would make them move and at different times. But after looking at servo tutorials I found one example by BARRAGAN (http://barraganstudio.com) that I modified to test my motors, and it worked!


**6/14 - Spider Robot Prototyping:**

I decided to simplify the design I wanted and only have 4 legs for the spider robot. This would allow me to use les servo motors, as well as simplify the process of making the robot move. A friend of mine shared with me a file with the design ready to be laser cutted, so I used it on the CCA laser cut machines. The file is here in case others want to download it (Robot_Quadruped2v2.dxf.zip)

After I got all the pieces ready, I decided to spray paint them to give them a different look. After using the spray paint room upstairs, I realized a made the mistake of not removing a protective layer that the material I used to laser cut the parts had, and I could just peel off the paint. This was frustrating because painting the parts took longer than I expected (because of waiting for it to dry so you can use them later and I still got marks and imperfections), and it was all in vain. Leason learned.


**6/16 - Spider Robot Prototyping:**

After removing all of the paint from tha parts I had ready from last class, I started building the legs of the robot and attaching the servo motors to test with code how they would move. While doing this I realized I was missing the right nuts and bolts, so I had to improvise with the ones I found on the hybrid lab and even using wire to attach the servo motor "horns." After this I ordered nuts, bolts and nylon Hex lock nuts.

Some photos can be found below and this is a video showing how the leg worked: https://youtu.be/kkIDmBfzg1M

Another really helpful thing was finding this article (http://makezine.com/2016/11/22/robot-quadruped-arduino-program/) explaining the logic behind programming a quadruped robot with arduino. This includes some theory about Passive vs. Active Stability, the Creep Gait, etc. that were VERY helpful. I definitely recommend reading it if you're working on a similar project. They even have diagrams and videos that help you understand what you'll need to consider for your project.


**6/19 - Spider Robot Prototyping:**

During the weekend I worked on finishing building the robot and making sure the structure worked. I got it done by Sunday night, so I wanted to work during class on Monday on making sure the robot moved using a breadboard to make all the circuit I needed to power and control the servo motors. To build this structure I used nuts, bolts, and nylon hex lock nuts I bought on amazon, but then realized they were not the best for this project. I then went to Harrison & Boninni to get the 4-40 nuts, bolts, and nylon hex lock nuts that fit perfectly.

During class I created sample code that would test the robot's ability to make different coordinated movements, as well as help me start understanding more what degrees I need to consider for specific movements and the time (or delay) I had to assign after each function created for a robot's action.

Here's a video showing how the robot worked: https://youtu.be/MoS8wETw3yw


**6/21 - Spider Robot Prototyping:**

I finally got the servo shield I ordered from Adafruit and started soldering to get rid of the breadboard I was using before. I have to say doing this was very exciting because it was the first time I worked creating a shield and doing a project with arduino without using a breadboard. I guess it just made it feel for like a real project than just an assignment.

Luis helped me use the soldering machines at school during class and finally got to create the shield I was going to use for my spider robot. Michael also helped me learn how to achieve a more clean and precise soldering work. After being done with the shield, I connected it to my robot to make sure this was working, and I coudln't get it to work. After that class, Sabine shared with me that I was probably missing the shield library, and it turned out I was.


**6/23 - Spider Robot Prototyping:**

After adding the shield library I was able to look at some of the examples programs they had in the tutorial and test the robot with the new code. The tutorial I followed was found on the "learn" section of the Adafruit website ( https://learn.adafruit.com/16-channel-pwm-servo-driver/using-the-adafruit-library) and uses content from this Github repository (https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library). Instead of the conventional servo library, this shield was using "Wire.h" and "Adafruit_PWMServoDriver.h" libraries. This library also required that I converted from degrees to pulse lengths in order to understand the logic behind the rotations of the servo motors which would eventually make the robot move the way I want it to. Instead of having an angle between 0-180 degrees, I had a range between 150-600 pulse length.

At this point, I replaced some of the nuts and bolt I had because they kep falling off. I also thought it would be a good idea to use a hot glue gun to make sure some of the nuts I added were not moving in ways I didn't want them to, specially now that I was working on creating code to make the robot move forward. After doing this, I also glued the battery holder on the bottom of the robot.

Here is a video of how I started thinking of ways to make this robot move: https://youtu.be/JItx2b7Y19U.


**6/26 - Spider Robot Final Presentation:**

Look at FinalProject Folder > FinalPresentation_0626.md
