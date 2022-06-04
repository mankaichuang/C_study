#include <stdio.h>
#include <string.h>

void Get_next(char str[], int next[], int len);
char *kmp(char str_s[], char str_d[], int next[], int s_len, int d_len, int pos);
//****************************************************************************//
//该函数字符串str[0]不参与计算，也就是提供的str串中，str[0]包含在要查找的子串中
//该函数的缺点是，输入要查找的字符串时，必须初始化str[0]，并且将字符串放置到从str[1]开始的位置
//next的值为前一个索引下的最长子串长度+1；
//例如：str[7] = {' ','a','b','a','b','c','d'}
//计算结果举例如下：
//      index   1   2   3   4   5   6 
//      str     a   b   a   b   c   d 
//      next    0   1   1   2   3   1
//****************************************************************************//
void Get_next(char str[], int next[], int len)
{
    int i = 1;
    int j = 0;
    next[1] = 0;

    while(i < len-1)
    {
        if((j == 0) || (str[i] == str[j]))
        {
            next[++i] = ++j;
        }
        else
        {
            j = next[j];    //回溯
        }
    }
}

//****************************************************************************//
//这个函数比较通用，不用设置str[0]，next的值为对应索引下的最长子串长度；
//例如：str[6] ={'a','b','a','b','c','d'}
//计算结果举例如下：
//      index   0   1   2   3   4   5 
//      str     a   b   a   b   c   d 
//      next    0   0   1   2   0   0
//****************************************************************************//
void Get_next_1(char str[], int next[], int len)
{
    next[0] = 0;
    for(int i = 1, j = 0; i < len; i++)
    {
        while(j > 0 && str[i] != str[j])
        {
            j = next[j-1];     //回溯
        }
        if(str[i] == str[j])
        {
            j++;
        }
        next[i] = j;
    }
}

//****************************************************************************//
//该函数字符串str[0]不参与运算，也就是提供的str串中，str[0]包含在源字符串中
//该函数的缺点是，输入要查找的字符串时，必须初始化str[0]，并且将字符串放置到从str[1]开始的位置
//  str_s[]:源字符串
//  str_d[]：模式串，也就是子串
//  s_len：源字符串长度
//  d_len：子串长度
//  pos：从源字符串的什么位置开始查
//****************************************************************************//
char *kmp(char str_s[], char str_d[], int next[], int s_len, int d_len, int pos)
{
    int i = pos;    //源字符串索引
    int j = 1;      //模式串索引
    
    while((i < s_len) && (j < d_len))
    {
        if((j == 0) || (str_s[i] == str_d[j]))
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j >= d_len)
    {
        return str_s+(i-d_len + 1);
    }
    else
    {
        return NULL;
    }
}

//****************************************************************************//
//这个函数比较通用，不用设置str[0]
//  str_s[]:源字符串
//  str_d[]：模式串，也就是子串
//  s_len：源字符串长度
//  d_len：子串长度
//  pos：从源字符串的什么位置开始查
//****************************************************************************//
char *kmp_1(char str_s[], char str_d[], int next[], int s_len, int d_len, int pos)
{
    int i = pos;    //源字符串索引
    int j = 0;      //模式串索引
    
    for(i = pos, j = 0; i<s_len; i++)
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
            return str_s + i-d_len +1;
        }
    }
    return NULL;
}

int main(void)
{
    int k;
    char *ret;
    char str_s[255];
    char str_d[100];
    int next[255] = {0};
    int s_len = 0;
    int d_len = 0;

    // str_s[0] = '0';
    // str_d[0] = '0';

    printf("请输入源字符串\r\n");
    gets(str_s);
    printf("请输入要查找的字符串\r\n");
    gets(str_d);

    s_len = strlen(str_s);
    d_len = strlen(str_d);

    Get_next_1(str_d,next,d_len);

    for(k = 0; k<d_len; k++)
    {
        printf("%d ",next[k]);
    }
    printf("\r\n");

    ret = kmp_1(str_s,str_d,next,s_len,d_len,0);
    printf("%s\r\n",ret);
    
    return 0;
}