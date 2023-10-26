#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    int x[5],in,ans[5],a=0,b=0;

    //random number
    srand(time(NULL));
    for (int i=0;i<4;i++){
        x[i]=rand()%10;
        for (int j=0;j<i;j++){
            while(x[i]==x[j]){
                x[i]=rand()%10;
            }
        }
    }

    for (int h = 0; h < 10; h++) {
        //split
        printf("input four different number:(例如2178): ");
        scanf("%d",&in);
        ans[0]=in/1000;
        ans[1]=in/100%10;
        ans[2]=in/10%10;
        ans[3]=in%10;

        //compare
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                if (ans[i]==x[j]){
                    b+=1;
                    if(i==j){
                        a+=1;
                        b-=1;
                    }
                }
            }
        }
        printf("結果： %dA%dB,還有%d次機會...\n",a,b,9-h);

        //break
        if (a==4){
            h=100;
        }
        else{
            a=0;
            b=0;
        }
    }
    if (a==4){
        printf("您猜對了");
    }
    else{
        printf("答案是%d%d%d%d",x[0],x[1],x[2],x[3]);
    }
    
}
