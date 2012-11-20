#include <ContinuousRotationServo.h>

ContinuousRotationServo Servo;
int distance;

void setup()
{
  Servo.begin(2);
}

void loop()
{
  Servo.rotate(-50);
}
