#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    while (1) {
        printf("Enter a string (or '0' to quit): ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == '0' || feof(stdin)) {
            break;
        }

        char* start = strchr(input, '\"');
        char* end = strrchr(input, '\"');
        while (start != NULL && end != NULL && start != end) {
            start++;
            *end = '\0';
            printf("%s\n", start);

            start = strchr(end + 1, '\"');
            end = strrchr(end + 1, '\"');
        }

        if (start == NULL || end == NULL) {
            printf("No text within double quotes found.\n");
        }
    }

    return 0;
}
