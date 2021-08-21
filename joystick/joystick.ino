#include <math.h>

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
string getDirection(int, int);

void setup()
{
  // put your setup code here, to run once:
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  Serial.begin(9600);
  Serial.setTimeout(10000);
}

void loop()
{
  
  xRaw = analogRead(X);
  yRaw = analogRead(Y);

  // Remap 
  xVal = map(xRaw, 0, 1023, -512, 512);
  //Y input range increases as it goes down, so range must be flipped
  yVal = map(yRaw, 1023, 0, -512, 512);

  int r = getPolarRadius(xVal, yVal);
  double theta = getPolarAngle(xVal, yVal);
}


int getPolarRadius(int x, int y)
{
  return sqrt(x * x + y * y);
}

//Returns polar angle in degrees, from 0 to 360
double getPolarAngle(int x, int y)
{
  double theta = atan2(y, x);
  theta = 180 / 3.14 * theta;
  if (theta < 0)
  {
    theta = 360 + theta;
  }
  return theta;
}

//Returns string of direction of input. 
string getDirection(int xVal, int yVal)
{
  const int center = 25; //Range of volatage magnitudes that should register as no input (origin)
  string outputString;
  // Check if joystick is at origin
  if (abs(xVal) <= center && abs(yVal) <= center)
  {
    outputString = "Origin";
  }
  else
  {
    xDir = (xVal < -center) ? "left" : "right"; //determine the sign of x and y componenents
    yDir = (yVal < -center) ? "down" : "up";
    outputString = (abs(xVal) > abs(yVal)) ? xDir : yDir;
  }
  return outputString;
}