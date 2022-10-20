#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

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