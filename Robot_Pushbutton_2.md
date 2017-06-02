## Robot Pushbutton 2

**Code:**

```
// declare variable pushButton and give it a value of "13" (for pin number 13)
int pushButton = 13;

// the setup function runs once when you press reset or power the board
void setup() {
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
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  // delay in between reads for stability
  delay(1);

  // create if condition for buttonState >= 1
  if (buttonState >= 1) {

    // create a while loop for a condition that would always be true in this case
    while (buttonState >= 0) {

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

  }
}
```
**Video + Comments:**

Link: https://youtu.be/Tm9K0TCI8S8

I'm not sure if I created the right program. It does what was asked for the homework, but the logic might not be the right one. I modified the code I hade for the previous excercise and in addition to creating the if condition to make the robot perform the sequence after buttonState was "1" (or when the button was pressed), and added a while loop that would continue for as long as the condition that I define was true, which in this case would always be true since when button is released the value of the variable pushButton goes back to "0". 

*I added another exploration (file) where I get the robot to start/stop when I press the button.
