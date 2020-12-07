/*  求int型正整数在内存中存储时1的个数
*   输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。
*/

/*
*   解题思路：利用位移和与此操作来判断某一位是不是1
*/
#include <stdio.h>

int main(void)
{
    int num;
    int count = 0;
    scanf("%d",&num);
    while(num){
        count += num&1;         //&1 将结果和count相加
        num = num >> 1;         //最低位处理之后，将数据右移，处理下一位
    }
    printf("%d\n", count);
}