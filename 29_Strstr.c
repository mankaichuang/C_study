#include <stdio.h>
#include <string.h>

int Strstr(char *str_s, char *str_d)
{
    int s_len = strlen(str_s);
    int d_len = strlen(str_d);
    int next[d_len];

    if(d_len == 0)
    {
        return 0;
    }

    next[0] = 0;

    for(int i = 1, j = 0; i < d_len; i++)
    {
        while(j > 0 && str_d[i] != str_d[j])
        {
            j = next[j-1];
        }
        if(str_d[i] == str_d[j])
        {
            j++;
        }
        next[i] = j;
    }

    for(int i = 0, j = 0; i < s_len; i++)
    {
        while(j > 0 && str_s[i] != str_d[j])
        {
            j = next[j-1];
        }
        if(str_s[i] == str_d[j])
        {
            j++;
        }
        if(j == d_len)
        {
            return i-d_len+1;
        }
    }
    return -1;    
}

int main(void)
{
    char ret;
    char str_s[255];
    char str_d[100];

    printf("请输入源字符串\r\n");
    gets(str_s);
    printf("请输入要查找的字符串\r\n");
    gets(str_d);

    ret = Strstr(str_s, str_d);
    printf("%d\r\n",ret);
}