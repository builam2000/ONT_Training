#include <stdio.h>
#include <stdlib.h>

/*Array's implementation of stack*/
/* Time Complexity : O(1) */
typedef struct Stack Stack;
struct Stack
{
    int top;
    unsigned int capacity;
    int* array;
};

Stack *create_Stack(unsigned int capacity);
int Is_Full(Stack *stack);
int Is_Empty(Stack *stack);
void push(Stack *stack, int data);
int pop(Stack *stack);
int top(Stack *stack);
void Print_Stack(Stack *stack);
int sum_digit(int number);

