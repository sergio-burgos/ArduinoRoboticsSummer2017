```
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  // open the serial port at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read sensorValue as first step of loop:
  Serial.println(sensorValue);
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  
  // if the sensorValue is greater or equal to 14
  if (sensorValue >= 40) {
   // turn the ledPin on
   digitalWrite(ledPin, HIGH);
   // stop the program for <sensorValue> milliseconds:
   delay(sensorValue);
   
  // if the sensorValue is less or equal to 4
  } else if (sensorValue <= 10) {
   // turn the ledPin off:
   digitalWrite(ledPin, LOW);
   // stop the program for <sensorValue> milliseconds:
   delay(sensorValue);
  
  } else {
   digitalWrite(ledPin, HIGH);
   // stop the program for 100 milliseconds:
   delay(100);
   // turn the ledPin off:
   digitalWrite(ledPin, LOW);
   // stop the program for 100 milliseconds:
   delay(100);
  }
  
}
```
