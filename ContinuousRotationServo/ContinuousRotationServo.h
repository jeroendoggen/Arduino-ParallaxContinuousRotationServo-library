// ContinuousRotationServo.h - Arduino library to control a Parallax (Futaba)Continuous Rotation Servo
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//  More info: http://www.parallax.com/tabid/768/ProductID/102/Default.aspx
//
// Version History:
//  Version 0.1: rotate, rotateLeft, rotateRight, noMovement (speed) and (speed,time)
// Roadmap:
//  Version 0.2: ??
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

#ifndef ContinuousRotationServo_h
#define ContinuousRotationServo_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

class ContinuousRotationServo
{
  public:
    ContinuousRotationServo();
    void begin();
    void begin(int servoPin);

    void rotate(int speed);

    void rotateLeft(int speed);
    void rotateRight(int speed);

    void rotateLeft(int speed, int time);
    void rotateRight(int speed, int time);

    void noMovement();
    void noMovement(int time);
    void delayServo(int time);

  private:
    int _servoPin;
    int _offset;
};
#endif
