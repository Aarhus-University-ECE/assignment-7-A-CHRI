#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

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

