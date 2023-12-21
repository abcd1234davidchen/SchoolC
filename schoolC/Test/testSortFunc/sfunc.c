#include <stdio.h>
#include <string.h>

void bubbleSortStrings(char arr[][100], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {//str1-str2
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main(void) {
    char arr[][100] = {"apxe", "aple", "cherry", "date", "elderberry"};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSortStrings(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    return 0;
}
