#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int a, int b){
    if(b>a) b=(a+b)-(a=b);
    if(b==0) return a;
    else return(GCD(b,a%b));
}
//Weeee
int main(void){
    int a,b;
    while (scanf("%d %d",&a,&b)!=EOF){
        printf("GCD%d\n",GCD(a,b));
    }    
}
