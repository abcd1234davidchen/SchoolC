#include <stdio.h>

unsigned int swap_bytes(unsigned int x) {
    return ((x & 0xFF00FF00) >> 8) | ((x & 0x00FF00FF) << 8);
}

int main() {
    unsigned int x;
    printf("請輸入一個無符號整數: ");
    scanf("%u", &x);
    printf("交換第二和第三個位元組後的結果為: %u\n", swap_bytes(x));
    return 0;
}
