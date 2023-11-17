#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
    char inp[2][1024];
    memset(inp,'\0',2*1024);
    int b=0,max=0;
    while(fgets(inp[0],100,stdin)!=NULL){
        b=(int)strlen(inp[0])-1;
        if(b>=max){
            strcpy(inp[1],inp[0]);
            max=b;
        }
    }
    printf("%s",inp[1]);
}
