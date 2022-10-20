#include <stdio.h>
#include <stdlib.h>
#include <math.h>
    
#define MAX_SIZE 1998
int result = 0;   //Flag for final result
    
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
   

int main()
{
    int test_case;
    scanf("%d",&test_case);
    while(test_case--)
    {
        int sum_people = 0;
        int number_of_house;
        int i;
        int arr[MAX_SIZE] = {0};
        //printf("Enter number of house");
        scanf("%d",&number_of_house);
        
        
        int A[number_of_house][2];
        int start = 0;
    
    /*Nhap n gia dinh*/
        for(i=0;i<number_of_house;i++)
        {
            int x,y,h;
            //printf("Enter house data: ");
            scanf("%d %d %d",&x,&y,&h);
            /*Change from x=y to x=...,y=0*/
            int x1 = x-y;
            int y1 = x+y;
            x = x1;
            y = y1;
            if(start<number_of_house)
            {
                A[start][0] = x;
                A[start][1] = h;
                start ++;
                sum_people += h;
            }
            
        }
        /*Bubble sort input array*/
        int j;
        for(i=0;i<number_of_house-1;i++)
        {
            for(j=0;j<number_of_house-i-1;j++)
            {
                if(A[j][0] > A[j+1][0])
                {
                    swap(&A[j][0],&A[j+1][0]);
                    swap(&A[j][1],&A[j+1][1]);
                }
            }
        }

        /*If house has same x, plus num people in these house*/
        for(i=0;i<number_of_house-1;i++)
        {
            if(A[i][0]==A[i+1][0])
            {
                A[i+1][1] += A[i][1]; 
                A[i][1] = 0;
            }
            
        }

        /*Print sorted array*/
        // for(i=0;i<number_of_house;i++)
        // {
        //     printf("[%d,%d],",A[i][0],A[i][1]);
        // }
        // printf("\n");
        // printf("Sum people: %d\n",sum_people);

        /*Compare total left and total right to find YES or NO*/
        for(i=0;i<=number_of_house;i++)
        {
            int total_left = 0;
            int k ;
            for(k=0;k<=i;k++)
            {
                total_left += A[k][1];
            }
            int total_left_2 = total_left - A[i][1];
            int total_right = sum_people - total_left_2 - A[i][1];
            //printf("Total right: %d\n",total_right);
            if(total_left == (int)sum_people/2 || total_left_2 == total_right || total_left_2 == sum_people/2 )
            {
                result = 1;
                printf("YES\n");
                break;
            }
    
        }
        if(result==0)printf("NO\n");
        result = 0;
      
    }
    
}