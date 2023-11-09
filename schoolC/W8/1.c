#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main(void){
//hw1
    srand(time(NULL));
    int generate[100],freq[101]={0},order[101];
    int temp,mode;
    double mean=0,median=0,n=0;

    for (int i=0;i<100;i++){
        generate[i]=rand()%50+1;
        mean+=generate[i];
        freq[generate[i]]++;
        order[i]=generate[i];
    }

//    order
    for(int i=0;i<100;i++){
        for(int j=i;j<100;j++){
            if(order[i]>order[j]){
                order[i]=(order[i]*order[j])/(order[j]=order[i]);
            }
        }
    }

//    print generate
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            temp=i*10+j;
            printf("%3d",generate[temp]);
        }
        printf("\n");
    }
    printf("\n");

//    print frequency
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            temp=i*5+j+1;
            printf("%3d:%2d",temp,freq[temp]);
        }
        printf("\n");
    }
    printf("\n");

//    means and others
    mean/=100;
    printf("\nMean: %f\n",mean);
    
    mode=0;
    for(int i=0;i<50;i++){
        if(freq[i]>freq[mode]){
            mode=i;
        }
    }
    printf("Mode: %2d\n",mode);

    median=(order[50]+order[51])/2;
    printf("Median: %.2f\n",median);

    for(int i=0;i<50;i++){
        n+=(generate[i]-mean)*(generate[i]-mean);
    }
    n/=100;
    n=sqrt(n);
    printf("Standard Deviation: %f\n\n",n);

//hw2
    int odd[100]={0},even[100]={0};
    int oddn=0,evenn=0;
    for(int i=0;i<100;i++){
        if(order[i]%2==1){
            odd[oddn]=order[i];
            oddn+=1;
        }
        else{
            even[evenn]=order[i];
            evenn+=1;
        }
    }


    printf("odd\n");
    for(int i=0;i<oddn;i++){
        printf("%3d",odd[i]);
        if((i+1)%10==0){
            printf("\n");
        }
    }
    printf("\n");

    printf("even\n");
    for(int i=0;i<evenn;i++){
        printf("%3d",even[i]);
        if((i+1)%10==0){
            printf("\n");
        }
    }
    printf("\n");
}
