#include <stdio.h>
#include <stdlib.h>

/*Array's implementation of stack*/
/* Time Complexity : O(1) */
typedef struct Stack Stack;
struct Stack
{
    int top; //Currenty top of stack(Like SP pointer)
    unsigned int capacity;
    int* array;
};
/*Create a stack*/
Stack *create_Stack(unsigned int capacity);

/*Check for Stack is full or not*/
int Is_Full(Stack *stack);

/*Check for Stack is empty or not*/
int Is_Empty(Stack *stack);

/*Push an element onto Stack*/
void push(Stack *stack, int data);

/*Pop an element off the Stack*/
int pop(Stack *stack);

/*Get top value of stack*/
int top(Stack *stack);
void Print_Stack(Stack *stack);
int sum_digit(int number);

