#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack *create_Stack(unsigned int capacity)
{
    Stack *new_stack = (Stack* )malloc(sizeof(Stack));
    new_stack->top = -1;
    new_stack->capacity = capacity;
    new_stack->array = (int* )malloc(capacity*sizeof(int));
    return new_stack;
}

int Is_Full(Stack *stack)
{
    if(stack->top == stack->capacity - 1)
    {
        printf("Stack is full !!\n");
        return 1;
    }
    else return 0;
}

int Is_Empty(Stack *stack)
{
    if(stack->top == -1)
    {
        printf("Stack is empty !!\n");
        return 1;
    }
    else return 0;
}

void push(Stack *stack, int data)
{
    if(Is_Full(stack))return;
    (stack->top)++;
    stack->array[stack->top] = data;
}

int pop(Stack *stack)
{
    if(Is_Empty(stack))return -1;
    else return stack->array[stack->top--];
}

int top(Stack *stack)
{
    if(Is_Empty(stack))return -1;
    else return stack->array[stack->top];
}

void Print_Stack(Stack *stack)
{
    int i;
    for(i=0;i<= stack->top;i++)
    {
        printf("%d ",stack->array[i]);
    }
    printf("\n");
}

int sum_digit(int number)
{
    int sum = 0;
    int remainder;
    while(number !=0)
    {
        sum += number%10;
        number = number/10;
    }
    return sum;
}
