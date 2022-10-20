#include <stdio.h>
#include <stdlib.h>
#include "lib/Stack.h"

void main()
{
    Stack *stack = create_Stack(2);

    int number_of_elements, number_of_queries;
    //printf("Enter number: ");
    scanf("%d %d",&number_of_elements,&number_of_queries);
    //printf("\nSum: %d \n",sum_digit(12345));

    int A[number_of_elements];
    int i;
    for(i=0;i<number_of_elements;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\n");
    /*
    for(i=0;i<number_of_elements;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    */
    for(i = 0; i< number_of_queries;i++)
    {
        int index;
        scanf("%d",&index);
        index--;
        int j;

        push(stack,A[index]);
        for(j = index;j<number_of_elements;j++)
        {
            if(sum_digit(top(stack)) > sum_digit(A[j]) && top(stack) < A[j])
            {
                printf("%d\n",j+1);
                j=0;
                break;
            }
            
        }
        pop(stack);
        if(j!=0)printf("%d\n",-1);
    
    }
    free(stack);

}