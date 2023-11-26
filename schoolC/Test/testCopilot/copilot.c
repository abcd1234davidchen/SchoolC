
#include <stdio.h>

int main() {
    int bun = 1;

    switch (bun) {
        case 1:
            printf("Purchase 黑糖包\n");
            break;
        case 2:
            printf("Purchase 爆漿包\n");
            break;
        default:
            printf("算了\n");
            break;
    }

    return 0;
}
