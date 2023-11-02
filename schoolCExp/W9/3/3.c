#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int og[10],dif[9],i;
    for(i=0;i<10;i++){
        og[i]=rand()%10;
    }
    for(i=0;i<9;i++){
        dif[i]=og[i+1]*(i+1);
    }
    printf("Original polynomial: ");
    for(i=9;i>=0;i--){
        if(og[i]!=0){
            printf("%d * x^%d ",og[i],i);
        }
    }
    printf("\nDifferentiated polynomial: ");
    for(i=8;i>=0;i--){
        if(dif[i]!=0){
            printf("%d * x^%d ",dif[i],i);
        }
    }
}
