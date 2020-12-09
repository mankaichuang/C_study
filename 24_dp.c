#include <stdio.h>

static int max(int a, int b)
{
    return (a>b) ? a : b;
}

int main(void)
{
    int w[5] = {0, 10, 3, 4, 5};   //各个物品的重量
    int v[5] = {0, 3, 4, 6, 7};    //各个物品对应的价值

    int m = 10;                    //背包的最大重量
    int n = 4;                     //放入物品的个数
    
    int i, j;
    int maxvalue[16] = {0};        //存放背包容量为10，数量为4的最大价值

    for(i = 1; i<=n; i++){
        for(j = m; j>=w[i]; j--){
            maxvalue[j] = max(maxvalue[j],maxvalue[j-w[i]]+v[i]);
        }
    }

    for(i = 0; i<=m; i++){
        printf("%d   ",maxvalue[i]);
    }
    printf("\n");
}