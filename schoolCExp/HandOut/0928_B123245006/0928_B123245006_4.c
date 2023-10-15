#include<stdio.h>
int main(){
    char ch;
    int a;
    printf("Please enter an interger: ");
    scanf("%d",&a);
    fflush(stdin);
    printf("Please enter a character: ");
    scanf("%c",&ch);
    printf("I have %d %c\'s.",a,ch);
}