#include <stdio.h>
#include "test.h"
#include "array.h"
#include "struct.h"
#include "function.h"

/*冒泡排序*/
void wstMaoPao(int *arry, int size)
{
    int num;
    for(int i = 1; i<size; i++)
    {
        for(int j = 0; j<(size - i); j++)
        {
            if(arry[j]>arry[j+1])
            {
                num = arry[j + 1];
                arry[j + 1] = arry[j];
                arry[j] = num;
            }
        }
    }
}

/*删除指定数组值*/
int wstDelVal(int *arry, int size, int val)
{
    int j;
    j = 0;
    for(int i = 0; i<size; i++)
    {
        if(arry[i] != val)
        {
            *(arry + j) = arry[i];
            j++;
        }
    }
    return j;
}

/*打印链表*/
void wstListPrint(List *head)
{
    List *Node_print = NULL;

    Node_print = head;

    for(int i = 0; Node_print != NULL; i++)
    {
        printf("%d", Node_print->num);
        Node_print = Node_print->next_Node;
    }
}
