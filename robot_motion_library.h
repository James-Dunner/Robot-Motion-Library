/*
 * robot_motion_library.h
 *
 *  Created on: Dec 14, 2013
 *      Author: C14James.Dunn
 */

#ifndef ROBOT_MOTION_LIBRARY_H_
#define ROBOT_MOTION_LIBRARY_H_


void initRobot(void);

void clearLeftMotor(void);

void clearRightMotor(void);

void leftMotorForward(void);

void leftMotorBackward(void);

void rightMotorForward(void);

void rightMotorBackward(void);

void stopLeftMotor(void);

void stopRightMotor(void);

void stopBothMotors(void);

void moveForward(void);

void moveBackward(void);

void bigLeftTurn(void);

void bigRightTurn(void);

void smallLeftTurn(void);

void smallRightTurn(void);


#endif /* ROBOT_MOTION_LIBRARY_H_ */
