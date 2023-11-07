#include<stdio.h>
int main(void){
    int x=0;
    for (int a=1;a<6;a++){
        for (int b=1;b<6;b++){
            for (int c=1;c<6;c++){
                for (int d=1;d<6;d++){
                    for (int e=1;e<6;e++){
                        if(a!=b && a!=c && a!=d && a!=e && b!=c && b!=d && b!=c && b!=e && c!=d && c!=e && d!=e){
                            x=x+1;
                            printf("%d%d%d%d%d\n",a,b,c,d,e);
                        }
                    }
                }
            }
        }
    }
    printf("There are %d orders in total.",x);
}
