#include<stdio.h>
#include<stdlib.h>
int main(void){
    char arr[10]="I am Groot";
    printf("The entire string: %s\n",arr);
    for(int i=0;i<10;i++){
        printf("The %d character is %c\n",i,arr[i]);
    }
}