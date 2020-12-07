/*
*   给定n个字符串，请对n个字符串按照字典序排列。
*/

/*
*   运用strcmp进行排序
*   注意这里字符串的长度要设的足够大，设置成100的话，实例测试会提示堆栈溢出，数组越界
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    int i,j;
    scanf("%d",&n);
    char str[n][1000];
    char temp[1000];
    for(i=0; i<n; i++){
        scanf("%s",str[i]);
    }

    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if(strcmp(str[j],str[j+1])>0){
                strcpy(temp, str[j]);
                strcpy(str[j], str[j+1]);
                strcpy(str[j+1], temp);
            }
        }
    }

    for(i=0; i<n; i++){
        printf("%s\n",str[i]);
    }
}