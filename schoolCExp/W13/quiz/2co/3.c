#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    char str[100];
    char* start[5];
    char* end[5];
    int i=0,length,j=0;
    while(fgets(str,100,stdin)!=NULL){
        i=0;
        j=0;
        length=strlen(str);
        while(i<length){
            if(str[i]=='\"'){
                start[j]=&str[i+1];
                i++;
                while(i<length && str[i]!='\"'){
                    i++;
                }
                end[j]=&str[i];
                j++;
            }
            i++;
        }
        for(int m=j-1;m>=0;m--){
            for(char* p=start[m];p!=end[m];p++){
                printf("%c",*p);
            }
            printf("\n");
        }
    }
    return 0;
}