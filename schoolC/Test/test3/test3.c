#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int arr[5];
    //og generate
    for(int i=0;i<5;i++){
        arr[i]=rand()%10;
        printf("%d ",arr[i]);
    }
    printf("\n");
    //selection
    int min;
    for (int i=0;i<5;i++){
        min = i;
        for (int j=i;j<5;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        if(min!=i){
            arr[i]=(arr[i]*arr[min])/(arr[min]=arr[i]);
        }
    }
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }

    //insert
}
