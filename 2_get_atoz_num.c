#include <stdio.h>
#include <string.h>

//方法一:通过返回值形式返回
//这里注意2个问题:
//1.返回的是数组的首地址,所以应该为int型
//2.返回的数组不能为局部变量，如果为局部变量，需要定义为static
static int* get_atoz_num(char *s)
{
    static num[26];
    memset(num,0,26);
    for(; *s != '\0'; s++){
        if(*s >= 'a' && *s <= 'z'){
            num[*s - 'a']++;  //字符-'a'的ASCII码值刚好对应其在数组中的位置
        }
    }
    return num;
}

//方法二:返回到参数中
static void get_atoz_num_2(char *s, char *n)
{
    memset(n,0,26);
    for(; *s != '\0'; s++){
        if(*s >= 'a' && *s <= 'z'){
            n[*s - 'a']++;
        }
    }
    
}
int main(void)
{
    int i;
    char s[50];
    char n[26];
    int *p;
    printf("please input char:\r\n");
    gets(s);
    //方法一
    p = get_atoz_num(s);
    for(i=0;i<26;i++){
        n[i] = *p;
        p++;
    }
    //方法二   
    //get_atoz_num_2(s, n);
    for(i = 0; i < 26; i++){
        printf("%c = %d;\r\n", 'a'+i, n[i]);
    }
}