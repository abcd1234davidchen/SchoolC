#include<stdio.h>
int main(void){
    double n;
    printf("Enter the side length of the square (N): ");
    scanf("%lf",&n);
    n=n*n/4;
    printf("The difference between the areas is: %.2lf",n*3.14);
    return 0;
}
