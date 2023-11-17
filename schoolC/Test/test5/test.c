#include<stdio.h>
#include<stdlib.h>
int main(void){
    int num,base,arr[4],i;
    while (1){
        printf("NUM/BASE");
        scanf("%d %d",&num,&base);
        if(num==0&&base==0) break;
        if(num>65535||base>16){
            printf("DONT FUCK WITH ME\n");
            continue;
        }
        arr[0]=num/(base*base*base);
        arr[1]=num/(base*base)%base;
        arr[2]=num/base%base;
        arr[3]=num%base;
        for(i=0;i<4;i++){
            switch (arr[i]){
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d",arr[i]);
                break;
            }   
        }
        printf("\n");
    }
}
