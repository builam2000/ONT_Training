#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Array's implementation of stack*/
/* Time Complexity : O(1) */

struct Stack
{
    int top;
    unsigned int capacity;
    char* array;
};

typedef struct Stack Stack;

Stack *create_Stack(unsigned int capacity)
{
    Stack *new_stack = (Stack* )malloc(sizeof(Stack));
    new_stack->top = -1;
    new_stack->capacity = capacity;
    new_stack->array = (char* )malloc(capacity*sizeof(int));
    return new_stack;
}

int Is_Full(Stack *stack)
{
    if(stack->top == stack->capacity - 1)
    {
        printf("\nStack is full !!\n");
        return 1;
    }
    else return 0;
}

int Is_Empty(Stack *stack)
{
    if(stack->top == -1)
    {
        printf("\nStack is empty !!\n");
        return 1;
    }
    else return 0;
}

void push(Stack *stack, char data)
{
    if(Is_Full(stack))return;
    (stack->top)++;
    stack->array[stack->top] = data;
}

char pop(Stack *stack)
{
    if(Is_Empty(stack))return -1;
    else return stack->array[stack->top--];
}

char top(Stack *stack)
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


char *output_string;
int final_pop;
int pop_flag = 0;
void main()
{
    
    char *m = NULL;
   // printf("please input a string\n");
    scanf("%ms",&m);
    int size_of_input_str = strlen(m);

    Stack *stack_for_parent = create_Stack(strlen(m));
    Stack *stack_for_string = create_Stack(strlen(m)+10);
    int i;
    int position_index[strlen(m)],position = 0;
    for(i = 0;i<strlen(m);i++)
    {
        if(m[i] == '/')
        {
            push(stack_for_string,m[i]);
            position_index[position++] = i;
            push(stack_for_parent,m[i]);
            
        }
        else if(m[i] == '\\')
        {
            push(stack_for_string,m[i]);
            pop_flag = 1;
            pop(stack_for_parent);
            int start = position_index[position-1]+1;
            int end = i-1;
            int j;
            position --;
           
            int number_of_pop = end - start + 3;
            output_string = (char *)malloc(number_of_pop);
            
            for(j=0;j<number_of_pop;j++)
            {
                output_string[j] = top(stack_for_string);
                pop(stack_for_string);
            }
            //printf("Has pushed : %d times\n",number_of_pop);
            for(j=0;j<number_of_pop;j++)
            {
                push(stack_for_string,output_string[j]);           
            }           
        }
        else push(stack_for_string,m[i]);
    }
    int k;
    for(k=0;k<size_of_input_str;k++)
    {
        if(output_string[k] == '\\' || output_string[k] == '/');
        else printf("%c",output_string[k]);
    }
    printf("\n");
    free(output_string);

}