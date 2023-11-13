#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int length = 10;
    int arr[length],i,j,temp,min;
    //generate
    for (i=0;i<length;i++){
        arr[i]=rand()%10;
        printf("%d ",arr[i]);
    }
    printf("\n");
    //bubble sort
    for(i=0;i<length-1;i++){
        for(j=0;j<length-i-1;j++){
            if(arr[j]>arr[j+1]){
                arr[j]=(arr[j]+arr[j+1])-(arr[j+1]=arr[j]);
            }
        }
    }
    for (i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    //generate
    for (i=0;i<length;i++){
        arr[i]=rand()%10;
        printf("%d ",arr[i]);
    }
    printf("\n");
    //insertion sort
    for(i=1;i<length;i++){
        temp=arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
    for (i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    //generate
    for (i=0;i<length;i++){
        arr[i]=rand()%10;
        printf("%d ",arr[i]);
    }
    printf("\n");
    //selection sort
    for(i=0;i<length;i++){
        min=i;
        for(j=i+1;j<length;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            arr[min]=(arr[min]+arr[i])-(arr[i]=arr[min]);
        }
    }
    for (i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
