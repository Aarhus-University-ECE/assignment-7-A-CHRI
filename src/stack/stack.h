/*
 * Implementation of a stack
 */

#ifndef _STACK
#define _STACK

typedef struct node
{
    int data;
    struct node *next;
} node;

void Initialize(node **top);

void Push(int x, node **top);

int Pop(node **top);

bool Empty(node **top);

void Display(node **top);

#endif