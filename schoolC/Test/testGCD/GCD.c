#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int a, int b){
    if(b>a) b=(a+b)-(a=b);
    if(b%a==0) return b;
    else return(GCD(b,b%a));
}

int main(void){
    int a,b;
    while (1){
        scanf("%d %d",&a,&b);
        printf("GCD%d\n",GCD(a,b));
    }    
}
