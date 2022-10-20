#include "lib/DynamicArray.h"

void main()
{
    Dynamic_Array *arr = Create_Dynamic_Array(3);
    printf("Count: %d\n",arr->size);
    add(arr,1);
    add(arr,2);
    add(arr,3);
    addAt(arr,1,10);
    printf("Size after resize: %d\n",arr->size);
    Print_Array(arr);
    
}