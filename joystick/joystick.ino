#include<math.h>

#define X A0
#define Y A1

int xVal;
int yVal;
String xDir;
String yDir;
String outputString;

String inX;
String inY;

int getPolarRadius(int, int);
double getPolarAngle(int, int);


void setup() {
  // put your setup code here, to run once:
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  Serial.begin(9600);
  Serial.setTimeout(10000);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(X);
  yVal = analogRead(Y);

  yVal = 1023 - yVal;
  yVal -= 512;
  xVal -= 512;


  // Check if joystick is at origin
  if (abs(xVal) <= 25 && abs(yVal) <= 25) {
    outputString = "Origin";
  }
  else {
    xDir =  (xVal < -25) ? "left" : "right"; //determine the sign of x and y componenents
    yDir = (yVal < -25) ? "down" : "up";
    outputString = (abs(xVal) > abs(yVal)) ? xDir : yDir;
    }
  // Serial.println(outputString);
  //delay(5000);
  Serial.println("Enter x coordinate: ");
  inX = Serial.readStringUntil('\n');
  Serial.println("Enter y coordinate: ");
  inY = Serial.readStringUntil('\n');
  Serial.println("inX: " + inX);
  Serial.println("inY: " + inY);
  Serial.print(inX.toInt());

  xVal = inX.toInt();
  yVal = inY.toInt();
  //Output string now contains the correct direction
  //Serial.print(outputString);

  int r = getPolarRadius(xVal, yVal);
  double theta = getPolarAngle(xVal, yVal);
  Serial.println("R: "+String(r));
  Serial.println("Theta: " + String(theta));


}



int getPolarRadius(int x, int y) {
  return sqrt(x*x + y*y);
}



double getPolarAngle(int x, int y) {
  double theta = atan2(y, x);
  theta = 180/3.14*theta;
  if (theta < 0){
    theta = 360 + theta;
  }
  return theta;
}