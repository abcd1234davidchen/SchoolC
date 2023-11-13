#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int a[11],i,j,key;
    for(i=0;i<11;i++){
        a[i]=rand()%100+1;
        for(j=0;j<i;j++){
            while (a[i]==a[j]){
                a[i]=rand()%100+1;
            }
        }
        printf("%d ",a[i]);
    }
    //sort
    int min;
    for(i=0;i<11;i++){
        min = i;
        for(j=i+1;j<11;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min!=i){
            a[i]=(a[min]*a[i])/(a[min]=a[i]);
        }
    }
    printf("\n");
    for(i=0;i<11;i++){
        printf("%d ",a[i]);
    }
    key=rand()%12;
    int low=0,high=10,mid;
    while(low<=high){
        
    }
}
