#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main(){
    char input[5][100];
    int i=0;
    memset(input,'\0',500);
    printf("Enter a series of string: \n");
    while(fgets(input[i],100,stdin)!=NULL&&i<4){
        i++;
    }
    printf("Reversed order:\n");
    for(i=0;i<5;i++){
        printf("%s",input[4-i]);
    }    
    return 0;
}