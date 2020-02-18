



int order_up[3];
int order_down[3];
int command[4];

void new_order(){
	int bestilling;
	if (hardware_read_order(0,HARDWARE_ORDER_UP)=1){
		order_up[0]=1}
	if (hardware_read_order(1,HARDWARE_ORDER_UP)=1){
		order_up[1]=1}
	if (hardware_read_order(2,HARDWARE_ORDER_UP)=1){
		order_up[2]=1}
	if (hardware_read_order(1,HARDWARE_ORDER_DOWN)=1){
		order_up[0]=1}
	if (hardware_read_order(2,HARDWARE_ORDER_DOWN)=1){
		order_up[1]=1}
	if (hardware_read_order(3,HARDWARE_ORDER_DOWN)=1){
		order_up[2]=1}
	if (hardware_read_order(0,HARDWARE_ORDER_INSIDE)=1){
		order_up[0]=1}
	if (hardware_read_order(1,HARDWARE_ORDER_INSIDE)=1){
		order_up[1]=1}
	if (hardware_read_order(2,HARDWARE_ORDER_INSIDE)=1){
		order_up[2]=1}
	if (hardware_read_order(3,HARDWARE_ORDER_INSIDE)=1){
		order_up[3]=1}
}

int next_floor(){
	for (int n=1; n<3 ;n++){
		if (command[n]==1){
			if (current_floor()<n){hardware_command_movement(HARDWARE_MOVEMENT_UP)}
			if (current_floor()>n){hardware_command_movement(HARDWARE_MOVEMENT_DOWN)}
			else {}
		}

	}

}
