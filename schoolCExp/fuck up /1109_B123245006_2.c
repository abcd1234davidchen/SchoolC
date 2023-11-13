#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int i,a[20]={0},flag=0,key;
    printf("Original Array:");
    for(i=0;i<20;i++){
        a[i]=rand()%15+1;
        printf(" %d",a[i]);
    }
    key=rand()%15+1;
    printf("\nSearch Number: %d\nPositions where %d appears in the array:\n",key,key);
    for(i=0;i<20;i++){
        if(a[i]==key){
            printf("%d ",i);
            flag=1;
        }
    }
    if(flag==0){
        printf("No found in the array");
    }
}
