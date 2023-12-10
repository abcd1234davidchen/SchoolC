#include<stdio.h>
#include<stdlib.h>
int fib(int n){
    if(n==0 || n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
int main(void){
    int input;
    while(scanf("%d",&input)!=EOF){
        if(input==0){
            break;
        }
        else if(input>100000000){
            printf("Input must less than 100000000\n");
            continue;
        }
        int n=1,arr[100],i=0;
        while (input>fib(n)){
            n++;
        }
        n-=1;
        //printf("%d\n",n);
        while(n>2){
            //printf("INPUT %d %d\n",input,fib(n));
            if(input>=fib(n)){
                arr[i]=input/fib(n);
                input=input%fib(n);
            }
            else{
                arr[i]=0;
            }
            n--;
            i++;
            printf("%d \n",n);
        }
        for(int j=0;j<i;j++){
            printf("%d",arr[j]);
        }
        printf(" (fib)\n");
    }
    printf("Finish!\n");
}