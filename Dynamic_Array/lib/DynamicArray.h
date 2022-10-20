#include <stdio.h>
#include <stdlib.h>

typedef struct Dynamic_Array
{
    int count;
    int size;
    int *array;
}Dynamic_Array;

void growSize(Dynamic_Array *arr);
Dynamic_Array* Create_Dynamic_Array(int size);
void add(Dynamic_Array *arr, int data);
void growSize(Dynamic_Array *arr);
void addAt(Dynamic_Array *arr, int index, int data);
void Remove(Dynamic_Array *arr);
void removeAt(Dynamic_Array *arr, int index);
void Print_Array(Dynamic_Array *arr);
