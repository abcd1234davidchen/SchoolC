#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[] = "The Great Gatsby, F. Scott Fitzgerald, 1925, 1001";
    char a[1024];
    char b[1024];
    char c[1024];
    char d[1024];

    sscanf(input, "%[^,], %[^,], %[^,], %s", a, b, c, d);

    printf("%s %s %s %s\n", a, b, c, d);

    return 0;
}