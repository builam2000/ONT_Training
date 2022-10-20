#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KMP(char *heystack,char *needle)
{
    int *lps = (int *)calloc(strlen(needle),sizeof(int));
    if(strlen(needle)==0)return -1;
    int prevLPS = 0, i = 1;
    while(i<strlen(needle))
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
    while(i<strlen(heystack))
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
        if(j==strlen(needle))
        {
            return i-strlen(needle);
        }
    }
    return -1;
}

int KMP_Appear(char *heystack,char *needle)
{
    int occurance = 0;
    int *lps = (int *)calloc(strlen(needle),sizeof(int));
    if(strlen(needle)==0)return 0;
    int prevLPS = 0, i = 1;
    while(i<strlen(needle))
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
    while(i<strlen(heystack))
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
        if(j==strlen(needle))
        {
            //return i-strlen(needle);
            occurance++;
        }
    }
    return occurance;
}


void main(){
    char *P = NULL;
   // printf("please input a string\n");
    scanf("%ms",&P);
    char *T = NULL;
   // printf("please input a string\n");
    scanf("%ms",&T);
    printf("%d\n",KMP_Appear(T,P));
}