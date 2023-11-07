#include <stdio.h>
#include <stdlib.h>

int c=1;

void swap(int *a,int x,int y)
{
    int tmp;
    tmp=a[x];
    a[x]=a[y];
    a[y]=tmp;
}

void perm(int *a,int m,int n){
    if(m==n){
        for(int i=0;i<n;i++){
            printf("%d",a[i]);
        }
        printf("\n");
    }
    else {
        printf("X\n");
        for(int i=m;i<n;i++){
            swap(a,m,i);
            perm(a,m+1,n);
            swap(a,m,i);
        }
    }
}

int main()
{
    int a[6]={1,2,3,4,5},tmp;
    int n=5;

    for(int i=n;i>0;i--){
        c*=i;
    }

    perm(a,0,n);

    printf("There are %d orders in total.\n",c);

    return 0;
}