#include "function.h"

void cadge(union income income)
{
   printf("Lam on lam phuoc \n");
   fprintf(fptr,"%s","Lam on lam phuoc\n");
   
}

void stole(union income income)
{
   printf("!!!!! \n");
   fprintf(fptr,"%s\n","!!!!!");
}

void work(union income income)
{
   printf("Income: %d \n",income.income_short);
   fprintf(fptr,"%d \n",income.income_short);

}