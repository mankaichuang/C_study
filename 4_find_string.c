#include <stdio.h>
#include <string.h>

//从指定字符串数组strs中查询是否存在字符串str
//返回str在数组中的索引
//利用字符串比较函数strcmp
//注意事项：为了方便我们遍历字符串数组，在字符串数组的最后一位添加NULL
static int find_string(char *strs[], char *str)
{
    int i = 1;
    while(*strs != NULL){
        if(strcmp(*strs, str) == 0){
            break;
        }
        i++;
        strs++;
    }
    if(*strs == NULL){
        return -1;
    }
    return i;
}

int main(void)
{
    int i;
    char s[15];
    char *place[] = {"beijing","shanghai","xi'an","wuhan","chongqing","guangzhou",NULL};
    printf("请输入地名：\r\n");
    gets(s);
    i = find_string(place, s);
    if(i < 0){
        printf("输入的地名不存在！\r\n");
    }else{
        printf("地名的索引为：%d\r\n", i);
    }
}