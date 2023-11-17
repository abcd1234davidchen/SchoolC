#include<stdio.h>
#include<stdlib.h>
int main(void){
    char arr[20];
    printf("Enter a string: ");
    scanf("%s",arr);
    printf("%s\n",arr);
    printf("%s\n",arr);
    printf("%s\n",arr);
    fflush(stdin);
    printf("Enter a string: ");
    gets(arr);
    puts(arr);
    puts(arr);
    puts(arr);
}
