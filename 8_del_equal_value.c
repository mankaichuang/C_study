/*
    题目：将整形数组中数字相同的数字只保留一个，其他的都删除
    已知数组元素已经按从小到大的顺序排列。
    例如[2,2,2,3,3,4,5,5,6,6,7],处理完成之后的数字应该为
    [2,3,4,5,6,7],函数的返回值为新数组的长度
*/

#include <stdio.h>

static int del_equal_value(int a[], int n)
{
    int i,j=0;
    if(n <= 0){         //判断输入的数组长度是否正确
        return 0;
    }else{
        for(i = 1; i<n; i++){
            if(a[j] != a[i]){   //判断数组遍历的当前值和新数组的最后一个值是否相等
                a[j+1] = a[i];  //如果不等，将值赋给新数组，新数组数量+1
                j++;
            }
        }
    }
    return j+1;         //数组的下标为j，所以元素个数为j+1;
}


int main(void)
{
    int a[11] = {2,2,2,3,3,4,5,5,6,6,7};
    int n = 11;
    int i;
    n = del_equal_value(a,n);
    if(n){
        for(i = 0; i<n; i++){
            printf("%d ",a[i]);
        }
        printf("\r\n");
    }else{
        printf("输入的数组长度有误\r\n");
    }


}