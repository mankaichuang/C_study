#include <stdio.h>
#include <string.h>

//从指定字符串数组strs中查询是否存在字符串str
//返回str在数组中的索引
//利用字符串比较函数strcmp
//注意事项：如何遍历字符串数组，使用通用方法获取字符串数组长度
// len = sizeof(strs) / sizeof(strs[0])
//这里还有个考点，就是sizeof指针和sizeof数组名是有区别的，这个一定要注意
//必须在主函数中计算字符串数组的长度，因为数组名传递参数的时候，实际是作为指针进行传递的

//定义获取字符串数组长度的宏
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}

static int find_string(char *strs[], char *str, int len)
{
    int i = 1;
    while(i < len + 1){
        if(strcmp(*strs, str) == 0){
            break;
        }
        i++;
        strs++;
    }
    if(i == len + 1){
        return -1;
    }
    return i;
}

int main(void)
{
    int i,len;
    char s[15];
    char *place[] = {"beijing","shanghai","xi'an","wuhan","chongqing","guangzhou"};
    GET_ARRAY_LEN(place,len);
    printf("请输入地名：\r\n");
    gets(s);
    i = find_string(place, s, len);
    if(i < 0){
        printf("输入的地名不存在！\r\n");
    }else{
        printf("地名的索引为：%d\r\n", i);
    }
}