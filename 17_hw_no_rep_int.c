/*  提取不重复的整数
*   输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
*   保证输入的整数最后一位不是0。
*/

/*
*   解题思路，一个整数，最多出现的数字就是0-9，10个数字，
*   所以我们使用哈希表法，将第一次出现的数字保存；
*   通过%10获取最右边得数字，通过/10获取去掉最后一位的整数
*/
#include <stdio.h>

int main(void)
{
    int data;
    int hash[10] = {0};
    scanf("%d", &data);
    while(data > 0){
        if(hash[data%10] == 0){
            hash[data%10] = 1;
            printf("%d",data%10);
        }
        data = data/10;
    }
    printf("\n");
}