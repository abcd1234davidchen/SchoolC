#include <stdio.h>
int main(void){
    int min,max,temp,flag,add,pof,p10;
    printf("Please input a range[i,j]: ");
    while (scanf("%d %d",&min,&max)!=EOF){
        if(min>=10&&max<=200000&&max>=min){
            add=0;
            for(int i=min+1;i<=max;i++){
                pof=1;
                p10=1;
                temp=i;
                while (temp>10){
                    temp/=10;
                    pof+=1;
                    p10*=10;
                }
                flag=0;
                temp=i;
                for(int j=0;j<pof;j++){//rotate
                    for(int m=2;m*m<temp;m++){//prime
                        if (temp%m==0){
                        flag=1;
                        break;
                        }
                    }
                    temp = temp/10+temp%10*p10;
                }
                if(flag==0){
                    //printf("%d ",i);
                    add+=1;
                }
            }
            if (add==0){
                printf("no Circular prime\nPlease input a range[i,j]: ");
            }
            else{
                printf("%d Circular prime\nPlease input a range[i,j]: ",add);
            }
        }
        else{
            printf("Invalid input\nPlease input a range[i,j]: ");
        }
    }
}
