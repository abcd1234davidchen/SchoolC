#include<stdio.h>
int main(void){
    int a,b;
    while (scanf("%d\n%d",&a,&b)!=EOF)
    {
        printf("X+Y=%d\n",a+b);
        printf("X-Y=%d\n",a-b);
        printf("X*Y=%d\n",a*b);
        if(b==0){
            printf("error");
        }
        else{
            printf("X/Y=%f\n",1.0*a/b);
        }
    }
}
