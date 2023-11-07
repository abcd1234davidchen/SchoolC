#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void hw1(void){
    int in,first,last,count=0;
    printf("Enter the value of n: ");
    scanf("%d",&in);
    printf("Side length of triangle:\n");
    for (first=0;first<in;first++){
        for(last=in+1;last<(first+in);last++){
            printf("%d %d %d\n",first,in,last);
            count+=1;
        }
    }    
    printf("Number of triangle with n as the middle side length: %d\n",count);
}
void hw2(void){
    int a[3][3],b[3][3],add[3][3],sub[3][3];
    printf("a.\n");
    for(int i=0;i<3;i++){
        printf("[");
        for(int j=0;j<3;j++){
            a[i][j]=rand()%101;
            printf("%2d",a[i][j]);
            if(j!=2){
                printf(" ");
            }
        }
        printf("]\n");
    }
    printf("b.\n");
    for(int i=0;i<3;i++){
        printf("[");
        for(int j=0;j<3;j++){
            b[i][j]=rand()%101;
            printf("%2d",b[i][j]);
            if(j!=2){
                printf(" ");
            }
        }
        printf("]\n");
    }
    printf("add.\n");
    for(int i=0;i<3;i++){
        printf("[");
        for(int j=0;j<3;j++){
            add[i][j]=a[i][j]+b[i][j];
            printf("%d",add[i][j]);
            if(j!=2){
                printf(" ");
            }
        }
        printf("]\n");
    }
    printf("sub.\n");
    for(int i=0;i<3;i++){
        printf("[");
        for(int j=0;j<3;j++){
            sub[i][j]=a[i][j]-b[i][j];
            printf("%d",sub[i][j]);
            if(j!=2){
                printf(" ");
            }
        }
        printf("]\n");
    }
}
int main(void){
    srand(time(NULL));
    hw1();
    printf("\n");
    hw2();
}
