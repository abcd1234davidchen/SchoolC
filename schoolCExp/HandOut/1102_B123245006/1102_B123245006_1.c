#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int arr[10],sum=0,i;
    double avg=0;
    printf("Array Item:\n");
    for(i=0;i<10;i++){
        arr[i]=rand()%100+1;
        sum+=arr[i];
        printf("No.%d is %d\n",i+1,arr[i]);
    }
    printf("Sum: %d\n",sum);
    avg=1.0*sum/10;
    printf("Average: %.1lf\n",avg);
}
