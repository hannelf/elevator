
/**
*@file 
*@brief Our finite state machine for the elevator
*/



/**
*@brief initializes the elevater. Makes it go down if it is between floors
*/
void initialize();



/**
*@brief returns the current floor
*/
int current_floor()




#define Nr_ordertypes= 3;




typedef enum state{
	IDLE,
	LOADING,
	MOVING,
	STOP
} State;




typedef struct {
	State current_state;
	int current_floor;
	HardwareMovement current_direction;
	int queue[HARDWARE_NUMBER_OF_FLOORS][Nr_ordertypes];
	} Elevator;



