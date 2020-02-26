#include "queue.h"
#include "hardware.h"
#include "fsm.h"




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




int next_floor(Elevator* elevator){
	int next_f = -1;
	int orders[HARDWARE_NUMBER_OF_FLOORS];
	HardwareMovement last_direction;

	while(1){	
		if (elevator->current_driection == HARDWARE_MOVEMENT_UP) {
			last_direction=HARDWARE_MOVEMENT_UP;
			if(queue[elevator->current_floor][0]==1){
				next_f=elevator->current_floor;
			}
		}
		if (elevator->current_driection == HARDWARE_MOVEMENT_DOWN){
			last_direction=HARDWARE_MOVEMENT_DOWN;
			if(queue[elevator->current_floor][2]==1){
				next_f=elevator->current_floor;
			}
		}
	}
	
	while (1) {
		for (int f=0; f = < HARDWARE_NUMBER_OF_FLOORS; f++) {
			for (int o; o = < Nr_ordertypes; o++) {
				if (elevator->queue[f][o]==0){
					next_f=-1;
				}

				if (elevator->current_directon == HARDWARE_MOVEMENT_STOP){
					if (elevator->current_floor==3 && elevator->queue[f][o]==1){
						next_f=f;
						break; //hvor langt ut breaker den her ???
					}
					if (elevator->current_floor==0 && elevator->queue[f][o]==1){
						next_f=f;
						break; //hvor langt ut breaker den her ???
					}
				
					if (last_direction==HARDWARE_MOVEMENT_UP && elevator->queue[f][0]==1 && elevator->current_floor<f){
						next_f=f;
					}
					else if (last_direction==HARDWARE_MOVEMENT_UP && elevator->queue[f][2]==1 && elevator->current_floor<f){
						next_f=f
					}
					if (last_direction==HARDWARE_MOVEMENT_DOWN && elevator->queue[f][2]==1 && elevator->current_floor>f){
						next_f=f;
					}
					else if (last_direction==HARDWARE_MOVEMENT_DOWN && elevator->queue[f][0]==1 && elevator->current_floor>f){
						next_f=f;
					}
					
				}
				

			}
		
		}

	}
	return next_f;
}






















