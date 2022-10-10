/*
"3. Thực hành code C basic (áp dụng các coding convention):
    Viết chương trình C thực hiện việc sau:
    Có 3 kiểu người: ăn xin, ăn trộm và công nhân. 
    Định nghĩa một kiểu someone_t là một struct đại diện cho 1 người gồm các trường sau:
    - type: là một chuỗi kí tự lưu kiểu người: ""anxin"", ""antrom"", ""congnhan""
    - income: là một trường lưu thông tin thu nhập của người đó. Nếu type:
        + anxin: thì income là chuỗi kí tự có giá trị ""tuytam""
        + antrom: thì income là chuỗi kí tự có giá trị ""henxui""
        + congnhan: thì income là số nguyên 2 bytes có giá trị là 500000
    - action: là một con trỏ hàm (với biến đầu vào có kiểu someone_t) trỏ tới công việc của mỗi người.  Nếu type:
        + anxin: thực hiện hàm cadge(): in ra chuỗi ""lam on lam phuoc""
        + antrom: thực hiện hàm stole(): in ra chuỗi ""!!!""
        + congnhan: thực hiện hàm work(): in ra income của người này
    Hàm main() thực hiện việc sau:
    - Tạo ngẫu nhiên N người thuộc có kiểu someone_t và lưu vào mảng có kích thước MAX_PEOPLE(cần được define). 
    - Duyệt mảng trên và thực hiện hàm action của mỗi người, các chuỗi đầu ra được in lần lượt vào file ""output.txt"""
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"


extern FILE *fptr;
extern someone_t nguoi[MAX_PEOPLE];


int main()
{   int N;
    printf("So nguoi can nhap: ");
    scanf("%d",&N);
    int i = 0;
    printf("\nNhap mot trong 3 loai nguoi: 1.anxin 2.antrom 3.congnhan \n");
    fptr = fopen("output.txt","a");
 
    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
    for(i=0;i<N;i++)
    {
        printf("Nguoi so %d: ",i+1);
        scanf("%s",nguoi[i].type);
        if(!strcmp(nguoi[i].type,"anxin"))
        {
            strcpy(nguoi[i].income.income_str,"tuytam");
            nguoi[i].action = cadge;
            (*nguoi[i].action)(nguoi[i].income);
        }
        else if(!strcmp(nguoi[i].type,"antrom"))
        {
            strcpy(nguoi[i].income.income_str,"henxui");
            nguoi[i].action = stole;
            (*nguoi[i].action)(nguoi[i].income);
        }
        else
        {
            nguoi[i].income.income_short = 5000;
            nguoi[i].action = work;
            (*nguoi[i].action)(nguoi[i].income);
        }

    }
    fclose(fptr);
    return 0;
}