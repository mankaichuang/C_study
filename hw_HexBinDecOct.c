#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int N;
    char num1[100];
    char num2[100];
    int data1=0,data2=0,data=0;
    int i;
    int len1,len2;
    scanf("%d%s%s",&N,num1,num2);
    len1 = strlen(num1);
    len2 = strlen(num2);
    
    if((len1>1 && num1[0] == '0')||(len2>1 && num2[0] == '0')){
        printf("%d\n",-1);
    }
    data1 = atoi(num1);
    data2 = atoi(num2);

    data = data1-data2;
    if(data >=0){
        printf("%d ", 0);
    }else{
        printf("%d ", 1);
    }
    while(data/N){
        printf("%d",data/N);
        data = data%N;
    }
    printf("%d\n",data);

    return 0;
}