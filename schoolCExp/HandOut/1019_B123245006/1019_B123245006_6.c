#include<stdio.h>
int main(void){
    int total=0,temp;
    printf("Please enter some intergers ande use EOF to end input:\n");
    while(scanf("%d",&temp)!=EOF){
        total+=temp;
    }
    printf("The total sum of entered intergers is %d",total);
}
