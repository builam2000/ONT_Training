#include <stdio.h>
#include <stdlib.h> 
#include "Sorting.h"
void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the
 adjacent elements if they are in the wrong order. This algorithm is not suitable 
 for large data sets as its average and worst-case time complexity is quite high.

 In this algo: the biggest element will come into the last first(bubble), .... etc
 Time complexity: O(N^2)
 Space complexity: O(1)
 */

void BubbleSort(int arr[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])swap(arr+j,arr+j+1);
        }
    }
}

/*
The selection sort algorithm sorts an array by repeatedly finding 
the minimum element (considering ascending order) from the 
unsorted part and putting it at the beginning. 
Time complexity: O(N^2)
Space complexity: O(1)
*/

void SelectionSort(int arr[], int n)
{
    int i,j,min_idx;
    for(i=0;i<n-1;i++)
    {
        min_idx = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min_idx]){
                min_idx = j;
                
            }
           
        }
         swap(&arr[min_idx],&arr[i]);
    }
}

/*
Insertion sort:
Iterate from arr[1] to arr[N] over the array. Compare the current element (key) to its predecessor. 
If the key element is smaller than its predecessor, compare it to the elements before. 
Move the greater elements one position up to make space for the swapped element.
Time complexity: O(N^2)
Space complexity: O(1)

So sanh key voi precedence, neu be hon thi arr[j+1] = arr[j]
*/

void InsertionSort(int arr[], int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && key<arr[j])
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

/*
Merge sort

*/

void Merge(int *A, int *L,int left_number,int *R,int right_number)
{
    int i,j,k;
    i=0;j=0;k=0;
    while(i<left_number && j<right_number)
    {
        if(L[i] <= R[j])A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i<left_number)A[k++] = L[i++];
    while(j<right_number)A[k++] = R[j++];
}

void MergeSort(int *A, int n)
{
    int mid,i,*L,*R;
    if(n<2)return;
    mid = n/2;

    L = (int *)malloc(mid*sizeof(int));
    R = (int *)malloc((n-mid)*sizeof(int));

    for(i=0;i<mid;i++)
    {
        L[i] = A[i];
    }
    for(i=mid;i<n;i++)
    {
        R[i-mid] = A[i];
    }

    MergeSort(L,mid);
    MergeSort(R,n-mid);
    Merge(A,L,mid,R,n-mid);
    free(L);
    free(R);
}

/*QuickSort
Time complexity : O(nlog(n))
Space complexity : O(logn)
*/
int Partition(int *A,int start,int end)
{
    int pivot = A[end];
    int pIndex = start;
    int i;
    for(i=start;i<end;i++)
    {
        if(A[i] <= pivot)
        {
            swap(&A[i],&A[pIndex++]);
        }
    }
    swap(&A[pIndex],&A[end]);
    return pIndex;
}

int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

void Randomized_Partition(int *A, int start, int end)
{
    int Pivot_Index = GetRandom(start,end);
    swap(&A[Pivot_Index],&A[end]);
    Partition(A,start,end);
}

void QuickSort(int *A,int start,int end)
{
    if(start >= end)return;
    int pIndex = Partition(A,start,end);
    QuickSort(A,start,pIndex-1);
    QuickSort(A,pIndex+1,end);
}

/*HeapSort*/

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < N && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < N && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,N,largest);
    }
}

void HeapSort(int arr[], int N)
{
    int i;
    //Create max-heap
    for(i = N/2 - 1;i>=0;i--)
    {
        heapify(arr,N,i);
    }
    for(i=N-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

