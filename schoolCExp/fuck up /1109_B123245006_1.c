#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(NULL));
    int og[15]={0},sel[15]={0},ins[15]={0},bub[15]={0};
    int i,j;
    printf("Original Array:\n");
    for(i=0;i<15;i++){
        og[i]=rand()%100+1;
        sel[i]=og[i];
        ins[i]=og[i];
        bub[i]=og[i];
        printf("%d ",og[i]);
    }
    //selection  error
    int min;
    for(i=0;i<15;i++){
        min = i;
        for(j=i+1;j<15;j++){
            if(sel[j]<sel[min]){
                min = j;
            }
        }
        if(min!=i){
            sel[i]=(sel[min]*sel[i])/(sel[min]=sel[i]);
        }
    }
    printf("\n\nSelction Sort (Ascending):\n");
    for(i=0;i<15;i++){
        printf("%d ",sel[i]);
    }
    printf("\nSelction Sort (Decending):\n");
    for(i=0;i<15;i++){
        printf("%d ",sel[14-i]);
    }
    //insertion
    int temp;
    for(i=0;i<15;i++){
        temp = ins[i];
        for(j=i-1;j>=0;j--){
            if(ins[j]>temp){
                ins[j+1]=ins[j];
            }
            else{
                break;
            }
        }
        ins[j+1]=temp;
    }
    printf("\n\nInsertion Sort (Ascending):\n");
    for(i=0;i<15;i++){
        printf("%d ",ins[i]);
    }
    printf("\nInsertion Sort (Decending):\n");
    for(i=0;i<15;i++){
        printf("%d ",ins[14-i]);
    }
    //bubble
    for(i=0;i<14;i++){
        for(j=0;j<14-i;j++){
            if(bub[j]>bub[j+1]){
                bub[j+1]=(bub[j+1]*bub[j])/(bub[j]=bub[j+1]);
            }
        }
    }
    printf("\n\nBubble Sort (Ascending):\n");
    for(i=0;i<15;i++){
        printf("%d ",bub[i]);
    }
    printf("\nBubble Sort (Decending):\n");
    for(i=0;i<15;i++){
        printf("%d ",bub[14-i]);
    }
}
