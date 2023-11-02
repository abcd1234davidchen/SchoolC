#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int og[10],dif[9],i,flag;
    for(i=0;i<10;i++){
        og[i]=rand()%10;
    }
    for(i=0;i<9;i++){
        dif[i]=og[i+1]*(i+1);
    }
    flag=0;
    printf("Original polynomial: ");
    for(i=9;i>=0;i--){
        if(og[i]!=0){
            if (flag==1){
                printf("+ ");
            }
            printf("%d * x^%d ",og[i],i);
            flag=1;
        }
    }
    flag=0;
    printf("\nDifferentiated polynomial: ");
    for(i=8;i>=0;i--){
        if(dif[i]!=0){
            if (flag==1){
                printf("+ ");
            }
            printf("%d * x^%d ",dif[i],i);
            flag=1;
        }
    }
}
