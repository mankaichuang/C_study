/*  近似取值
*   接受一个正浮点数，输出该数值的近似整数。如果小数点后数值大于等于5，
*   向上取整，小于5则向下取整。
*/

#include <stdio.h>

int main(void)
{
    float in;
    int temp;
    while(~scanf("%f",&in)){
        temp = (int)in;
        if((in - temp) >= 0.5){
            temp += 1;
        }
        printf("%d\n",temp);
    }
}