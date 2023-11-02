#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int arr[10],max,min,i;
    printf("Array Contents:");
    for(i=0;i<10;i++){
        arr[i]=rand()%100+1;
        printf("%d ",arr[i]);
    }
    max=0;
    min=0;
    for(i=1;i<10;i++){
        if(arr[i]>arr[max]){
            max=i;
        }
        else if(arr[i]<arr[min]){
            min=i;
        }
    }
    printf("\nMaximum value is %d at position %d",arr[max],max+1);
    printf("\nMinimum value is %d at position %d",arr[min],min+1);
}
