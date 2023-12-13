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
            while(str[i]!='\"'){
                i++;
            }
            start[j]=&str[i+1];
            i++;
            while(str[i]!='\"'){
                i++;
            }
            end[j]=&str[i];
            i+=2;
            j++;
        }
        for(int m=j;m>=0;m--){
            while (start[m]+i!=end[m]){
                printf("%c",start[m][i]);
                i++;
            }
        }
    }
}
