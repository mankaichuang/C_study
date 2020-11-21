/*
*   获取n(n>1)以内的所有质数或者合数
*/
#include <stdio.h>
#include <stdlib.h>

static int get_prime(int n, int *data)
{
    int i,j;
    int k = 0;
    for(i = 2; i < n+1; i++){
        for(j = 2; j < i; j++){
            if(i % j == 0){
                break;
            }
        }
        if((i == j) || (i == 2)){
            data[k] = i;
            k++;
        }
    }
    return k;
}

static int get_composite(int n, int *data)
{
    int i,j;
    int k = 0;
    for(i = 4; i < n+1; i++){
        for(j = 2; j < i; j++){
            if(i % j == 0){
                break;
            }
        }
        if(j < i){
            data[k] = i;
            k++;
        }
    }
    return k;
}

int main(void)
{
    char s[10];
    int n;
    int p_len,c_len,i;
    int prime_data[20];
    int composite_data[20];

    printf("请输入一个数字：\r\n");
    gets(s);
    n = atoi(s);
    p_len = get_prime(n,prime_data);
    c_len = get_composite(n,composite_data);

    printf("%d 以内的质数为:\r\n",n);
    for(i = 0; i < p_len; i++){
        printf("%d ",prime_data[i]);
    }
    printf("\r\n");

    printf("%d 以内的合数为:\r\n",n);
    for(i = 0; i < c_len; i++){
        printf("%d ",composite_data[i]);
    }
    printf("\r\n");

}