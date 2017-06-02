## Robot Sequence

**Code:**

```
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
```
**Photos:**

![img_0217](https://cloud.githubusercontent.com/assets/28915361/26741081/e09982f0-478c-11e7-971b-6d1440aa28a0.JPG)

![img_0214](https://cloud.githubusercontent.com/assets/28915361/26741120/fb6daa84-478c-11e7-873b-912663487b1b.JPG)

![img_0216](https://cloud.githubusercontent.com/assets/28915361/26741173/26fb62f4-478d-11e7-80f9-257d5aed809e.JPG)

![img_0215](https://cloud.githubusercontent.com/assets/28915361/26741150/12bd110c-478d-11e7-8dbd-b3887842d19d.JPG)

**Video + Comments:**




