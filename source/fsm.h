
/**
*@file 
*@brief Our finite state machine for the elevator
*/




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






/**
*@brief initializes the elevater. Makes it go down if it is between floors
*/
void initialize(Elevator* elevator);


/**
*@brief returns the current floor
*/
int current_floor(Elevator* elevator);



void move_to_next_floor(Elevator* elevator);

#define Nr_ordertypes= 3;



void set_lights();

void poll_order();

int fsm(Elevator* elevator);