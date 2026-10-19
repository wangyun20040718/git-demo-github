#include <stdio.h>
#include <string.h>
#include "pointer.h"
#include "test.h"
#include "array.h"
#include "struct.h"
#include "function.h"

/*最简单的指针加法操作*/
int add(int* wsbnum1_p, int* wsbnum2_p)
{
    int add;

    add = 0;
    add = *wsbnum1_p + *wsbnum2_p;
    
    return add;
}

void arrayPrintTowWei(int (*array)[4])
{
    printf("%drow %dcol = %d\n", 1, 1, *(*(array + 1) + 1));
    *(*(array + 1) + 1) = 20;
}

void arrayPrintYiWei(int *array, int num)
{
    for(int i = 0; i<num; i++)
    {
        printf("%d ", array[i]);
    }
}