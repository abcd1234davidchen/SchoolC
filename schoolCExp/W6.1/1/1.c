#include<stdio.h>
int main(void){
    int a1,a2,a3,a4,a5,max;
    printf("Enter five intergers: \n");
    scanf("%d %d %d %d %d",&a1,&a2,&a3,&a4,&a5);
    max = a1;
    if (a2>max){
        a2=max;
    }
    if (a3>max){
        a3=max;
    }
    if (a4>max){
        a4=max;
    }
    if (a5>max){
        a5=max;
    }
    printf("From %d, %d, %d, %d, %d, the maximum number is: %d",a1,a2,a3,a4,a5,max);
}
