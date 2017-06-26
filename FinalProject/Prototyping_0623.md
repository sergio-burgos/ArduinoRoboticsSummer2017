## Prototyping 06/23

After adding the shield library I was able to look at some of the examples programs they had in the tutorial and test the robot with the new code. The tutorial I followed was found on the "learn" section of the Adafruit website (
https://learn.adafruit.com/16-channel-pwm-servo-driver/using-the-adafruit-library) and uses content from this Github repository (https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library). Instead of the conventional servo library, this shield was using "Wire.h" and "Adafruit_PWMServoDriver.h" libraries. This library also required that I converted from degrees to pulse lengths in order to understand the logic behind the rotations of the servo motors which would eventually make the robot move the way I want it to. Instead of having an angle between 0-180 degrees, I had a range between 150-600 pulse length.

At this point, I replaced some of the nuts and bolt I had because they kep falling off. I also thought it would be a good idea to use a hot glue gun to make sure some of the nuts I added were not moving in ways I didn't want them to, specially now that I was working on creating code to make the robot move forward. After doing this, I also glued the battery holder on the bottom of the robot.

Here is a video of how I started thinking of ways to make this robot move: https://youtu.be/JItx2b7Y19U. 

**Photos:**

![img_0790 3](https://user-images.githubusercontent.com/28915361/27553834-6695fad2-5a61-11e7-90fe-dfe75c7aa68b.JPG)

> Adding hot glue to the nuts to avoid them falling off.

![img_0805](https://user-images.githubusercontent.com/28915361/27553976-d248919a-5a61-11e7-8eb0-7408a13b4766.JPG)

> Adding hot glue to the nuts to avoid them falling off.

![img_0789](https://user-images.githubusercontent.com/28915361/27553848-6f40c61c-5a61-11e7-9248-72fcb668ed65.JPG)
![img_0791](https://user-images.githubusercontent.com/28915361/27553862-7585961a-5a61-11e7-9121-0bd5757d135a.JPG)
![img_0792](https://user-images.githubusercontent.com/28915361/27553865-77856da0-5a61-11e7-90c3-e4c4a52ddb01.JPG)
![img_0793](https://user-images.githubusercontent.com/28915361/27553867-7c65ee4e-5a61-11e7-8583-466488f771cc.JPG)

> The spider robot almost done!
