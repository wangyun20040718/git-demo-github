#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

#define INSERT 1
#define DELETE 2
#define QUIT 3

void insertNode(ListNode_t **head, int data)
{
    /*创建节点指针指向头节点*/
    ListNode_t *preList = *head;
    ListNode_t *curList = (*head) -> nextPtr;
    ListNode_t *pNewNode = (ListNode_t *)malloc(sizeof(ListNode_t));
    if(NULL == pNewNode )
    {
        printf("内存申请失败\n");
        return;
    }

    pNewNode->pstData = (DataStruct_t *)malloc(sizeof(DataStruct_t));
    if (pNewNode->pstData == NULL)
    {
        free(pNewNode);
        printf("内存申请失败\n");
        return;
    }

    while(curList != NULL && curList -> pstData -> Value < data)
    {
        preList = curList;
        curList = curList -> nextPtr;

    }
    pNewNode -> nextPtr = curList;
    /*pList 的上一个节点的nextPtr等于ppNewNode */
    preList -> nextPtr = pNewNode;
    pNewNode -> pstData -> Value = data;
   
}

void deleteNode(ListNode_t **head, int data)
{
    if(NULL == (*head) -> nextPtr)
    {
        printf("无数据\n");
        return;
    }

    ListNode_t *preList = *head;
    ListNode_t *curList = (*head) -> nextPtr;
    
    while(curList != NULL && curList -> pstData -> Value != data)
    {
        preList = curList;
        curList = curList -> nextPtr;
    }

    if (curList == NULL)
    {
        printf("未找到数值 %d\n", data);
        return;
    }
    
    preList -> nextPtr = curList -> nextPtr;

    free(curList->pstData);  
    free(curList);     
}

void printList(ListNode_t *head)
{
    ListNode_t *curList = head -> nextPtr;
    if (curList == NULL)
    {
        printf("链表暂无数据\n");
        return;
    }

    while(curList != NULL)
    {
        printf("%d ",curList -> pstData -> Value);
        curList = curList -> nextPtr;
    }
    printf("\n");
}

void printInformation()
{
    printf("Please enter your choice:\n");
    printf("1 is to insert an element to the List.\n");
    printf("2 is to delete an element from the List.\n");
    printf("3 is to Quit.\n");
    printf("?\n");
}

void releaseMemory(ListNode_t **head)
{
    ListNode_t *curList = (*head) -> nextPtr;
    ListNode_t *node = NULL;

    while(NULL != curList)
    {
        node = curList;
        curList = curList -> nextPtr;
        free(node -> pstData);
        free(node);
    }
    free(*head);
    *head = NULL;
}

void runFunc(ListNode_t **head)
{
    int inputChoice;
    int inputData;

    inputChoice = 0;
    inputData = 0;

    printInformation();

    while(1)
    {
        scanf(" %d", &inputChoice);
        switch(inputChoice)
        {
            case INSERT:
                printf("Enter a int to insert:");
                scanf(" %d", &inputData);

                insertNode(head, inputData); //没有填写入参数
                printf("?\n");
                break;
            case DELETE:
                printf("Enter a int to be deleted:");
                scanf(" %d", &inputData);

                deleteNode(head, inputData);
                printf("?\n");
                break;
            case QUIT:
                printf("程序退出");
                return;
            default :
                printf("请输入有效数字\n");
                printf("?\n");
         }
    }
}


