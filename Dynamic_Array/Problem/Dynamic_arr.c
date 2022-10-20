#include <stdio.h>
#include <stdlib.h>

typedef struct Dynamic_Array
{
    int count;
    int size;
    int *array;
}Dynamic_Array;

void growSize(Dynamic_Array *arr);

Dynamic_Array* Create_Dynamic_Array(int size)
{
    Dynamic_Array *arr = (Dynamic_Array *)malloc(sizeof(Dynamic_Array));
    arr->count = 0;
    arr->size = size;
    //printf("Count: %d\n",arr->size);
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
    arr->count++;
    //printf("Added: %d\n",arr->array[arr->count++]);
   
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
    //printf("Count: %d\n",arr->count);
    for(i = 0; i<arr->count;i++)
    {
        printf("%d ",arr->array[i]);
    }
    printf("\n");
}


int gcd(int a, int b)
{
    if (a == b)
        return a; 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int findGCD(int arr[], int n)
{
  int result = arr[0];
  for (int i = 1; i < n; i++)
  {
    result = gcd(arr[i], result);
 
    if(result == 1)
    {
    return 1;
    }
  }
  return result;
}

int cmpfunc(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
} 


int main()
{
    Dynamic_Array *arr = Create_Dynamic_Array(10);
    int num;
    scanf("%d", &num);
    int i;
     for(i=0;i<num;i++){
        int types_of_query;
        scanf("%d",&types_of_query);
        
        if( 1 == types_of_query )
        {
            int x;
            scanf("%d",&x);
            add(arr,x);
            //printf("Array after add: ");
            //Print_Array(arr);
            
        }
        if( 2 == types_of_query )
        {
            int x,j; //o(n)
            scanf("%d",&x);
            for (j = 0;j<arr->count;j++)
            {
                if(arr->array[j]==x)break;
            }
            removeAt(arr,j);
            //printf("Array after delete: ");
            //Print_Array(arr);
        }

        if ( 3 == types_of_query )
        {
            //printf("Current max postion: %d \n",current_max_positon);
            qsort(arr->array, arr->count, sizeof(int), cmpfunc);
            int x;
            scanf("%d",&x);
            printf("%d\n",arr->array[x-1]);
        }

        if( 4 == types_of_query)
        {
            int i,L,R;
           
            scanf("%d %d",&L,&R);
            Dynamic_Array *gcd_arr = Create_Dynamic_Array(100);
            for(i=0;i<arr->count;i++)
            {
                if(arr->array[i] >=L && arr->array[i] <= R)
                {
                    add(gcd_arr,arr->array[i]);
                }
            }
            int gcd = findGCD(gcd_arr->array,gcd_arr->count);

            //int gcd = 2;
            printf("%d\n",gcd);
            
        }
    }   
    // for(i=0;i<num_of_elements;i++){
    //     printf("%d ",arr[i]);
    // }
    free(arr);
    return 0;
    
}