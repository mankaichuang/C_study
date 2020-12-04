/*  进制转换
*   写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。
*/
#include <stdio.h>

int main(void)
{
    long d;
    while(~scanf("%x",&d)){
        printf("%d\n",d);
    }
}