#include<stdio.h>
int main(void){
    int inpt,a,j=0,count=0,temp;
    printf("Input a number: ");
    scanf("%d",&inpt);
    a=inpt;
    while(count<5){
        j=1;
        a+=1;
        for(temp = 2;temp<a;temp++){
            if (a%temp==0){
                j=0;
            }
        }
        if (j==1&&a!=1){
            printf("%d ",a);
            count+=1;
        }
    }
}
