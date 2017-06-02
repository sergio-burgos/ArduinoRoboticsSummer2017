## Robot Pushbutton Exploration (Not part of the HW)

In this code I get the robot to start/stop when the pushbutton is pressed. I got this code to work by following this tutorial I found on YouTube: https://www.youtube.com/watch?v=1C-3P_hmd70

**Code:**

```
// declare variable pushButton and give it a value of "13" (for pin number 13)
int pushButton = 13;
boolean buttonState = LOW;
int motorEnabled = 0;
boolean previousButtonState = LOW;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode (pushButton, INPUT);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (12, OUTPUT);

  analogWrite (6, 200);
  analogWrite (12, 200);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// create loop function for sequence
void loop() {
  // read the input pin:
  buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  // delay in between reads for stability
  delay(1);

  // create if condition for buttonState >= 1
  if (previousButtonState != buttonState && buttonState == HIGH) {
    motorEnabled = !motorEnabled;
  }

  if (motorEnabled == 1) {

    // make robot move forward for half a second (500 miliseconds)
    digitalWrite (2, HIGH);
    digitalWrite (4, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (10, LOW);
    delay(500);

    // make robot stop for half a second (500 miliseconds)
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, LOW);
    digitalWrite (10, LOW);
    delay(500);

    // make robot move backwards for half a second (500 miliseconds)
    digitalWrite (2, LOW);
    digitalWrite (4, HIGH);
    digitalWrite (8, LOW);
    digitalWrite (10, HIGH);
    delay(500);

    // make robot stop for half a second (500 miliseconds). This is added so it makes the robot stop before moving forward againat the beginning of the loop function.
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, LOW);
    digitalWrite (10, LOW);
    delay(500);
  }

  else {
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, LOW);
    digitalWrite (10, LOW);
  }

  previousButtonState = buttonState;

}
```
**Videos + Comments:**

Link: https://youtu.be/EIs3La_bZZ8
Link 2: https://youtu.be/MlgPWlYQ938

I looked at different tutorials to understand the logic to make the robot perform the sequence when the button was pressed at least once, and then stop when it was pressed again. I took the code I had for the Robor_PushButton_2 file and added some of the code I saw on the YouTube tutorial and was able to successfully make it work. Although, I identified a delay that doesn't make the robot stop as soon as the button is pressed. What I have to do to make it stop is press the button and hold it down.  I'm not really sure why this happens, but it was fun getting it to do what I wanted it to do.

The first video shows the robot on the floor and moving, but since it was hard to show in detail what happened when I pressed the button, I added a second one of me holding the robot and just showing its behavior.
