#include<stdio.h>
int main(void){
    int in,rev=0,temp,ogin,ogrev;
    printf("Enter an interger: ");
    scanf("%d",&in);
    temp = in;
    //reverse number
    while (in!=0){
        rev=rev*10+in%10;
        in/=10;
    }
    ogrev = rev;
    in = temp;
    ogin = temp;
    printf("Reversed number: %d\n",ogrev);
    //GCD
    if (rev>in){//in >= rev
        temp = rev;
        rev = in;
        in = temp;
    }
    while (in%rev!=0){
        temp = rev;
        rev = in%rev;
        in = temp;
    }
    printf("GCD of %d and %d is %d",ogin,ogrev,rev);
}
