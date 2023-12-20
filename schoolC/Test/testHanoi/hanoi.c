#include<stdio.h>
#include<stdlib.h>
/*
void hanoi(int n,char A,char B,char C,int* times){
    // n amount A to C B Buffer
    if(n==1){
        (*times)++;
        printf("Move ring %d from %c to %c\n", n, A, C);
    }
    else{
        hanoi(n-1,A,C,B,times);
        hanoi(1,A,B,C,times);
        hanoi(n-1,B,A,C,times);
    }
}*/
void hanoi(int n,char A,char B,char C,int* times){
    // n amount A to C B Buffer
    if(n==1){
        (*times)++;
        printf("Move ring 1 from %c to %c\n", A, C);
    }
    else{
        hanoi(n-1,A,C,B,times);
        printf("Move ring %d from %c to %c\n", n, A, C);
        (*times)++;
        hanoi(n-1,B,A,C,times);
    }
}
int main(void){
    int n=0;
    int times=0;
    while (scanf("%d",&n)!=EOF){
        hanoi(n,'A','B','C',&times);
        printf("%d moves total\n",times);
    }
}
