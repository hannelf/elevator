#include "hardware.h"
#include "queue.h"
#include "fsm.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>




Elevator elevator;




int move_to_next_floor(Elevator* elevator) {
	int current_f = elevator->current_floor;
	int next_f= next_floor(elevator);
	while (current_f<next_f){
		hardware_command_movement(HARDWARE_MOVEMENT_UP);
		return 0;
	}
	while (current_f>next_f){
		hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
		return 0;
	}

	while (current_f==next_f){
		hardware_command_movement(HARDWARE_MOVEMENT_STOP);
		return 1;
	}
	
}




void current_floor(Elevator* elevator){
	int floor=-1;
	for (int n=0; n=<HARDWARE_NUMBER_OF_FLOORS; n++){
		if (hardware_read_floor_sensor(n)==1){
			floor=n;
		}
	}
	hardware_command_floor_indicator_on(n)
	*elevator->current_floor=floor;
}


void initialize(Elevator* elevator){
	while (current_floor()==-1){
		hardware_command_movement(HARDWARE_ORDER_DOWN);
		}
	
};








void set_lights(){
	for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; floor++){
		if (hardware_read_order(floor, HARDWARE_ORDER_INSIDE)){
			hardware_command_order_light(floor, HARDWARE_ORDER_INSIDE, 1);
		}
		if (hardware_read_order(floor, HARDWARE_ORDER_UP)){
			hardware_command_order_light(floor, HARDWARE_ORDER_UP, 1);
		}
		if (hardware_read_order(floor, HARDWARE_ORDER_DOWN)){
			hardware_command_order_light(floor, HARDWARE_ORDER_DOWN, 1);
		}
	}
}



void poll_order(){
	while(1){
		for (int n; n=<HARDWARE_NUMBER_OF_FLOORS; n++){
			if (hardware_read_order(n, HARDWARE_ORDER_UP)=1){
					queue_add(elevator, n, 0);
				}
			if (hardware_read_order(n, HARDWARE_ORDER_INSIDE)=1){
					queue_add(elevator, n, 1);
				}
			if (hardware_read_order(n, HARDWARE_ORDER_DOWN)=1){
					queue_add(elevator, n, 2);		
				}
		}
	}

}




int fsm(Elevator* elevator){
	//trenger å definere current_state=state eller noe
while(1)
	switch (current_state){
		case IDLE:
			poll_order();
			if (hardware_read_stop_signal()){
				current_state = STOP;
				break;
			}
			if (next_floor(elevator)==-1){
				current_state = IDLE;
			}
			if (next_floor(elevator)!=)-1{
				current_state=MOVING;
			}
	
		case MOVING:
			if (hardware_read_stop_signal()){
				current_state = STOP;
				break;
			}
			poll_order();
	
			while (move_to_next_floor(elevator*)){ //peker riktig?
				current_state= LOADING;
			}
			
			

		case LOADING:
			if (hardware_read_stop_signal()){
				current_state = STOP;
				break;
			}
			poll_order();
			else if (is_on_floor){
				hardware_command_movement(HARDWARE_MOVEMENT_STOP)
				queue_remove()
				hardware_command_door_open(1);
				current_time = set_timer();
				while (current_time < timer_stop){
					if (hardware_read_stop_signal() || hardware_read_obstruction_signal()){
						\\dør forbli åpen + 3 sek lengre enn knapper
					}

				}
				
			}

			for(){
			}
			else if (queue[n][n] == 0){
				hardware_command_door_open(0);
			}

		case STOP:
			poll_order();
			while (hardware_read_stop_signal()){
				hardware_command_stop_light(1);
			}		
	}
	return 0;
}

