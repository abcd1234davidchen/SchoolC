#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int in,ran,sum=0;
    printf("Enter the number of random numbers to generate:");
    scanf("%d",&in);
    printf("Random numbers:\n");
    for (int i=1;i<=in;i++){
        ran=rand()%500+1;
        if (i==1){
            printf("The first random number %d\n",ran);
            sum+=ran;
        }
        else if (i==2){
            printf("The second random number %d\n",ran);
            sum+=ran;
        }
        else if (i==3){
            printf("The third random number %d\n",ran);
            sum+=ran;
        }
        else{
            printf("The %dth random number %d\n",i,ran);
            sum+=ran;
        }
    }
    printf("The sum is: %d",sum);
}
