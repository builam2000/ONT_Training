#include <stdio.h>
#include <stdlib.h>
#include "lib/Sorting.h"
void main()
{
    int arr[] = {64, 25, 12, 22, 11,8,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    //SelectionSort(arr, n);
    //printf("Sorted array selection: \n");
    //printArray(arr, n);
    // BubbleSort(arr,n);
    // printf("Bubble array bubble: \n");
    // MergeSort(arr,n);
    HeapSort(arr,n);
    printf("Heap sorted array: \n");

    printArray(arr,n);


}