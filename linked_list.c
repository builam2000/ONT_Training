#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node *head = NULL;

Node* create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(int data)
{
    Node *new_node = create_node(data);
    if(head==NULL)head = new_node;
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void Insert(int data, int position){
    Node *temp1 = create_node(data);
    if(position == 1){
        temp1->next = head;
        head = temp1;
        return;
    }
    Node *temp2 = head;
    int i;
    for(i = 0; i< position-2;i++)
    {
        temp2 = temp2->next; //point to n-1 position
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void Delete(int position)
{
    Node *temp = head;
    int i;
    if(head == NULL)
    {
        printf("Cannot delete because there is no node ! \n");
        return ;
    }
    else if(position == 1)
    {
        head = temp->next;
        free(temp);
    }
    else{

    for(i = 0; i<position-2;i++){
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    }
}

void Reverse()
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current-> next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


void print(Node *head){
    Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Print_Recursive(Node *p)
{
    if(p == NULL)return;
    printf("%d ",p->data);
    Print_Recursive(p->next);
}

void Print_Traverse(Node *p)
{
    if(p==NULL)return;
    Print_Recursive(p->next);
    printf("%d ",p->data);
}

void Reverse_Recursion(Node *p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse_Recursion(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

