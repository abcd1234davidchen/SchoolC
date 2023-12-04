#include<stdio.h>
#include<stdlib.h>
long long level(int a){
    long long count=1;
    for(int i=1;i<=a;i++){
        count*=i;
    }
    return count;
}
long long P (int a,int b){
    int temp = a-b;
    return(level(a)/level(temp));
}

long long C (int a,int b){
    int temp = a-b;
    return(level(a)/(level(temp)*level(b)));
}

long long H (int a,int b){
    int temp = a+b-1;
    return(C(temp,b));
}

int main(void){
    int a,b;
    while (scanf("%d %d",&a,&b)!=EOF){
        if(a==0||b==0){
            printf("Finish!");
            break;
        }
        if(a+b>20){
            printf("Invalid input\n");
            continue;
        }
        printf("The P(%d,%d) is %lld\n",a,b,P(a,b));
        printf("The C(%d,%d) is %lld\n",a,b,C(a,b));
        printf("The H(%d,%d) is %lld\n",a,b,H(a,b));
    }
}
