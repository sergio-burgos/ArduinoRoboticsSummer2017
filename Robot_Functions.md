## Robot Obstacles Using Functions

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
  // create long variables for duration and distance
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

  // create condition for robot to move, stop, and turn when distance is < 20 cm
  else {

    // call function to make robot stop before turning
    pause();
    delay(500);

    // call function to make robot turn right
    turnRight();
    delay(500);

    // call function to make robot stop after making a turn
    pause();
    delay(500);
  }
}

// create function 'pause'
void pause() {
  digitalWrite (2, LOW);
  digitalWrite (4, LOW);
  digitalWrite (8, LOW);
  digitalWrite (10, LOW);
}

// create function 'turnRight'
void turnRight() {
  digitalWrite (2, LOW);
  digitalWrite (4, LOW);
  digitalWrite (8, HIGH);
  digitalWrite (10, LOW);
}



```
