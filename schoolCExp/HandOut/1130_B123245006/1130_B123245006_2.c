#include<stdio.h>
#include<stdlib.h>
long long level(int a){
    long long count=1;
    for(int i=1;i<=a;i++){
        count*=i;
    }
    return count;
}
int main(void){
    int n;
    printf("Enter an integer (n): ");
    while (scanf("%d",&n)!=EOF)
    {        
        if(n==0){
            break;
        }
        else if(n<0){
            printf("Please input a positive interger.\n");
        }
        else if(n>0){
            printf("%d!=%lld\n",n,level(n));
        }
        printf("Enter an integer (n): ");
    }   
}
