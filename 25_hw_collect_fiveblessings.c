/*  集五福
*   0代表没有福字，1代表有福字，比如11011，代表收集到了4个福字；
*   现在一个团队进行五福收集（<=10人），看看这个团队一共收集到多少五福
*   例如：输入11011，10011 输出0；输入11001，10110，输出1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str[60];               //输入的数据
    int data[10];               //将输入的五福数据转换成int型
    int count = 0;              //可以组成五福的个数
    int blessings[5] = {0};     //各个福字的总数
    char *p;                    //字符串分割指针
    int i = 0, len = 0, j = 0;
    int flag = 1;               
    gets(str);                  //获取收入数据
    while(strrchr(str, ',')){   //通过','进行字符串分割
        p = strrchr(str, ',');  
        data[i] = atoi(p+1);    //字符串转int
        *p = '\0';
        i++;
    }
    data[i] = atoi(str);        
    len = i+1;
    // for(i=0; i<len; i++){
    //     printf("%d ",data[i]);
    // }
    for(i = 0; i<len; i++){
        for(j = 0; j<5; j++){
            blessings[j] += data[i]%10; //统计各个福字的数量
            data[i] = data[i]/10;
        } 
    }
    // for(i=0; i<5; i++){
    //     printf("%d ",blessings[i]);
    // }
    while(flag){
        if(blessings[0]>0 && blessings[1]>0 && blessings[2]>0 && blessings[3]>0 && blessings[4]>0){
            count++;
            blessings[0] -= 1;
            blessings[1] -= 1;
            blessings[2] -= 1;
            blessings[3] -= 1;
            blessings[4] -= 1;
        }else{
            flag = 0;
        }
    }
    printf("%d\n", count);
}