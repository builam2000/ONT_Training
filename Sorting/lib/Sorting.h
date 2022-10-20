#include <stdio.h>
#include <stdlib.h> 

void swap(int *a, int *b);

void printArray(int arr[], int size);

/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the
 adjacent elements if they are in the wrong order. This algorithm is not suitable 
 for large data sets as its average and worst-case time complexity is quite high.

 In this algo: the biggest element will come into the last first(bubble), .... etc
 Time complexity: O(N^2)
 Space complexity: O(1)
 */

void BubbleSort(int arr[], int n);
/*
The selection sort algorithm sorts an array by repeatedly finding 
the minimum element (considering ascending order) from the 
unsorted part and putting it at the beginning. 
Time complexity: O(N^2)
Space complexity: O(1)
*/
void SelectionSort(int arr[], int n);

/*
Insertion sort:
Iterate from arr[1] to arr[N] over the array. Compare the current element (key) to its predecessor. 
If the key element is smaller than its predecessor, compare it to the elements before. 
Move the greater elements one position up to make space for the swapped element.
Time complexity: O(N^2)
Space complexity: O(1)

So sanh key voi precedence, neu be hon thi arr[j+1] = arr[j]
*/

void InsertionSort(int arr[], int n);
void Merge(int *A, int *L,int left_number,int *R,int right_number);
void MergeSort(int *A, int n);
int Partition(int *A,int start,int end);

int GetRandom(int min,int max);

void Randomized_Partition(int *A, int start, int end);
void QuickSort(int *A,int start,int end);
void heapify(int arr[], int N, int i);
void HeapSort(int arr[], int N);
