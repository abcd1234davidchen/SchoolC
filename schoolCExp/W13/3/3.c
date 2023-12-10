#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortNumbers(int *a, int *b, int *c, int *d, int *e) {
    int i,j, temp;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (*a > *b) {
                temp = *a;
                *a = *b;
                *b = temp;
            }
            if (*b > *c) {
                temp = *b;
                *b = *c;
                *c = temp;
            }
            if (*c > *d) {
                temp = *c;
                *c = *d;
                *d = temp;
            }
            if (*d > *e) {
                temp = *d;
                *d = *e;
                *e = temp;
            }
        }
    }
}

int main() {
    int num1, num2, num3, num4, num5;

    srand(time(NULL));
    num1 = rand() % 20 + 1;
    num2 = rand() % 20 + 1;
    num3 = rand() % 20 + 1;
    num4 = rand() % 20 + 1;
    num5 = rand() % 20 + 1;

    printf("Random 5 Numbers: %d %d %d %d %d\n", num1, num2, num3, num4, num5);
    sortNumbers(&num1, &num2, &num3, &num4, &num5);
    printf("Sorted: %d %d %d %d %d\n", num1, num2, num3, num4, num5);

    return 0;
}