#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
    char inp[30][1024];
    int ans[30]={0};
    memset(inp,'\0',30*1024);
    int a=0,b=0,correct,i,c=0;
    while(fgets(inp[a],100,stdin)!=NULL&&a<30){
        b=(int)strlen(inp[a])-1;
        correct=1;
        for(i=0;i<(b/2);i++){
            if(inp[a][i]!=inp[a][b-i-1]){
                correct=0;
                break;
            }
        }
        if(correct){
        	ans[c]=a;
            c+=1;
        }
        a++;
    }
    for(i = 0; i < c; i++){
        printf("%s", inp[ans[i]]);
    }
}