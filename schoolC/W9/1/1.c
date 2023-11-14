#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int a[3][3],b[3][3],i,j;
    //generate
    printf("a.\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            a[i][j]=rand()%101;
            printf("[%d][%d] = %2d, ",i,j,a[i][j]);
        }
        printf("\n");
    }
    printf("\nb.\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            b[i][j]=rand()%101;
            printf("[%d][%d] = %2d, ",i,j,b[i][j]);
        }
        printf("\n");
    }
    //sum sub
    printf("\nadd.\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("[%d][%d] = %3d, ",i,j,a[i][j]+b[i][j]);
        }
        printf("\n");
    }
    printf("\nsub.\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("[%d][%d] = %3d, ",i,j,a[i][j]-b[i][j]);
        }
        printf("\n");
    }
    //multi
    int temp=0,k;
    printf("\nmulti.\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                temp+=a[i][k]*b[k][j];
            }
            printf("[%d][%d] = %5d, ",i,j,temp);
            temp=0;
        }
        printf("\n");
    }
}
