#include<stdio.h>
#include<math.h>
int main(void){
    int in,rev=0,p=-1,power=1,temp,ogin,ogrev;
    printf("Enter an interger: ");
    scanf("%d",&in);
    //reverse number
    while (in/power>10){
        rev*=10;
        p+=1;
        power=(int)pow(10,p);
        rev+=in/power%10;
    }
    ogrev = rev;
    ogin = in;
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
