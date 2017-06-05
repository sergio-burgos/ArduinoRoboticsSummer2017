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
