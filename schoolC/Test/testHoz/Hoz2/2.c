#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void getword(char a){
    if(isspace(a)){
        printf("\n");
    }
    else printf("%c",a);
}

int main(void){
    char arr[2048]={'\0'};
    int i=0;
    while (fgets(arr,2048,stdin)){
        while (arr[i]!='\0'){
            getword(arr[i]);
            i++;
        }
        i=0;
        memset(arr,'\0',2048);
    }  
}
