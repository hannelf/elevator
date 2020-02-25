#include "hardware.h"
#include "queue.h"
#include "fsm.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>




Elevator elevator;








void current_floor(){
	int floor=-1;
	for (int n=0; n=<HARDWARE_NUMBER_OF_FLOORS; n++){
		if (hardware_read_floor_sensor(n)==1){
			floor=n;
		}
	}
	hardware_command_floor_indicator_on(n)
	elevator->current_floor=n;

	
}


void initialize(){
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




int fsm(){
	//trenger å definere current_state=state eller noe
while(1)
	switch (current_state){
		case IDLE:
			update_floor();
			poll_order();
			if (hardware_read_stop_signal()){
				current_state = STOP;
				break;
			}
			else if (hardware_read_order()){
				if (hvis den er i samme etasje som order_down/up ) {
					current_state = LOADING
				}
			}
	
		case MOVING:
			if (hardware_read_stop_signal()){
				current_state = STOP;
				break;
			}
			poll_order();
			else if (bestilling er til en etasje under current_floor){
				HARDWARE_MOVEMENT_DOWN;
			}
			else if (bestilling er til etasje over current_floor){
				HARDWARE_MOVEMENT_UP;
			}
			else if (inside_order er til en etasje under current floor){
				
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

