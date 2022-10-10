#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 3

FILE *fptr;
union income
{
    char income_str[16];
    short int income_short;
};

typedef struct 
{
    /* data */
    char type[9]; //congnhan
    union income income;
    void (*action)(union income income);  
}someone_t;

someone_t nguoi[MAX_PEOPLE];

void cadge(union income income);
void stole(union income income);
void work(union income income);
