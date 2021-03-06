/*
*   王强今天很开心，公司发给N元的年终奖。王强决定把年终奖用于购物，他把想买的物品分为两类：
*   主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：
*   主件	附件
*   电脑	打印机，扫描仪
*   书柜	图书
*   书桌	台灯，文具
*   工作椅	无
*   如果要买归类为附件的物品，必须先买该附件所属的主件。每个主件可以有 0 个、 1 个或 2 个附件
*   附件不再有从属于自己的附件。王强想买的东西很多，为了不超出预算，他把每件物品规定了一个重要度，分为 5 等：
*   用整数 1 ~ 5 表示，第 5 等最重要。他还从因特网上查到了每件物品的价格（都是 10 元的整数倍）。
*   他希望在不超过 N 元（可以等于 N 元）的前提下，使每件物品的价格与重要度的乘积的总和最大。
*   设第 j 件物品的价格为 v[j] ，重要度为 w[j] ，共选中了 k 件物品，编号依次为 j 1 ， j 2 ，……， j k ，则所求的总和为：
*   v[j 1 ]*w[j 1 ]+v[j 2 ]*w[j 2 ]+ … +v[j k ]*w[j k ] 。（其中 * 为乘号）
*   请你帮助王强设计一个满足要求的购物单。
*/

/*
*   输入的第 1 行，为两个正整数，用一个空格隔开：N m
*   （其中 N （ <32000 ）表示总钱数， m （ <60 ）为希望购买物品的个数。）
*   从第 2 行到第 m+1 行，第 j 行给出了编号为 j-1 的物品的基本数据，每行有 3 个非负整数 v p q
*   （其中 v 表示该物品的价格（ v<10000 ）， p 表示该物品的重要度（ 1 ~ 5 ）， q 表示该物品是主件还是附件。
*   如果 q=0 ，表示该物品为主件，如果 q>0 ，表示该物品为附件， q 是所属主件的编号）
*/

#include <stdio.h>

static int max(int a, int b)
{
    return (a>b) ? a : b;
}

int main(void)
{
    int value[60][3] = {0};  //三种情况的价值存放，value[m][0]主件价值；value[q][1],第一件附件，value[q][2]，第二件附件
    int price[60][3] = {0};  //三种情况的价格存放，price[m][0]主件价格；price[q][1],第一件附件，price[q][2]，第二件附件

    int maxvalue[3200] = {0}; //每个价格存放的最大价值
    int N,m;                    //N为总价格限定，m为希望购买的数量

    scanf("%d %d", &N, &m);
    int p = 0, q = 0, v = 0;
    int i = 0, j = 0;

    int temp_price = 0;

    for(i = 1; i<= m; i++){
        scanf("%d %d %d", &v, &p, &q);
        if(q == 0){       //是主件
            price[i][0] = v;
            value[i][0] = v*p;
        }else{          //是附件
            if(price[q][1] == 0){       //如果第一个附件位置为空
                price[q][1] = v;
                value[q][1] = v*p;
            }else{                      //已经有了一个附件，放到第二个附件位
                price[q][2] = v;
                value[q][2] = v*p;
            }
        }
    }

    for(i = 1; i<=m; i++){
        for(j = N/10; j>=price[i][0]/10; j--){
            maxvalue[j] = max(maxvalue[j], maxvalue[j-price[i][0]/10]+value[i][0]); //只有主件
            if(price[i][1] != 0){                                                   //只有一件附件
                temp_price = price[i][0]/10 + price[i][1]/10;
                if(j>=temp_price){
                    maxvalue[j] = max(maxvalue[j], maxvalue[j - temp_price]+value[i][0]+value[i][1]); 
                }
            }
            if(price[i][2] != 0){                                                   //有两件附件
                temp_price = price[i][0]/10 + price[i][1]/10 + price[i][2]/10;
                if(j>=temp_price){
                    maxvalue[j] = max(maxvalue[j], maxvalue[j - temp_price] + value[i][0] + value[i][1] + value[i][2]);
                } 
            }
        }
    }

    printf("%d\n", maxvalue[N/10]);
}