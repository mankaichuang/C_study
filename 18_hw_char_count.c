/*
*   编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)，
*   换行表示结束符，不算在字符里。不在范围内的不作统计。多个相同的字符只计算一次
*   例如，对于字符串abaca而言，有a、b、c三种不同的字符，因此输出3。
*/

/*
*   哈希表法，简单直观，就是字符串数组要大一些，不然实例测试会通不过
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    int hash[128] = {0};
    char arr[1000];
    int i,len;
    int sum = 0;
    gets(arr);
    len = strlen(arr);
    for(i = 0; i< len; i++){
        if(hash[arr[i]] == 0){
            hash[arr[i]] = 1;
            sum++;
        }
    }
    printf("%d\n",sum);

}