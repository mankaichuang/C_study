/*  集五福
*   0代表没有福字，1代表有福字，比如11011，代表收集到了4个福字；
*   现在一个团队进行五福收集（<=10人），看看这个团队一共收集到多少五福
*   例如：输入11011，10011 输出0；输入11001，10110，输出1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str[60];
    int data[10];
    char *p;
    int i = 0, len = 0;
    gets(str);
    while(strrchr(str, ',')){
        p = strrchr(str, ',');
        data[i] = atoi(p+1);
        *p = '\0';
        i++;
    }
    data[i] = atoi(str);
    len = i+1;
    for(i=0; i<len; i++){
        printf("%d ",data[i]);
    }

}