#ifndef TEST_H
#define TEST_H

typedef enum state{
	NO_DISC = 0,
	STOP,
	PLAY,
	PAUSE,
	FAST_FORWARD,
	FAST_BACKWARD,
	STATE_NULL     //6
}state;

typedef enum keyInput{
	LOAD_INPUT = 0,
	EJECT_INPUT,
	PLAY_INPUT = 2,
	PAUSE_INPUT = 2,
	FAST_FORWARD_INPUT,
	FAST_BACKWARD_INPUT,
	STOP_INPUT,
	STATE_QUIT_INPUT
}keyInput;

#endif
