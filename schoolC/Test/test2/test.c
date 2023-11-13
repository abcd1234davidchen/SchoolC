#include<stdio.h>
#include<stdlib.h>
int main(void){
    int a;
    while(1){
        while (scanf("%d",&a)!=EOF){
            printf("in%d\n",a);
        }
        printf("YOUR FUCKED");
        clearerr(stdin);
    }
}
