#include<stdio.h>
#include<stdlib.h>
void find(char from[],char target[]){
    int fOcc=-1,lOcc=-1;
    int targetLength=0;
    while(target[targetLength]!='\0'){
        targetLength++;
    }
    for(int i=0;i<2048;i++){
        int j;
        if(from[i]==target[0]){
            int flag=1;
            for(j=0;j<targetLength;j++){
                if(from[i+j]!=target[j]){
                    flag=0;
                }
            }
            if(flag){
                fOcc=i;
                lOcc=j+i-1;
            }
        }
    }
    if(lOcc!=-1){
        printf("%d,%d\n",fOcc,lOcc);
    }
    else{
        printf("-1\n");
    }
}
int main(void){
    char in[3072];
    while (fgets(in,3072,stdin)!=NULL){
        char s[2048]={0},w[1024]={0};
        sscanf(in,"%[^,], %s",s,w);
        find(s,w);
    }
    
}
