#include <stdio.h>

long long gcd(int a, int b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main(void) {
    int num1, num2;
    
    while (1) {
        printf("Enter two integers (0 0 to terminate): ");
        if (scanf("%d %d", &num1, &num2) == EOF) {
            break;
        }
        
        if (num1 == 0 && num2 == 0) {
            break;
        }
        
        printf("GCD(%d,%d)= %lld\n",num1,num2,gcd(num1, num2));
        printf("LCD(%d,%d)= %lld\n",num1,num2,lcm(num1, num2));
    }
    
    return 0;
}
