#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Sort the substring*/
void swap(char *a, char *b)
{
   char temp = *a;
   *a = *b;
   *b = temp;
}

int Partition(char *A,int start,int end)
{
    char pivot = A[end];
    int pIndex = start;
    int i;
    for(i=start;i<end;i++)
    {
        if(A[i] >= pivot)
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

void Randomized_Partition(char *A, int start, int end)
{
    int Pivot_Index = GetRandom(start,end);
    swap(&A[Pivot_Index],&A[end]);
    Partition(A,start,end);
}

void QuickSort(char *A,int start,int end)
{
    if(start >= end)return;
    int pIndex = Partition(A,start,end);
    QuickSort(A,start,pIndex-1);
    QuickSort(A,pIndex+1,end);
}

void main()
{
    int number;
    scanf("%d",&number);
    int i;
    for(i=0;i<number;i++)
    {
    char *str = NULL;
 
    scanf("%ms",&str);
    int size_of_input_str = strlen(str);
    int start,end;
    scanf("%d %d",&start,&end);
    int length_to_reverse = end-start+1;
    int position_to_reverse = start;
    int str_len = 0;
    int i;
    QuickSort(str,start,end);
    printf("%s\n",str);
 }
}