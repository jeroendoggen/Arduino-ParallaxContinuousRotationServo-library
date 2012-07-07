#include <ContinuousRotationServo.h>

ContinuousRotationServo Servo;
int distance;

void setup()
{
  Servo.begin(2);
}

void loop()
{
  Servo.rotateLeft(50,100);
  Servo.noMovement(500);
  Servo.rotateRight(50,100);
  Servo.noMovement(500);
}
