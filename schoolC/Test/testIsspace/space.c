#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = ' ';

    if (isspace(ch)) {
        printf("The character is a whitespace character.\n");
    } else {
        printf("The character is not a whitespace character.\n");
    }

    return 0;
}
