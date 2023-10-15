#include<stdio.h>
int main(void){
    int n1 = 123;
    float f1 = 123.4567;
    double f2 = 123.4567;
    printf("整數n1 = %d\n",n1);
    printf("----------\n");
    printf("%%8d  結果：%8d\n",n1);
    printf("%%.8d 結果：%.8d\n",n1);
    printf("%%06d 結果：%06d\n",n1);
    printf("----------\n");
    printf("單精度浮點數f1 = %f\n",f1);
    printf("單精度浮點數f2 = %lf\n",f2);
    printf("----------\n");
    printf("%%.4f   結果：%.4f\n",f1);
    printf("%%10.4f 結果：%10.4f\n",f1);
    printf("%%lf    結果：%lf\n",f2);
    return 0;
}
