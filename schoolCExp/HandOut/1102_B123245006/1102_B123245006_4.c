#include<stdio.h>
#include<stdlib.h>
int main(void){
    int arr[2][3],i,j;
    for (i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("Enter the element at row%d, column%d: ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Original matrix\n");
    for (i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
    printf("Original matrix\n");
    for (i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("%d   ",arr[j][i]);
        }
        printf("\n");
    }
}
