#include <stdio.h>

int main(void)
{
    int num;
    int i, j;
    int temp;
    int prime[1000] = {0};
    int count = 0;
    int flag = 0;
    scanf("%d", &num);
    temp = num;
    for(i=2; i<temp; i++){
        while(temp%i == 0){
            if(count == 0){
                prime[count] = i;
                temp = temp/i;
                count++; 
            }else{
                if(i != prime[count-1]){
                    prime[count] = i;
                    temp = temp/i;
                    count++;
                }else{
                    temp = temp/i;
                }
            }
        }
    }
    if(temp != num && temp != 1){
        prime[count] = temp;
        count++;
    }
    for(i = 0; i<count; i++){
        printf("%d ", prime[i]);
    }

    for(i=0; i<count; i++){
        for(j=1; j<count; j++){
            if(prime[i]*prime[j] == num){
                printf("%d %d\n",prime[i],prime[j]);
                flag = 1;
            }
        }
    }
    if(flag == 0){
        printf("%d %d\n", -1, -1);
    }    
}