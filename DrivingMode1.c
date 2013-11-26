#pragma config(Hubs  ,  S1         , HTMotor   , HTMotor               ,  HTMotor, none     )
#pragma config(Sensor,  S1         ,           , sensorI2CMuxController                     )
#pragma config(Motor ,  mtr_S1_C1_1, leftDrive , tmotorTetrix          , openLoop, reversed )
#pragma config(Motor ,  mtr_S1_C1_2, rightDrive, tmotorTetrix          , openLoop           )
#pragma config(Motor ,  mtr_S1_C3_2, arm       , tmotorTetrix          , openLoop           )
#pragma config(Motor ,  mtr_S1_C2_2, elbow     , tmotorTetrix          , openLoop           )
#pragma config(Motor ,  mtr_S1_C3_1, spinner   , tmotorTetrix          , openLoop           )
#pragma config(Motor ,  mtr_S1_C2_1, gripper   , tmotorTetrix          , openLoop           )
//Setup Motors^

//For control mappings refer to /notes.txt

//Allow Use Of Joysticks:
#pragma  debuggerWindows("joystickSimple");
#include "JoystickDriver.c"

//Define Constants:
const int THRESHOLD  =10;
const int SPEED_MULT =1 ;

//Main Code:
task main(){
	while(true){ //Repeat the following forever:

		{ // Driving code:
			if(abs(SPEED_MULT * joystick.joy1_y1) > THRESHOLD) { //If the joystick is outside of the deadzone:
				motor[leftDrive] = SPEED_MULT * joystick.joy1_y1;   //Set motor speed to joystick value * multiplier
			}else{                                               //Otherwise:
				motor[leftDrive] = 0;                               //Set motor to 0
			}
			if(abs(SPEED_MULT * joystick.joy1_y2) > THRESHOLD) { //If the joystick is outside of the deadzone:
				motor[rightDrive] = SPEED_MULT * joystick.joy1_y2;   //Set motor speed to joystick value * multiplier
			}else{                                               //Otherwise:
				motor[rightDrive] = 0;                               //Set motor to 0
			}
		}

		{
			
		}
	}
}
