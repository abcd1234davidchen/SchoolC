#include<stdio.h>
int main(void){
    int x;
    printf("Enter the AD year: ");
    scanf("%d",&x);
    if (x%4==0&&x%100!=0){
        printf("%d is a leap year",x);
    }
    else if (x%400==0&&x%3200!=0){
        printf("%d is a leap year",x);
    }
    else{
        printf("%d is not a leap year",x);
    }
}
