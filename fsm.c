#include "hardware.h"
#include "fsm.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>



void initialize(){
	while (current_floor()==-1){
		hardware_command_movement(HARDWARE_ORDER_DOWN);
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

void idle(){
	
}



//loading

void loading(){
	if (queue==empty){
		 hardware_command_door_open(0);
		}
}


typedef enum {
	IDLE,
	LOADING,
	MOVING,
	STOPP
}state



