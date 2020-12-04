/*  字符串分割
*   连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
*   长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    char temp[9] = {0};
    int len;
    int i;
    int j;
    while(gets(str)){
        len = strlen(str);
        if(len < 8)
        {
            printf("%s",str);
            for(i = 0; i< 8-len; i++){
                printf("%c",'0');
            }
            printf("\n");
        }
        else{
            for(i = 0; i<len/8;i++){
                strncpy(temp,str+8*i,8);
                temp[8] = '\0';
                printf("%s\n",temp);
                memset(temp,0,8);
            }
            if(len%8 != 0){
                j = len - 8*i;
                strncpy(temp,str+8*i,j);
                for(i = 0; i< 8-j;i++){
                    temp[j+i] = '0';
                }
                printf("%s\n",temp);
                memset(temp,0,8);
            }
        }
    }
}