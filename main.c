#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

extern Node *head;

int main()
{
    head = NULL;
    insert_at_head(4);
    insert_at_head(2);
    insert_at_head(1);
    print(head);
    Insert(3,3);
    print(head);
    Delete(1);
    print(head);
    Insert(0,1);
    print(head);
    Reverse();
    print(head);
    return 0;
}