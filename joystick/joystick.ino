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
  Serial.print("X value: " + String(xVal)+"\n");
  Serial.print("Y value: " + String(yVal)+"\n");




  // Check if joystick is at origin
  if (abs(xVal) <= 25 && abs(yVal) <= 25) {
    outputString = "Origin";
    Serial.print(outputString+"\n");
  }
  else {
    xDir =  (xVal < -25) ? "left" : "right"; //determine the sign of x and y componenents
    yDir = (yVal < -25) ? "down" : "up";
    
      outputString = (abs(xVal) > abs(yVal)) ? xDir : yDir;
      Serial.print(outputString+"\n");
    }
  delay(1000);
}
/*

  //Output string now contains the correct direction
  //Serial.print(outputString);

  int r = sqrt(xVal*xVal + yVal*yVal);

  int theta = atan2(yVal, xVal);
  if (yVal < 0){
    theta = 360 - theta;
  }
}*/
