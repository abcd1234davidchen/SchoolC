#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char* getword(char *line,char* word){
    char* ptr,*qtr;
    ptr=line;qtr=word;
    while (isspace(*ptr)){ptr++;};
    while (!isspace(*ptr)&&(*ptr)){*qtr++=*ptr++;}
    *qtr='\0';
    if(strlen(word)==0)
        return NULL;
    else
        return ptr;
}

int main(void){
    char line[1024]={'\0'};
    char word[1024]={'\0'};
    char *ptr;
    while (fgets(line,2048,stdin)){
        ptr=line;
        while ((ptr=getword(ptr,word))!=NULL){
            printf("%s\n",word);
        }
        
    }  
}
