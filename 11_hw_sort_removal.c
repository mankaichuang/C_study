/*  明明的随机数
*   明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），
*   对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照
*   排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作(同一个测试用例里可能会有多组数据，希望大家能正确处理)。
*/


#include <stdio.h>

static int fun(int n, int *num)
{
    int i;
    int j;
    int k;
    int temp;
    int *tmp;
    //冒泡排序
    for(j = 0; j< n-1; j++){
        for(i=0; i<n-1-j;i++){
            if(num[i] > num[i+1]){
                temp = num[i];
                num[i] = num[i+1];
                num[i+1] = temp;
            }
        }
    }
    tmp = num;
    k = 1;
    for(i = 0; i< n-1; i++){
        if(tmp[i] != tmp[i+1]){
            num[k] = tmp[i+1];
            k++;
        }
    }
//     for(i = 0; i < k; i++){
//         printf("%d\r\n",num[i]);
//     }
    return k;
}

/*
*    ~是按位取反
*    scanf的返回值是输入值的个数
*    如果没有输入值就是返回-1
*    -1按位取反结果是0
*    while(~scanf("%d", &n))就是当没有输入的时候退出循环
*    和while(scanf("%d",&n)!=EOF)一个意思
*    知识1：只有-1取反（~-1）是0
*    知识2：scanf读入到EOF时返回-1
*/
int main(void)
{
    int i;
    int n;
    int num[1000];
    int len;
    while(~scanf("%d",&n)){         //判断是否有输入
        for(i = 0; i < n; i++){
            scanf("%d",&num[i]);
        }
        len = fun(n,num);
        for(i = 0; i < len; i++){
            printf("%d\r\n",num[i]);
        }
    }
    return 0;
}