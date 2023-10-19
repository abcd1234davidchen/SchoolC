#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    int right,in;
    srand(time(NULL));
    right = rand()%10+1;
    printf("Please enter a number(1~10):");
    scanf("%d",&in);
    while(in!=right){
        printf("You guessed wrong, please try again.\n");
        printf("Please enter a number(1~10):");
        scanf("%d",&in);
    }
    printf("Congratulations! The answer is %d",right);
}
