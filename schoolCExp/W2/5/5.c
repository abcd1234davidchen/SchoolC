#include<stdio.h>
int main(void){
    int i = 32767;
    short int s = 32767;
    printf("整數i = %d\n",i);
    printf("短整數s = %d\n",s);
    i+=1;
    s+=1;
    printf("i+1 = %d\n",i);
    printf("s+1 = %d\n",s);
    return 0;
}
