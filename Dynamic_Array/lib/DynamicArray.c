#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

Dynamic_Array* Create_Dynamic_Array(int size)
{
    Dynamic_Array *arr = (Dynamic_Array *)malloc(sizeof(Dynamic_Array));
    arr->count = 0;
    arr->size = size;
    printf("Count: %d\n",arr->size);
    arr->array = (int *)malloc(size*sizeof(int));
    return arr;
}

void add(Dynamic_Array *arr, int data)
{
    if(arr->count == arr->size)
    {
        growSize(arr);
    }
    arr->array[arr->count] = data;
    printf("Added: %d\n",arr->array[arr->count++]);
   
}

void growSize(Dynamic_Array *arr)
{
    if(arr->count == arr->size)
    {
        arr->size *= 2;
        arr->array = (int *)realloc(arr->array,(arr->size)*sizeof(int));
    }
}

void addAt(Dynamic_Array *arr, int index, int data)
{
    if(arr->count == arr->size)growSize(arr);
    int i;
    for(i=arr->count - 1; i>=index; i--)
    {
        arr->array[i+1] = arr->array[i];
    }
    arr->array[index] = data;
    arr->count = arr->count + 1;
}

void Remove(Dynamic_Array *arr)
{
    if(arr->count > 0)
    {
        arr->array[arr->count - 1] = 0;
        arr->count--;
    }
}

void removeAt(Dynamic_Array *arr, int index)
{
    if(arr->count > 0)
    {
        int i;
        for(i=index;i<arr->count - 1;i++)
        {
            arr->array[i] = arr->array[i+1];
        }
        arr->array[arr->count-1] = 0;
        arr->count--;
    }
}

void Print_Array(Dynamic_Array *arr){
    int i;
    printf("Count: %d\n",arr->count);
    for(i = 0; i<arr->count;i++)
    {
        printf("%d ",arr->array[i]);
    }
    printf("\n");
}

