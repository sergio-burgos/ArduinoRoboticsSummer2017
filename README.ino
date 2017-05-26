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

// 5/25 - Anlog Input Tutorial with LDR notes
// When putting together the circuit we needed for this excercise, I decided to use an additional LED instead of the built-in one to practice making the connections needed for an external LED, and also to make it easier for me to see any changes (since the built-in LED is really small). 

// 5/25 - Analog Input + Serial Print notes
// Based on the room I was in, when adding the LDR + resistor to measure the voltage, I saw the value go from 4-65. I started playing with covering the LDR to see how the values changed and get an idea of how much light affected those values.

// 5/25 - Anlog Input On/Off notes
// For this excercise, I created a condition for the code to turn the ledPin on if the sensorValue was greater or equal to 40, and for anything else, to to turn the ledPin off. Creating this condition was easier because I only needed to assign a value that I saw worked for the room I was in, based on what was showing in the serial monitor window.

// 5/26 - Anlog Input On/Blink/Off notes
// For this last excercise, I created a structure with two conditions. One if the sensorValue was greater or equal to 40, which would turn the ledPin on, and a second one if the sensorValue was less or equal to 10, which would turn the ledPin on. I finally added under "else" a code to make the ledPin blink and changed the delay to 100 milliseconds to make the blinking delay consistent and easier to identify.
