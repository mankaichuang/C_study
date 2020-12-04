#include <stdio.h>

int main(void)
{
    int i;
    int j = 0;
    char n[5000];
    int len;
    int lastspace;
//    printf("Please input a string:\r\n");
    gets(n); 
    for(i = 0; n[i] != '\0'; i++){
       if(n[i] == ' ') {
           lastspace = i+1;
       }
    }
    for(i = lastspace; n[i] != '\0'; i++){
        j++;
    }
    printf("%d\r\n",j);
}