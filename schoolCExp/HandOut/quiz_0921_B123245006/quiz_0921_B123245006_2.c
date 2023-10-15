#include<stdio.h>
int main(void){
    int year,month,date;
    printf("Please enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d",&date,&month,&year);
    printf("The output date is: %04d/%02d/%02d",year,month,date);
    return 0;
}
