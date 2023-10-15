#include<stdio.h>
int main(void){
    char ch;
//    int i=1;

    do
    {
    printf("Enter a character: ");
    scanf(" %c",&ch);    
    switch (ch)
    {
    case 'A':
    case 'a':
        printf("Enter new mode\n");
        break;
    case 'D':
    case 'd':
        printf("Enter delete mode\n");
        break;
    
    case 'U':
    case 'u':
        printf("Enter modification mode\n");
        break;
    
    case 'Q':
    case 'q':
        printf("Leave the system\n");
//        i=0;
        break;
    
    default:
        printf("There is no such option!\n");
        break;
    }
    } while (ch!='q'&&ch!='Q');
}
