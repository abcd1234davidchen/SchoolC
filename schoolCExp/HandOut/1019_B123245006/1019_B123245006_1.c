#include<stdio.h>
int main(void){
    int in;
    printf("Please enter a number(0~100): ");
    scanf("%d",&in);
    if (in>=0&&in<=100){
        for (int i=0;i<in;i++){
            if (i%2==0)
            {
                printf("%d is an even number\n",i);
            }
        }
    }
    else{
        printf("invalid number");
    }
}
