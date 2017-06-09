## Robot Obstacles Using Functions

**Code:**

```
int sensorPin1 = A0;    // select pin for LDR 1
int sensorPin2 = A1;    // select pin for LDR 2
int sensorPin3 = A2;    // select pin for LDR 3

int sensorValue1;  // variable to store the value from LDR 1
int sensorValue2;  // variable to store the value from LDR 2
int sensorValue3;  // variable to store the value from LDR 3

int roomLight;  // defining variable to store average

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // initialize Serial
}

void loop() {
  lightReading();  // call for function "lightReading"
  Serial.println(roomLight);  // print "roomLight" value
  delay(1);        // delay in between reads for stability
}

int lightReading() {
  sensorValue1 = analogRead(sensorPin1); // update sensorValue1
  sensorValue2 = analogRead(sensorPin2); // update sensorValue2
  sensorValue3 = analogRead(sensorPin3); // update sensorValue2

  roomLight = (sensorValue1 + sensorValue2 + sensorValue3) / 3;   // calculate average

  return roomLight;   // return roomLight value
}
```

**Comments:**

For this excercise, I created a program that would use 3 LDR to read the light value of a room, and return an average of the three resdings. 
