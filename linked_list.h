#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    int data;
    struct Node *next;
};



extern Node* create_node(int data);
extern void insert_at_head(int data);
extern void Insert(int data, int position);
extern void Delete(int position);
extern void Reverse();
extern void print(Node *head);
extern void Print_Recursive(Node *p);
extern void Print_Traverse(Node *p);
extern void Reverse_Recursion(Node *p);