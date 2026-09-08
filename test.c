#include <stdio.h>
#include <string.h>
#include "test.h"

#define VALID_INPUT 0    
#define INVALID_INPUT 1

int judgeWordValidInput = VALID_INPUT; 


void func_null(void)
{
	printf("Unavailable");
} 

void func_loading(void)
{
	printf("Loading");
} 

void func_ejecting(void)
{
	printf("Ejecting");
} 

void func_startplay(void)
{
	printf("Play from begin");
} 

void func_play(void)
{
	printf("Play");
} 

void func_pause(void)
{
	printf("Pause");
} 

void func_ff(void)
{
	printf("Fast Forward");
} 

void func_rew(void)
{
	printf("Fast Backward");
} 

void func_stop(void)
{
	printf("Stop");
} 

void (*cdFuncArry[])() = {func_loading, func_ejecting, func_startplay, func_play, func_pause, func_ff, func_rew, func_stop, func_null};

typedef struct stCdStateAndFunc{
	void (*cdFunc)(void);
	enum state cdState;
}stCdStateAndFunc;

const struct stCdStateAndFunc cdStateMoveTable[STATE_NULL][STATE_QUIT_INPUT] = {
	/*LOAD_INPUT = 0*/           /*EJECT_INPUT = 1*/          /*PLAY_INPUT/PAUSE_INPUT = 2*/ /*FAST_FORWARD_INPUT = 3*/ /*FAST_BACKWARD_INPUT = 4*/ /*STOP_INPUT = 5*/
	{{func_loading, STOP}, {func_null    , STATE_NULL}, {func_null     , STATE_NULL}, {func_null, STATE_NULL  }, {func_null,    STATE_NULL}, {func_null, STATE_NULL}}, /*NO_DISC*/
	{{func_null   ,     STATE_NULL}, {func_ejecting,    NO_DISC}, {func_startplay,       PLAY}, {func_null, STATE_NULL  }, {func_null,    STATE_NULL}, {func_null, STATE_NULL}}, /*STOP*/
	{{func_null   ,     STATE_NULL}, {func_ejecting,    NO_DISC}, {func_pause    ,      PAUSE}, {func_ff  , FAST_FORWARD}, {func_rew , FAST_BACKWARD}, {func_stop,       STOP}}, /*PLAY*/
	{{func_null   ,     STATE_NULL}, {func_ejecting,    NO_DISC}, {func_play     ,       PLAY}, {func_ff  , FAST_FORWARD}, {func_rew , FAST_BACKWARD}, {func_stop,       STOP}}, /*PAUSE*/
	{{func_null   ,     STATE_NULL}, {func_ejecting,    NO_DISC}, {func_play     ,       PLAY}, {func_null, STATE_NULL  }, {func_null,    STATE_NULL}, {func_stop,       STOP}}, /*FAST_FORWARD*/
	{{func_null   ,     STATE_NULL}, {func_ejecting,    NO_DISC}, {func_play     ,       PLAY}, {func_null, STATE_NULL  }, {func_null,    STATE_NULL}, {func_stop,       STOP}}  /*FAST_BACKWARD*/
}; 

/*将输入的字母转换成状态枚举数值*/
void convertWordToState(char inputWord, keyInput *key_Input)
{
	switch(inputWord)
	{
		case 'L':
			*key_Input = LOAD_INPUT;
			break;			
		case 'E':
			*key_Input = EJECT_INPUT;
			break;
		case 'P':
			*key_Input = PLAY_INPUT;
			break;	
		case 'F':
			*key_Input = FAST_FORWARD_INPUT;
			break;
		case 'R':
			*key_Input = FAST_BACKWARD_INPUT;
			break;
		case 'S':
			*key_Input = STOP_INPUT;
			break;
		case 'Q':
			*key_Input = STATE_QUIT_INPUT;
			break;
		case 'q':
			*key_Input = STATE_QUIT_INPUT;
			break;	
        default:
		    printf("input invalid letter");
		    judgeWordValidInput = INVALID_INPUT;
	} 
}

/*状态迁移函数*/ 
void cdStateMoveFunc()
{
	state currentState =  NO_DISC;
	state nextState = STATE_NULL;
	keyInput key_Input = STATE_QUIT_INPUT; 
	char inputWord = 0;
	
	while(1){
		
		/*轮询输入字符指令*/
		scanf(" %c",&inputWord);
		
		/*将字符转换为枚举输出*/
		convertWordToState(inputWord, &key_Input);
		
		/*判断是否输入的有效字母*/
		if(INVALID_INPUT == judgeWordValidInput)
		{
			judgeWordValidInput = VALID_INPUT;
			printf("\n");
			continue;
		} 
		
		/*输入Q/q退出状态迁移*/
		if(STATE_QUIT_INPUT == key_Input)
		{
			printf("exit CD"); 
			break;
		}
		
		/*执行当前函数*/ 
		cdStateMoveTable[currentState][key_Input].cdFunc();
		
		/*判断当前状态的下一个状态是否为空*/
		if(STATE_NULL == cdStateMoveTable[currentState][key_Input].cdState)
		{
			nextState = currentState;
		} 
		else
		{
			nextState = cdStateMoveTable[currentState][key_Input].cdState;
		}
		
		currentState = nextState;//赋值新状态 
		printf("\n");
	}
} 

int main()
{
	/*状态迁移函数调用*/
    cdStateMoveFunc();	
}