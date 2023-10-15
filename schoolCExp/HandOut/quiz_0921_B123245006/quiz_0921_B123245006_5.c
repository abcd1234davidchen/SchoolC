#include<stdio.h>
int main(void){
    int second,day,hour,minute,insec;
    printf("Enter the number of seconds (N): ");
    scanf("%d",&second);
    insec = second;
    day = second/86400;
    second %= 86400;
    hour = second/3600;
    second %= 3600;
    minute = second/60;
    second %= 60;
    printf("%d seconds is equal to: %d days, %d hours, %d minutes, %d seconds.",insec,day,hour,minute,second);
    return 0;
}
