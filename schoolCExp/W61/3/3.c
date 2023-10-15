#include<stdio.h>
int main (void){
    int a,b,c,tri,j;
    printf("Enter the three positive intergers a, b, and c: ");
    scanf("%d %d %d",&a,&b,&c);
    j= a*a-b*b-c*c;
    tri = a>=b+c ? 0 : j==0 ? 1: j>0 ? 2:3;//0 no 1 right 2 o 3 acute
    if (tri == 0){
        printf("Not a triangle");
    }
    else if (tri == 1){
        printf("Right triangle");
    }
    else if (tri == 2){
        printf("Obtuse triangle");
    }
    else if (tri == 3){
        printf("Acute triangle");
    }
}
