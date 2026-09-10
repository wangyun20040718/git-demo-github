#ifndef TEST_H
#define TEST_H
#include "pointer.h"

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

typedef struct stCdStateAndFunc{
	void (*cdFunc)(void);
	enum state cdState;
}stCdStateAndFunc;


void func_null(void);
void func_loading(void);
void func_ejecting(void);
void func_startplay(void);
void func_play(void);
void func_pause(void);
void func_ff(void);
void func_rew(void);
void func_stop(void);
void cdStateMoveFunc(void);
#endif
