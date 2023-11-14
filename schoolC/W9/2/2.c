#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int fal,sal,i,j;
    printf("First array length\n");
    scanf("%d",&fal);
    printf("Second array length\n");
    scanf("%d",&sal);
    int a[fal+sal];
    //generate first
    printf("First array:[ ");
    for(i=0;i<fal;i++){
        a[i]=rand()%21;
        printf("%d",a[i]);
        if(i!=fal-1){
            printf(" ");
        }
    }
    //sort
    printf(" ]");
    for(i=0;i<fal-1;i++){
        for(j=0;j<fal-i-1;j++){
            if(a[j]>a[j+1]){
                a[j+1]=(a[j]*a[j+1])/(a[j]=a[j+1]);
            }
        }
    }
    printf("\nAfter bubble sort:[");
    for(i=0;i<fal;i++){
        printf("%d",a[i]);
        if(i!=fal-1){
            printf(" ");
        }
    }
    printf("]");
    //generate second
    printf("\nSecond array:[ ");
    for(i=fal;i<fal+sal;i++){
        a[i]=rand()%21;
        printf("%d",a[i]);
        if(i!=fal+sal-1){
            printf(" ");
        }
    }
    printf(" ]");
    //sort second (insertion)
    int temp;
    for(i=fal;i<fal+sal;i++){
        temp=a[i];
        for(j=i-1;j>=fal;j--){
            if(a[j]>temp){
                a[j+1]=a[j];
            }
            else{
                break;
            }
        }
        a[j+1]=temp;
    }
    printf("\nAfter insertion sort:[");
    for(i=fal;i<fal+sal;i++){
        printf("%d",a[i]);
        if(i!=fal+sal-1){
            printf(" ");
        }
    }
    printf("]");
    //sort(selection)
    int min;
    for (i=0;i<fal+sal-1;i++){
        min=i;
        for(j=i;j<fal+sal;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        if(min!=i){
            a[min]=(a[i]*a[min])/(a[i]=a[min]);
        }
    }
    printf("\nAfter merge and sorting:[");
    for(i=0;i<fal+sal;i++){
        printf("%d",a[i]);
        if(i!=fal+sal-1){
            printf(" ");
        }
    }
    printf("]");
}
