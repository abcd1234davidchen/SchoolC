#include<stdio.h>
int main(void){
    int a,b,p,pow,oa;
    printf("Please input a pair of interger (m,n): ");
    while(scanf("%d %d",&a,&b)!=EOF){
        p=0;
        pow=1;
        if(a==0){
            if(b==0){
                printf("Wrong input, input again!\n");
            }
            else{
                printf("0 is not the power of any number, input again.\n");
            }
        }
        else{
            oa=a;
            while (a>=b){
                a/=b;
                p+=1;
            }
            for(int i=0;i<p;i++){
                pow*=b;
            }
            if(oa==pow){
                printf("%d is the power of %d\n",oa,b);
            }
            else{
                printf("%d is not the power of %d\n",oa,b);
            }
        }
        printf("Please input a pair of interger (m,n): ");
    }
}
