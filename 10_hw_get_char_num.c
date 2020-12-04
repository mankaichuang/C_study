/*
*   写出一个程序，接受一个由字母，数字和空格组成的字符串，和一个字母，然后输出输入字符串中该字母出现的次数，不区分大小写
*   考察内容：gets和scanf
*   gets读取一行字符串，遇到换行符结束，并且将换行符从缓冲区读取丢掉
*   scanf：如果读取%c，空格换行都会读取，如果是读取其他如%s %d,会把输入之前的空格换行符读取丢掉，然后获取数据，遇到空格或者换行截至
*   残留的空格或者换行还在缓存区中
*/

#include <stdio.h>

int main(void)
{
    char s[1000];
    char c;
    int len,i,j=0;
    gets(s);
    scanf("%c",&c);
    len = strlen(s);
    if(c < 'A' && c > 'z'){
        printf("%d\r\n", j);
        return 0;
    }else{
        for(i = 0; i < len; i++){
            if(s[i] == c || s[i] == (c+32) || s[i] == (c-32))
                j++;
        }
        printf("%d\r\n", j);
    }
    return 0;
}