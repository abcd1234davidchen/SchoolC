#include<stdio.h>
int main(void){
    float flo;
    scanf("%f",&flo);
    printf("%10.1f\n",flo);
    printf("%010.2f\n",flo);
    printf("%+10.4f\n",flo);
    printf("%.3f\n",flo);
    return 0;
}
