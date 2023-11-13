#include<stdio.h>
#include<stdlib.h>
int main(void){
    int i,j,temp;
    int a[5] = {4,6,9,3,2};
    for (i=1;i<5;i++){
        temp = a[i];
        for(j=i-1;j>=0;j--){
            if(a[j]>temp){
                a[j+1] = a[j];
            }
            else{
                break;
            }
        }
        a[j+1]=temp;
    }
    for(i=0;i<5;i++){
        printf("%d ",a[i]);
    }
}
