#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float mymean(int arr[], int len){
    int sum=0;
    for(int i=0;i<len;i++){
        sum+=arr[i];
    }
    printf("Mean of the array is %f\n",sum*1.0/len);
    printf("The address of the mean is %p\n", (void*)&mymean);
    return sum*1.0f/len;
}

int main(void){
    srand((unsigned int)time(NULL));
    int len=5;
    int arr[len];
    for(int i=0;i<len;i++){
        arr[i]=(rand()%10)*10;
        printf("%d ",arr[i]);
    }
    printf("\n");
    mymean(arr,len);    
}
