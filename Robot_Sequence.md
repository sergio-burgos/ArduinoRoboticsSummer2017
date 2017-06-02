Robot Sequence

// setup function runs once at the beginning
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (12, OUTPUT);

  // power motors using analog write to control how much power I want to give them. In this case 200/255
  analogWrite (6, 200);
  analogWrite (12, 200);
}

// create loop function for sequence
void loop() {
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
