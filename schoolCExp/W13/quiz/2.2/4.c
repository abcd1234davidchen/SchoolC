#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
    char arr[2048]={0};
    while(fgets(arr,2048,stdin)!=NULL){
        int hFlag=0;
        for(int i=0;i<2048;i++){
            //printf("%d = %c\n",i,arr[i]);
            if(arr[i]=='\"'&&hFlag==0){
                hFlag=1;
                i++;
            }
            if(hFlag==1&&arr[i]!='\"'){
                printf("%c",arr[i]);
            }
            if(hFlag==1&&arr[i]=='\"'){
                hFlag=0;
                printf("\n");
            }
        }
        printf("\n");
        memset(arr,'\0',2048);
    }
}