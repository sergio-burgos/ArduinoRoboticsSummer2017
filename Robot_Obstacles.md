## Robot Obstacles

**Code:**

```
// defining constant variables for distance measuring sensor pins
const int trigPin = 7;
const int echoPin = 9;

// setup function runs once at the beginning
void setup() {
  // initialize digital pins for motors as an output
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (12, OUTPUT);

  // control motor speed by using analog write to control how much power I want to give them
  analogWrite (6, 200);
  analogWrite (12, 200);

  // intialize Serial
  Serial.begin (9600);

  // initialize trigPin and echoPin as output and input, respectively
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// create loop function for sequence
void loop() {

  long duration, distance;

  // Drive trigger pin LOW, HIGH, LOW to send the pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // low for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // high for 10 microseconds
  digitalWrite(trigPin, LOW);

  // the pulseIn command waits for a given pin to go HIGH, and then
  // reports how long it waited until that happened
  duration = pulseIn(echoPin, HIGH); // measure the time to the echo

  // Convert to centimeters
  distance = (duration / 2) / 29.1; // calculate the distance in cm

  // Discard readings that are too large or too small to be reasonable
  // It's pretty common for some sensors to give occasional bad readings
  // and a good program must take that into account
  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range; reading invalid");
  } else {
    // anything left should be a valid distance
    Serial.print(distance);
    Serial.println(" cm");
  }

  // create if condition for robot to move forward as long as distance is >= 20 cm
  if (distance >= 20) {

    // make robot move forward for half a second (500 miliseconds)
    digitalWrite (2, HIGH);
    digitalWrite (4, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (10, LOW);
    delay(1000);
  }

  // create if condition for robot to move stop and turn when distance is < 20 cm
  else {

    // make robot stop before turning
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, LOW);
    digitalWrite (10, LOW);
    delay(500);

    // make robot turn right
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (10, LOW);
    delay(500);

    // make robot stop after making a turn
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, LOW);
    digitalWrite (10, LOW);
    delay(500);
  }
}

```

**Code 2:**

```
// defining constant variables for distance measuring sensor pins
const int trigPin = 7;
const int echoPin = 9;

// setup function runs once at the beginning
void setup() {
  // initialize digital pins for motors as an output
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (12, OUTPUT);

  // control motor speed by using analog write to control how much power I want to give them
  // analogWrite (6, 150);
  // analogWrite (12, 150);

  // intialize Serial
  Serial.begin (9600);

  // initialize trigPin and echoPin as output and input, respectively
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// create loop function for sequence
void loop() {

  long duration, distance;

  // Drive trigger pin LOW, HIGH, LOW to send the pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // low for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // high for 10 microseconds
  digitalWrite(trigPin, LOW);

  // the pulseIn command waits for a given pin to go HIGH, and then
  // reports how long it waited until that happened
  duration = pulseIn(echoPin, HIGH); // measure the time to the echo

  // Convert to centimeters
  distance = (duration / 2) / 29.1; // calculate the distance in cm

  // Discard readings that are too large or too small to be reasonable
  // It's pretty common for some sensors to give occasional bad readings
  // and a good program must take that into account
  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range; reading invalid");
  } else {
    // anything left should be a valid distance
    Serial.print(distance);
    Serial.println(" cm");
  }

  // create if condition for robot to move forward as long as distance is >= 20 cm
  if (distance >= 20) {

    analogWrite (6, 150);
    analogWrite (12, 150);

    // make robot move forward for half a second (500 miliseconds)
    digitalWrite (2, HIGH);
    digitalWrite (4, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (10, LOW);
    delay(1000);

  }

  // create if condition for robot to move stop and turn when distance is < 20 cm
  else {

    analogWrite (6, 150);
    analogWrite (12, 150);

    // make robot stop before turning
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, LOW);
    digitalWrite (10, LOW);
    delay(500);

    analogWrite (6, 200);
    analogWrite (12, 200);

    // make robot turn
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (10, LOW);
    delay(500);

    analogWrite (6, 150);
    analogWrite (12, 150);

    // make robot stop after making a turn
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, LOW);
    digitalWrite (10, LOW);
    delay(500);
  }
}
```

**Video + Comments:**

Link: https://youtu.be/Tm9K0TCI8S8

After building my robot, I realized it would've been impossible to have the distance measuring sensor facing the front without redesigning my lego robot. I decided to check out a small breadboard to add more legos to hold it and place the distance measuring sensor on that second one that could now be reading what was in front of my robot.

For the code, I combined the code I wrote for one of the previous excercises where I made my robot perform a sequence. Using the code we were given for the distance measuring sensor, I incorporated that into my code and made sure I could have both actions being performed when running the program (reading distance and printing it + making the robot run a sequence). After making sure this two worked, I created a condition using the value being read by the sensor and defining that if distance >= 20 cm, the robot could keep moving forward, and if distance < 20, the robot would stop the motors, turn right, and stop one more time before it started moving forward again.

After testing it, I realized I needed to give the motor that was making the robot turn more power to make it do it successfuly. In te second code I added, instead of assignning the speed in setup, I do it inside the loop function. This way I was able to make the motor spin faster (and with more power) when making the robot turn.
