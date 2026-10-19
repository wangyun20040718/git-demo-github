#include <stdio.h>
#include "test.h"
#include "array.h"
#include "struct.h"
#include "function.h"


int main()
{
	/*状态迁移函数调用*/
    //cdStateMoveFunc();

    /*数组打印*/
    //arrayPrint(arrayTow);
    //printf("%drow %dcol = %d\n", 1, 1, *(*(arrayTow + 1) + 1));

    /*结构体打印*/
    //printf("结构体打印：\n");
    printf("%s %d %s\n", people_p[0]->name, people_p[0]->age, people_p[0]->sex);
    //printf("%s %d %s\n", people[1].name, people[1].age, people[1].sex);

    /*冒泡排序*/
    wstMaoPao(arrayOne, sizeof(arrayOne)/sizeof(arrayOne[0]));
    arrayPrintYiWei(arrayOne, sizeof(arrayOne)/sizeof(arrayOne[0]));
    
    /*删除指定数组值*/
    int num =  wstDelVal(arrayOne, 8, 4);
    printf("\n");
    arrayPrintYiWei(arrayOne, num);
}
