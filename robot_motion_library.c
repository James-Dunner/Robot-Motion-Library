/*
 * robot_motion_library.c
 *
 *  Created on: Dec 14, 2013
 *      Author: C14James.Dunn
 */

#include "msp430.h"
#include "robot_motion_library.h"

void initRobot(void)
{
	 P1DIR |= BIT1|BIT2;					// TA0CCR0 on P1.1 and TA0CCR1 on P1.2
	 P1SEL |= BIT1|BIT2;

	 P2DIR |= BIT0|BIT1;					// TA1CCR0 on P2.0 and TA1CCR1 on P2.1
	 P2SEL |= BIT0|BIT1;

	 TA0CTL &= ~(MC1|MC0); 					// Stop the timer
	 TA0CTL |= TACLR;  						// Clear the timer
	 TA0CTL |= TASSEL1; 					// Select SMCLK

	 TA0CCR0 = 100; 						// Define period as 100
	 TA0CCR1 = 50; 							// Defines 50% duty cycle

	 TA0CTL |= MC0;  						// Enables the clock by having it count up to TA0CCR0

	 TA1CTL &= ~(MC1|MC0); 					// Stop the timer
	 TA1CTL |= TACLR; 						// Clear the other timer
	 TA1CTL |= TASSEL1; 					// Select SMCLK

	 TA1CCR0 = 100; 						// Define period as 100
	 TA1CCR1 = 50; 							// Defines 50% duty cycle

	 TA1CTL |= MC0;  						// Enables the clock by having it count up to TA1CCR0
}

void clearLeftMotor(void)
{
	 TA0CCTL0 &= ~OUTMOD_7;					// Clear mode
	 TA0CCTL1 &= ~OUTMOD_7;
}

void clearRightMotor(void)
{
	 TA1CCTL0 &= ~OUTMOD_7;					// Clear mode
	 TA1CCTL1 &= ~OUTMOD_7;
}

void leftMotorBackward(void)
{
	clearLeftMotor();

	TA0CCTL1 |= OUTMOD_5;       			// Reset mode
    TA0CCTL0 |= OUTMOD_4;					// Reset/set mode
}

void leftMotorForward(void)
{
	clearLeftMotor();

	TA0CCTL1 |= OUTMOD_7;       			// Reset/set mode
	TA0CCTL0 |= OUTMOD_5;					// Reset mode
}

void rightMotorForward(void)
{
	clearRightMotor();

	TA1CCTL1 |= OUTMOD_7;					// Reset/set mode
    TA1CCTL0 |= OUTMOD_5;					// Reset mode
}

void rightMotorBackward(void)
{
	clearRightMotor();

	TA1CCTL1 |= OUTMOD_5;       			// Reset mode
    TA1CCTL0 |= OUTMOD_4;					// Toggle mode
}

void stopLeftMotor(void)
{
	clearLeftMotor();

	TA0CCTL0 |= OUTMOD_5;					// Reset mode
	TA0CCTL1 |= OUTMOD_5;
}

void stopRightMotor(void)
{
	clearRightMotor();

	TA1CCTL0 |= OUTMOD_5;					// Reset mode
	TA1CCTL1 |= OUTMOD_5;
}

void stopBothMotors(void)
{
	stopRightMotor();
	stopLeftMotor();
}

void moveForward(void)
{
	leftMotorForward();
	rightMotorForward();
}

void moveBackward(void)
{
	leftMotorBackward();
	rightMotorBackward();
}

void bigLeftTurn(void)
{
	stopLeftMotor();
	rightMotorForward();
}

void bigRightTurn(void)
{
	stopRightMotor();
	leftMotorForward();
}

void smallLeftTurn(void)
{
	leftMotorBackward();
	rightMotorForward();
}

void smallRightTurn(void)
{
	rightMotorBackward();
	leftMotorForward();
}



