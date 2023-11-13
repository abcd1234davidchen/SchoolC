#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int n,m,temp;
    printf("Enter the value of N and M (1<N,M<10):");
    scanf("%d %d",&n,&m);
    while (n!=0||m!=0)
    {
        if(n>1&&m>1&&n<10&&m<10){
            int a1[n][m],a2[m][n],a[n][n];
            printf("Matrix 1:\n");
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    a1[i][j]=rand()%2;
                    printf("%d",a1[i][j]);
                }
                printf("\n");
            }
            printf("Matrix 2:\n");
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    a2[i][j]=rand()%2;
                    printf("%d",a2[i][j]);
                }
                printf("\n");
            }
            printf("Resulting Matrix:\n");
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp=0;
                    for(int y=0;y<m;y++){
                        temp+=a1[i][y]*a2[y][j];
                    }
                    a[i][j]=temp;
                    printf("%d",a[i][j]);
                }
                printf("\n");
            }

        }
        else{
            printf("Invalid Input: N and M must be between 2 and 9\n");
        }
        printf("Enter the value of N and M (1<N,M<10):");
        scanf("%d %d",&n,&m);
    }
    printf("Finish!");
}