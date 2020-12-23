#include <stdio.h>
#include <string.h>

int main(void)
{
    char *p;
    int len = 0, i,j;
    char data[1000];
    char hash[501];
    char temp;
    gets(data);
    len = strlen(data);
    len = len/2 +1;
    p = data;
    for(i = 0; i<len; i++){
        data[i] = *p;
        p = p + 2;
    }
    for(i = 0; i<len; i++){
        hash[i] = data[i];
    }
    for(i = 0; i<len-1; i++){
        for(j = 0; j<len-1-i; j++){
            if(data[j]<data[j+1]){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    for(i = 0; i<len; i++){
        for(j=0; j<len; j++){
            if(hash[i] == data[j]){
                if(i == len-1){
                    printf("%d\n",j);
                    break;
                }else{
                    printf("%d,",j);
                    data[j] = '0';
                    break;
                }
            }
        }
    }
    
}