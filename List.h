#ifndef LIST_H
#define LIST_H
#include "struct.h"

#define INSERT 1
#define DELETE 2
#define QUIT 3

void insertNode(ListNode_t **head, int data);
void deleteNode(ListNode_t **head, int data);
void printList(ListNode_t *head);
void printInformation();
void releaseMemory(ListNode_t **head);
void runFunc(ListNode_t **head);
#endif  
