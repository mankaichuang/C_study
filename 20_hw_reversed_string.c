/*  字符串反转
*   接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）
*/

#include <stdio.h>

int main(void)
{
    char arr[1000];
    int i,len;
    gets(arr);
    len = strlen(arr);
    for(i = 0; i<len; i++){
        printf("%c",arr[len-1-i]);
    }
    printf("\n");
}