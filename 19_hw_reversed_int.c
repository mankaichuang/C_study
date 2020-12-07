/*  数字颠倒
*   输入一个整数，将这个整数以字符串的形式逆序输出
*   程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
*/

#include <stdio.h>

int main(void)
{
    int num;
    scanf("%d",&num);
    while(num>0){
        printf("%d",num%10);
        num = num/10;
    }
    printf("\n");
}