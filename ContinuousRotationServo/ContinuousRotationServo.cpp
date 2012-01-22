/************************************************************************************************************
 * ContinuousRotationServo.h - Arduino library to control a Parallax (Futaba)Continuous Rotation Servo      *
 * Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)                                                    *
 * For more information: variable declaration, changelog,... see ContinuousRotationServo.h                  *
 ************************************************************************************************************
 * This library is free software; you can redistribute it and/or                                            *
 * modify it under the terms of the GNU Lesser General Public                                               *
 * License as published by the Free Software Foundation; either                                             *
 * version 2.1 of the License, or (at your option) any later version.                                       *
 *                                                                                                          *
 * This library is distributed in the hope that it will be useful,                                          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of                                           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU                                        *
 * Lesser General Public License for more details.                                                          *
 *                                                                                                          *
 * You should have received a copy of the GNU Lesser General Public                                         *
 * License along with this library; if not, write to the Free Software                                      *
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA                               *
 ***********************************************************************************************************/

/// <summary>
/// ContinuousRotationServo.cpp - Library for ....
/// For more information: variable declaration, changelog,... see ContinuousRotationServo.h
/// </summary>

#include <ContinuousRotationServo.h>
#include <ContinuousRotationServo.h>

/// <summary>
/// Constructor
/// </summary>
ContinuousRotationServo::ContinuousRotationServo()
{
}

/// <summary>
/// Begin function to set pins: default servoPin = 2.
/// </summary>
void ContinuousRotationServo::begin()
{
	begin (2);
}

/// <summary>
/// Begin variables
/// - int _servoPin: the pin to control the servo
/// </summary>
void ContinuousRotationServo::begin(int servoPin)
{
	_servoPin=servoPin;
	pinMode(_servoPin, OUTPUT);
}

/// <summary>
/// rotate(int speed): Rotate at a given speed (and direction) between -100 and +100
/// </summary>
void ContinuousRotationServo::rotate(int speed)
{
	_offset = map(constrain(speed,-100,100), 0, 100, 0, 200); // needs to be known/calculated before delayMicroseconds is called
	digitalWrite(_servoPin,HIGH);
	delayMicroseconds(1500 + _offset);
	digitalWrite(_servoPin,LOW);
	delay(20);  //20 ms
}

/// <summary>
/// rotateLeft(int speed): Rotate left at a speed between 0 and +100
/// </summary>
void ContinuousRotationServo::rotateLeft(int speed)
{
	_offset = map(constrain(speed,0,100), 0, 100, 0, 200); // needs to be known/calculated before delayMicroseconds is called
	digitalWrite(_servoPin,HIGH);
	delayMicroseconds(1500 + _offset);
	digitalWrite(_servoPin,LOW);
	delay(20);  //20 ms
}

/// <summary>
/// rotateRight(int speed): Rotate right at a speed between 0 and +100
/// </summary>
void ContinuousRotationServo::rotateRight(int speed)
{
	_offset = map(constrain(speed,0,100), 0, 100, 0, 200); // needs to be known/calculated before delayMicroseconds is called
	digitalWrite(_servoPin,HIGH);
	delayMicroseconds(1500 - _offset);
	digitalWrite(_servoPin,LOW);
	delay(20);  //20 ms 
}

/// <summary>
/// rotateLeft(int speed): Rotate left at a speed between 0 and +100 for 'time' loops
/// </summary>
void ContinuousRotationServo::rotateLeft(int speed, int time)
{
	  for(int count=0;count<time;count++){
	  rotateLeft(speed);
	  }	
}

/// <summary>
/// rotateLeft(int speed): Rotate right at a speed between 0 and +100 for 'time' loops
/// </summary>
void ContinuousRotationServo::rotateRight(int speed, int time)
{
	  for(int count=0;count<time;count++){
	  rotateRight(speed);
	  }
}

/// <summary>
/// rotateLeft(int speed): No movement
/// </summary>
void ContinuousRotationServo::noMovement()
{
	digitalWrite(_servoPin,HIGH);
	delayMicroseconds(1500);
	digitalWrite(_servoPin,LOW);
	delay(20);  //20 ms 
}

/// <summary>
/// rotateLeft(int speed): No movement for 'time' miliseconds
/// </summary>
void ContinuousRotationServo::noMovement(int time)
{
	noMovement();
	delay(time); 
}
