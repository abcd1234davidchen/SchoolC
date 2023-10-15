#include<stdio.h>
int main(void){
    int x,a=0;
    printf("Please input an interger: ");
    scanf("%d",&x);
    if (x<0){
        a=0-x;
    }
    else{
        a=x;
    }
    printf("The absolute number of %d is %d",x,a);
}
