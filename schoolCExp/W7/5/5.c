#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    int a,b;
    srand(time(NULL));
    a = rand()%10+1;//height
    b = rand()%10+1;//width
    printf("height:%d width:%d\n",a,b);
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("*");
        }
        printf("\n");
    }

}
