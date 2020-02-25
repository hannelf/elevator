#include "queue.h"
#include "hardware.h"
#include "fsm.h"



int next_floor(){
	for (int n=1; n<3 ;n++){
		if (command[n]==1){
			if (current_floor()<n){hardware_command_movement(HARDWARE_MOVEMENT_UP)}
			if (current_floor()>n){hardware_command_movement(HARDWARE_MOVEMENT_DOWN)}
			else {}
		}

	}



void queue_add(Elevator* elevator, int floor, int button ){
	elevator->queue[floor][button]=1;
}


void queue_remove(Elevator* elevator){
	for (int n=0; n=<Nr_ordertypes;n++){
		elevator->queue[current_floor][n]=0;
		hardware_command_order_light(floor, HARDWARE_ORDER_INSIDE, 0);
		hardware_command_order_light(floor, HARDWARE_ORDER_DOWN, 0);
		hardware_command_order_light(floor, HARDWARE_ORDER_UP, 0);

	}
	
}























