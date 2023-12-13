#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fib(int n){
    if (n==0|n==1)
        return n;
    else
        return fib(n-1)+fib(n-2);
}

int main(void){
    int i=0;
    for(i=0;i<20;i++){
        printf("%d %d\n",i,fib(i));
    }
}