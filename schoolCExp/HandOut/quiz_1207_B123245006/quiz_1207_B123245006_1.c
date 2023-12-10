#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int fib(int a){
    if (a==1||a==0){
        return a;
    }else{
        return fib(a-1)+fib(a-2);
    }
}

void make_digit(num){
    int len=0;
    while(num>fib(len)){
        len++;
    }
    len-=1;
    //printf("len = %d\n",len);
    while(1){
        if(len==1){
            break;
        }else if(num-fib(len)>=0){
            //printf(" %d\n",fib(len));
            num -= fib(len);
            printf("1");
            len-=1;
        }else{
            len-=1;
            printf("0");
        }
    }
    printf(" (fib)");
}

int main(){
    int num ;
    while(scanf(" %d",&num)!=EOF){
        if(num==0){
            printf("Finish!");
            break;
        }else if(num>100000000||num<0){
            printf("Invalid input,input again\n");
        }else{
            printf("%d = ",num); 
            if(num==1){
                printf("1 (fib)");
            }else{
                make_digit(num);
            }
            printf("\n");    
        } 
    }
    

    return 0;
}