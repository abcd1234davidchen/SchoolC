#include<stdio.h>
int main(void){
    int x;
    printf("Please enter an interger (1~100): ");
    scanf("%d",&x);
    if (x>0&&x<34){
        printf("You are in the LUCKY area.");
    }
    else if (x>32&&x<73){
        printf("You are in the GG area.");
    }
    else if (x>71&&x<101){
        printf("You are in the Awesome area.");
    }
    else{
        printf("Out of range");
    }
}
