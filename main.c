#include <msp430.h> 
#include "robot_motion_library.h"

/*
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;									// Stop watchdog timer

    initRobot();
    clearLeftMotor();
    clearRightMotor();

    while(1)
    {
    	moveForward();
    	_delay_cycles(1500000);

    	moveBackward();
    	_delay_cycles(1500000);

    	bigRightTurn();
    	_delay_cycles(2000000);

    	smallLeftTurn();
    	_delay_cycles(1000000);



    }
	
}

