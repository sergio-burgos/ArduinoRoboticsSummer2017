# ArduinoRoboticsSummer2017

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
