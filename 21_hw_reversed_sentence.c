/*  句子逆序
*   将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
*   所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
*/

/*
*   考查strchr和strrchr的运用，查询字符串中字符出现的位置，返回char *，如果没有，返回NULL
*   两个区别是一个正向，即从左到右查询，另一个是从右到左查询
*/

#include <stdio.h>

int main(void)
{
    char str[1000];
    char *p;
    gets(str);
    while(p = strrchr(str,' ')){    //查找空格的位置
        printf("%s ",p+1);          //输出空格后的字符串
        *p = '\0';                  //将空格设置为'\0'，截取字符串
    }
    printf("%s",str);               //输出第一个字符串
    printf("\n");
}