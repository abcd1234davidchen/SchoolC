#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void HW1(void){
    srand(time(NULL));
    int arr[10],L,R,i,max=0,temp,maxA[2];
    printf("10.1\n[ ");
    for(i=0;i<10;i++){
        arr[i]=rand()%11-5;
        printf("%d ",arr[i]);
    }
    printf("]");
    for(L=0;L<10;L++){
        for(R=L+1;R<10;R++){
            temp=1;
            for(i=L;i<=R;i++){
                temp*=arr[i];
            }
            //printf("\n%dL%dR%dT",L,R,temp);
            if(temp>max){
                max=temp;
                maxA[0]=L;
                maxA[1]=R;
            }
        }
    }
    printf("\nMaximum Product Subarray is from position %d to %d with product %d\n[ ",maxA[0]+1,maxA[1]+1,max);
    for(i=maxA[0];i<=maxA[1];i++){
        printf("%d ",arr[i]);
    }
    printf("]\n");
}
void HW2(void){
    char RLs[50];
    int R,L,rCount=0,lCount=0,len,i,balanceCount=0;
    printf("\n10.2\nInput a string: ");
    scanf("%s",RLs);
    len=strlen(RLs);
    for(L=0;L<len;L++){
        for(R=L+1;R<len;R++){
            for(i=L;i<=R;i++){
                if(RLs[i]=='R'){
                    rCount++;
                }
                else if(RLs[i]=='L'){
                    lCount++;
                }
            }
            if (rCount==lCount){
                for(i=L;i<=R;i++){
                    printf("%c",RLs[i]);
                }
                balanceCount++;
                printf("\n");
            }
            rCount=0;
            lCount=0;
        }
    }
    printf("\nMaximum number of balanced substrings: %d\n",balanceCount);
}
int main(void){
    HW1();
    HW2();
}
