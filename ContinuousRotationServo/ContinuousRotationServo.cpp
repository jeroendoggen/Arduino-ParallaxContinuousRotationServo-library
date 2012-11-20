// ContinuousRotationServo.h - Arduino library to control a Parallax (Futaba)Continuous Rotation Servo
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
// For more information: variable declaration, changelog,... see ContinuousRotationServo.h
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include <ContinuousRotationServo.h>

/// Constructor
ContinuousRotationServo::ContinuousRotationServo()
{
  _servoPin=0;
  _offset=0;
}

/// Begin function to set pins: default servoPin = 2.
void ContinuousRotationServo::begin()
{
  begin (2);
}

/// Begin variables
/// - int _servoPin: the pin to control the servo
void ContinuousRotationServo::begin(int servoPin)
{
  _servoPin=servoPin;
  pinMode(_servoPin, OUTPUT);
}

/// rotate(int speed): Rotate at a given speed (and direction) between -100 and +100
void ContinuousRotationServo::rotate(int speed)
{
                                                  // needs to be known/calculated before delayMicroseconds is called
  _offset = map(constrain(speed,-100,100), 0, 100, 0, 200);
  digitalWrite(_servoPin,HIGH);
  delayMicroseconds(1500 + _offset);
  digitalWrite(_servoPin,LOW);
  delay(20);                                      //20 ms
}


/// rotateLeft(int speed): Rotate left at a speed between 0 and +100
void ContinuousRotationServo::rotateLeft(int speed)
{
                                                  // needs to be known/calculated before delayMicroseconds is called
  _offset = map(constrain(speed,0,100), 0, 100, 0, 200);
  digitalWrite(_servoPin,HIGH);
  delayMicroseconds(1500 + _offset);
  digitalWrite(_servoPin,LOW);
//delay(20);  //20 ms
}


/// rotateRight(int speed): Rotate right at a speed between 0 and +100
void ContinuousRotationServo::rotateRight(int speed)
{
                                                  // needs to be known/calculated before delayMicroseconds is called
  _offset = map(constrain(speed,0,100), 0, 100, 0, 200);
  digitalWrite(_servoPin,HIGH);
  delayMicroseconds(1500 - _offset);
  digitalWrite(_servoPin,LOW);
//delay(20);  //20 ms
}

/// delay: after evey 20 ms servo expects our signal
void ContinuousRotationServo::delayServo(int time)
{
  delay(time);                                    //20 ms
}

/// rotateLeft(int speed): Rotate left at a speed between 0 and +100 for 'time' loops
void ContinuousRotationServo::rotateLeft(int speed, int time)
{
  for(int count=0;count<time;count++)
  {
    rotateLeft(speed);
  }
}

/// rotateLeft(int speed): Rotate right at a speed between 0 and +100 for 'time' loops
void ContinuousRotationServo::rotateRight(int speed, int time)
{
  for(int count=0;count<time;count++)
  {
    rotateRight(speed);
  }
}

/// rotateLeft(int speed): No movement
void ContinuousRotationServo::noMovement()
{
  digitalWrite(_servoPin,HIGH);
  delayMicroseconds(1500);
  digitalWrite(_servoPin,LOW);
  delay(20);                                      //20 ms
}

/// rotateLeft(int speed): No movement for 'time' miliseconds
void ContinuousRotationServo::noMovement(int time)
{
  noMovement();
  delay(time);
}
