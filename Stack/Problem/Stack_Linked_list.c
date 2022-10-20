#include <stdio.h>
#include <stdlib.h>

/*Array's implementation of stack*/
/* Time Complexity : O(1) */
struct Stack_Node
{
    int data;
    struct Stack_Node *next;
};

typedef struct Stack_Node Stack_Node;

Stack_Node *create_StackNode(int data)
{
    Stack_Node *new_node = (Stack_Node* )malloc(sizeof(Stack_Node));
    new_node->data = data;
    new_node->next = NULL;
}

int Is_Empty(Stack_Node* top)
{
    return !top ;
}

void push(Stack_Node **top, int data)
{
    Stack_Node *stack_node = create_StackNode(data);
    stack_node->next= *top;
    *top = stack_node;
    printf("%d is pushed to stack\n", data);
}

int pop(Stack_Node **top)
{
    if(Is_Empty(*top))return -1;
    Stack_Node *temp = *top;
    *top = temp->next;
    int popped_number = temp->data;
    free(temp);
    return popped_number;
}

int top(Stack_Node **top)
{
    if(Is_Empty(*top))return -1;
    return (*top)->data;
}

void Print_Stack(Stack_Node *top)
{
    Stack_Node *temp = top;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node* Reverse(Node *head)
{
    if(head == NULL)return head;
    
}


void main()
{
    Stack_Node *top = NULL;
    push(&top, 1);
    push(&top, 2);
    Print_Stack(top);
    pop(&top);
    if(Is_Empty(top))printf("Stack is empty! \n");
    Print_Stack(top);
    pop(&top);
    if(Is_Empty(top))printf("Stack is empty! \n");

}