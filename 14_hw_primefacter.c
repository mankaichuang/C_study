/*  质数因子
*   功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）
*   （如180的质因子为2 2 3 3 5 ）最后一个数后面也要有空格
*/

#include <stdio.h>

//这里注意，我们对i进行处理，因为如果大于数的1/2，就是数字本身了，其实不做处理也可以
//但是，华为测试会超时，所以加了处理
int main(void)
{
    int i;
    long num;
    scanf("%d",&num);
    for(i=2; i<num/2; i++){//质因子大于一个数的1/2，就是数字自身
        while(num != i){
            if(num%i == 0){
                printf("%d ",i);
                num = num / i;
            }else{
                break;
            }
        }
    }
    printf("%d ",num);
    printf("\n");     
}