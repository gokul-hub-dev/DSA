#include <stdlib.h>
#include <stdio.h>
typedef enum{
	NO_EVENT_RECEIVED,
	IDEL_RECEIVED,
	START_RECEIVED,
	STOP_RECEIVED
}t_event;
typedef enum
{
	STATE_INIT,
	STATE_IDEL,
	STATE_START,
	STATE_STOP
}t_state;
static t_state current_state=STATE_INIT;

void state_init()
{
	current_state=STATE_IDEL;
	printf("initiazling......\n");
}
void print_current_state()
{
	if(current_state == STATE_IDEL)
		printf("state idel....................\n");
	else if(current_state == STATE_START)
		printf("state start...................\n");
	else if(current_state == STATE_STOP)
		printf("state stop....................\n");
}
t_event get_event()
{
	int input_char;
	t_event ret = NO_EVENT_RECEIVED;
	print_current_state();
	printf("check the pin status:\n");
	scanf("%d",&input_char);
	switch(input_char)
	{
		case 1:
			ret = IDEL_RECEIVED;
			break;
		case 2:
			ret = START_RECEIVED;
			break;
		case 3:
			ret = STOP_RECEIVED;
			break;
		default:
			break;
	}
	return ret;
}
void state_idel(t_event event)
{
	if((event == IDEL_RECEIVED)||(event == NO_EVENT_RECEIVED))
		current_state=STATE_IDEL;
	else if(event == START_RECEIVED)
		current_state=STATE_START;
	else if(event == STOP_RECEIVED)
		current_state=STATE_STOP;
}
void state_start(t_event event)
{
	if((event == IDEL_RECEIVED)||(event == NO_EVENT_RECEIVED))
		current_state=STATE_IDEL;
	else if(event == START_RECEIVED)
		current_state=STATE_START;
	else if(event == STOP_RECEIVED)
		current_state=STATE_STOP;
}
void state_stop(t_event event)
{
	if((event == IDEL_RECEIVED)||(event == NO_EVENT_RECEIVED))
		current_state=STATE_IDEL;
	else if(event == START_RECEIVED)
		current_state=STATE_START;
	else if(event == STOP_RECEIVED)
		current_state=STATE_STOP;
}
void state_machine()
{
	t_event event=get_event();
	switch(current_state)
	{
		case STATE_IDEL:
			state_idel(event);
			break;
		case STATE_START:
			state_start(event);
			break;
		case STATE_STOP:
			state_stop(event);
			break;
		default:
			break;
	}
}
	
int main()
{
	state_init();
	for(;;)
	{
		state_machine();
	}
}
