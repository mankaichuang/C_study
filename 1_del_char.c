#include <stdio.h>

#define     DEL_CHAR    '*' 

static void del_char(char *data)
{   
    int i = 0;
    char *p = data;
    while(*p && *p == DEL_CHAR){    //遍历字符串，当*p!='\0'或者*p='*'时，停止遍历
                                    //目的是将字符串最前面的**全部保留下来
        data[i] = *p;               //将字符串最前面的*保留
        i++;
        p++;
    }
    while(*p){                  //从第一个不是*的字符串开始遍历，当*p!='\0'时，停止遍历
        if(*p != DEL_CHAR){          
            data[i] = *p;       //将不是*的数据保留
            i++;                
        }
        p++;                    //这里注意，不管是不是*，p的地址都要增加，以完成遍历
    }
    data[i] = '\0';             //在字符串末尾加入'\0'
}
void main(void)
{
    char s[100];
    printf("请输入一串字符串：\r\n");
    gets(s);
    del_char(s);
    printf("整理后的字符串为：%s\r\n",s);
}