#include<stdio.h>
int main(void){
    int in;
    printf("Please enter the number of layers:");
    scanf("%d",&in);
    for (int i=0;i<=in;i++){
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}