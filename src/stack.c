#include "stack.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void Initialize(node **top) {
    /* Set the top pointer to NULL */
    *top = NULL;
}

void Push(int x, node **top)
{
    /* Pre: Non-full stack */

    /* Post: Add element x to the top/front of the list */
    node *new = (node *)malloc(sizeof(node)); // Allocate memory for the node

    new->data = x;
    new->next = *top;

    /* Set the top node as the newly added node */
    *top = new;
}

int Pop(node **top)
{
    /* Pre: Non-empty stack */
    assert(*top != NULL);

    /* Post: Free the top node, and return its value */
    node *t = *top;
    *top = (*top)->next;

    /* Pull the data from the node, then free it*/
    int temp = t->data;
    free(t);

    /* Return the data */
    return temp;
}

bool Empty(node **top)
{
    /* Post: Return TRUE if the top node is NULL*/
    return *top == NULL;
}

void Display(node **top)
{
    /* Pre: Non-empty stack */
    assert(*top != NULL);

    /* Post: Print each element of the stack in order */
    node *t = *top;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main(void)
{
    /* Initialise the stack */
    node *s;
    Initialize(&s);
    // Initialize(s);

    /* TEST A: After initialization the stack must be empty */
    if (Empty(&s))
        printf("The stack is empty after initialization.\n");
    else
        printf("The stack is NOT empty!\n");

    /* Push some elements to the stack */
    Push(1, &s);
    Push(2, &s);

    /* TEST B: After pushing an element to the stack and popping, the stack must be the same */
    Display(&s);
    Push(3, &s);
    Pop(&s);
    Display(&s);

    /* TEST C: After pushing two elements to the stack and popping twice, the two elements should be correctly distributed */
    Push(10, &s);
    Push(20, &s);
    printf("First element popped, should be latest element pushed (20): %d\n", Pop(&s));
    printf("Second element popped, should be second element pushed (10): %d\n", Pop(&s));

    return 0;
}