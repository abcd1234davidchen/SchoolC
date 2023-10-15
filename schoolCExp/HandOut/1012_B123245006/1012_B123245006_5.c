#include<stdio.h>
int main(void){
    int x,lead,end;
    printf("Please enter a two-digit number: ");
    scanf("%d",&x);
    if (x>=10&&x<=19){
        switch (x)
        {
        case 10:
            printf("In English: Ten");
            break;
        case 11:
            printf("In English: Eleven");
            break;
        case 12:
            printf("In English: Twelve");
            break;
        case 13:
            printf("In English: Thirteen");
            break;
        case 14:
            printf("In English: Fourteen");
            break;
        case 15:
            printf("In English: Fifteen");
            break;
        case 16:
            printf("In English: Sixteen");
            break;
        case 17:
            printf("In English: Seventeen");
            break;
        case 18:
            printf("In English: Eighteen");
            break;
        case 19:
            printf("In English: Ninteen");
            break;
        default:
            break;
        }
    }
    else{
        lead=x/10;
        end=x%10;
        switch (lead)
        {
        case 2:
            printf("In English: Twenty");
            break;
        
        case 3:
            printf("In English: Thirty");
            break;
        
        case 4:
            printf("In English: Forty");
            break;
        
        case 5:
            printf("In English: Fifty");
            break;
        
        case 6:
            printf("In English: Sixty");
            break;
        
        case 7:
            printf("In English: Seventy");
            break;
        
        case 8:
            printf("In English: Eighty");
            break;
        
        case 9:
            printf("In English: Ninety");
            break;
        
        default:
            break;
        }
        switch (end)
        {
        case 1:
            printf("-One");
            break;
        case 2:
            printf("-Two");
            break;
        
        case 3:
            printf("-Three");
            break;
        
        case 4:
            printf("-Four");
            break;
        
        case 5:
            printf("-Five");
            break;
        
        case 6:
            printf("-Six");
            break;
        
        case 7:
            printf("-Seven");
            break;
        
        case 8:
            printf("-Eight");
            break;
        
        case 9:
            printf("-Nine");
            break;
        
        default:
            break;
        }
    }
}
