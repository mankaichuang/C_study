/*
*   sizeof使用过程中的两个重要点：
*   1、sizeof(struct s)
*       要点是对齐的问题，以及要深入理解#pragma pack(n);
*       默认的#pragma pack(n),n = 8;
*       当结构体的成员变量的长度>n时，使用n进行字节对齐
*       当结构的成员变量的长度<n时，使用自身默认的字节对齐
*       例如：
*       n = 4；结构体中有3个成员
        struct test{
            char a; 
            double b; 
            int c;
        };
*       sizeof(test) = 1 + 3 + 8 + 4 = 16
*       假设起始地址为0x0000,a的长度为1，1<n,使用自身字节长度对齐
*       那么存储a之后，地址偏移为0x0001，
*       下来进行b的存储，因为b的长度为8，8>n,使用n进行字节对齐，所以要补齐3个地址，
*       那么b就存储在0x0004-0x000b，再接下来，c的长度为4，使用4进行地址对齐，0x000c是
*       4的倍数，所以不用补齐地址，因此c存放在0x000c-0x000f，结构体总共占用了16个地址长度
*       16是n的倍数，所以结构体不要补齐地址，因此sizeof(test) = 16
*       当我们设置n = 8时
*       struct test{
*           char a; 
*           double b;
*           int c;
*       };
*       sizeof(test) = 1 + 7 + 8 + 4 +4 = 24
*       假设起始地址为0x0000,a的长度为1，1<n,使用自身字节长度1对齐
*       那么存储a之后，地址偏移为0x0001，
*       下来进行b的存储，因为b的长度为8，8=n,使用n进行字节对齐，所以要补齐7个地址，
*       那么b就存储在0x0008-0x000f，再接下来，c的长度为4，4<n,使用4进行地址对齐，0x0010是
*       4的倍数，所以不用补齐地址，因此c存放在0x0010-0x0014，结构体总共占用了20个地址长度
*       20不是n的倍数，所以结构体需要补齐4个地址，因此sizeof(test) = 24
*       
*   2、数组传参之后sizeof的问题
*       我们知道，通用的计算数组长度的方法为sizeof(array) / sizeof(array[0]) 
*       然而数组传参之后，实际上传递的数组的首地址，所以sizeof(array) = 4
*       因此，数组传参之后，我们就不能通过sizeof(array) / sizeof(array[0])来计算数组长度了
*       一般通用做法是提前计算出数组长度，然后通过参数将长度传递进去。
*/

#include <stdio.h>

//结构体的sizeof测试程序
//sizeof(struct test)

// #pragma pack(8)
// // #pragma pack(4)

// struct test{
//         char a;
//         double b;
//         int c;
// };
// int main(void)
// {
//     struct test t;
//     printf("len = %d\r\n",sizeof(t));
//     return 0;
// }

//数组传参测试程序
static void fun(char *p)
{
    printf("传参之后的sizeof：%d\r\n", sizeof(p));
}

int main(void)
{
    char p[] = "hello,world!";
    printf("传参之前的sizeof：%d\r\n", sizeof(p));
    fun(p);  
}