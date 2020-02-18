#include "hardware.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/**
*@file 
*@brief Our finite state machine for the elevator
*/


void initialize(){
	if (current_floor()==-1){
		hardware_command_movement(HARDWARE_ORDER_DOWN)
		}
};



int current_floor(){
	int floor=-1;
	for (int n=0; n<4; n++){
		if (hardware_read_floor_sensor(n)==1){
			floor=n;
		}
	}
	return floor;
	
}
