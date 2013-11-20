#pragma config(Hubs   , S1          , HTMotor , none                   , none     , none)
#pragma config(Sensor , S1          ,         , sensorI2CMuxController                  )
#pragma config(Motor  , mtr_S1_C1_1 , motor1  , tmotorTetrix           , openLoop       )
#pragma config(Motor  , mtr_S1_C1_2 , motor2  , tmotorTetrix           , openLoop       )
//Setup Motors^

//Allow Use Of Joysticks:
#pragma  debuggerWindows("joystickSimple");
#include "JoystickDriver.c"

//Define Constants:
const int THRESHOLD  =10;
const int SPEED_MULT =1 ;

//Main Code:
task main(){
	while(true){
		if(abs(SPEED_MULT * joystick.joy1_y1) > THRESHOLD) {
			motor[motor1] = SPEED_MULT * joystick.joy1_y1;
		}
		else{
			motor[motor1] = 0;
		}
		if(abs(SPEED_MULT * joystick.joy1_y2) > THRESHOLD) {
			motor[motor2] = SPEED_MULT * joystick.joy1_y2;
		}
		else {
			motor[motor2] = 0;
		}
	}
}
