#include<stdio.h>
#include<stdlib.h>
int main(void){
    int a[1024]={0},count=0,low=0,mid,up,down;
    while (scanf("%d",&a[count])!=EOF){
        count+=1;
    }
    int high = count;
    high-=1;
    while(low<high){
        mid = (low+high)/2;
        if(a[mid]==10000){
            printf("10000");
            break;
        }
        else if(a[mid]<10000){
            low = mid+1;
        }
        else if(a[mid]>10000){
            high = mid-1;
        }
    }
    if(a[mid]!=10000){
        up=a[high]-10000;
        if(up<0){
            up=0-up;
        }
        down=a[high-1]-10000;
        if(down<0){
            down=0-down;
        }
        if(up>down){
            printf("%d",a[high-1]);
        }
        else{
            printf("%d",a[high]);
        }
    }
}
