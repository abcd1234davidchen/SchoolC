#include<stdio.h>
int main(void){
    char ch;
    printf("Enter a character: ");
    scanf("%c",&ch);
    switch (ch)
    {
    case 'A':
    case 'a':
        printf("Enter new mode");
        break;
    case 'D':
    case 'd':
        printf("Enter delete mode");
        break;
    
    case 'U':
    case 'u':
        printf("Enter modification mode");
        break;
    
    case 'Q':
    case 'q':
        printf("Leave the system");
        break;
    
    default:
        printf("There is no such option!");
        break;
    }
}
