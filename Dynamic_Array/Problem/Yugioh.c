#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000010
typedef struct Dynamic_Array
{
    int count;
    int size;
    char *array;
}Dynamic_Array;

void growSize(Dynamic_Array *arr);

Dynamic_Array* Create_Dynamic_Array(int size)
{
    Dynamic_Array *arr = (Dynamic_Array *)malloc(sizeof(Dynamic_Array));
    arr->count = 0;
    arr->size = size;
    //printf("Count: %d\n",arr->size);
    arr->array = (char *)malloc(size*sizeof(char));
    return arr;
}

void add(Dynamic_Array *arr, char data)
{
    if(arr->count == arr->size)
    {
        growSize(arr);
    }
    arr->array[arr->count] = data;
    arr->count++;
}

void growSize(Dynamic_Array *arr)
{
    if(arr->count == arr->size)
    {
        arr->size *= 2;
        arr->array = (char *)realloc(arr->array,(arr->size)*sizeof(char));
    }
}

void Print_Array(Dynamic_Array *arr){
    int i;
    for(i = 0; i<arr->count;i++)
    {
        printf("%c",arr->array[i]);
    }
}

int KMP(char *heystack,char *needle,int length_str,int length)
{

    int occurance = 0;
    int lps[length];
    int h;
    for(h=0;h<length;h++)
    {
        lps[h] = 0;
    }
    if(length==0)return -1;
    int prevLPS = 0, i = 1;
    while(i<length)
    {
        if(needle[i] == needle[prevLPS])
        {
            lps[i] = prevLPS + 1;
            prevLPS += 1;
            i += 1;
        }
        else if(prevLPS == 0)
        {
            lps[i] = 0;
            i++;
        }
        else
        {
            prevLPS = lps[prevLPS - 1];
        }
    }

    i = 0;
    int j = 0;
    while(i<length_str)
    {
        if(heystack[i] == needle[j])
        {
            i = i+1;
            j = j+1;
        }
        else
        {
            if(j==0) i++;
            else j = lps[j-1];
        }
        if(j==length)
        {
            //return i-length;
            occurance++;
        }
    }
    return occurance;
    //return -1;
}

int true_flag = 0;
char str[N];
int max_value = 0;
int prefix_array[100];
int prefix_array_index = 0;

int main()
{
    
    scanf("%s",str);
    
    int i;
    int length = strlen(str);
    int max_length_str = 0;
    for(i=1;i<length;i++)
    {
        
        int j,k;
        int count_str = 0;
        for(j=0;j<i;j++)
        {
            if(str[j]==str[length-i+j])count_str++;
            else {
                count_str = 0;
                break;
            }
        }
        if(count_str >= max_value)
        {
            max_value = count_str;
            prefix_array[prefix_array_index++] = max_value;
        }
    }

    int k;
    for(k=prefix_array_index-1;k>=0;k--)
    {
        Dynamic_Array *arr = Create_Dynamic_Array(1);
        int length_for_substring = prefix_array[k];
        for(i = 0;i<length_for_substring;i++)
        {
            if(str[i]==str[length-length_for_substring+i])
            {
                add(arr,str[i]);
            }
        }
        
        int result = KMP(str+1,arr->array,strlen(str)-1,arr->count);
        if(result > 1 )
        {
            arr->array[arr->count] = '\0';
            printf("%s",arr->array);
            free(arr);
            return 0;
            
        }
        free(arr);  
}
    printf("Just a legend");
    return 0;
    
    
}