#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int a, int b){
    if(b>a) b=(a+b)-(a=b);
    if(b==0) return a;
    else return(GCD(b,a%b));
}
//as a test of the GCD function
int main(void){
    int a,b;
    while (1){
        scanf("%d %d",&a,&b);
        printf("GCD%d\n",GCD(a,b));
    }    
}
