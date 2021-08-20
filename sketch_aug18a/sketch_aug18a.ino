#include<math.h>

#define X A0
#define Y A1

int xVal;
int yVal;
String xDir;
String yDir;
String outputString;

void setup() {
  // put your setup code here, to run once:
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(X);
  yVal = analogRead(Y);

  
  yVal = 1023 - yVal;
  yVal -= 512;
  xVal -= 512;


  // Check if joystick is at origin
  if (xVal == 0 && yVal == 0) {
    outputString = "Origin";
  }
  else {
    xDir =  (xVal < 0) ? "left" : "right"; //determine the sign of x and y componenents
    yDir = (yVal < 0) ? "down" : "up";

    //if x and y components equal magnitude, concatentate them
    if (abs(xVal) == abs(yVal)) {
      outputString = xDir + " " + yDir;
    } 
    
    //Otherwise, determine which component is more significant
    else {
      outputString = (abs(xVal) > abs(yVal)) ? xDir : yDir;
    }
  }

  //Output string now contains the correct direction
  Serial.print(outputString);

  /*int r = sqrt(xVal*xVal + yVal*yVal);

  int theta = atan2(yVal, xVal);
  if (yVal < 0){
    theta = 360 - theta;
  }*/
}
