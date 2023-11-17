#include<stdio.h>
#include<stdlib.h>
int main(void){
    char buffer[1024],i=0;
    printf("Please enter a string: ");
    while(fgets(buffer, 1024, stdin)!=NULL){
        while (buffer[i]!='\0'){
            i+=1;
        }
        printf("Input string length is: %d\n",i-1);
        printf("Please enter a string: ");
        i=0;
    }
}
