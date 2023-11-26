#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main ( void ) {
    
    int i, j, k;
    int randnum[100];
    int count=0, mode, sum=0, token[50], sum_SD=0, max=0, modeCount=0, modes[50];
    float mean, median, sub, average;
    
    srand(time(NULL));
    // produce 100 randnom numbers from  closed interval [1,50]：
    for (i=0 ; i< 100; i++){
        randnum[i] = rand()%50+1;
        printf("%2d ", randnum[i]);
        if (i % 10 == 9){
            printf("\n");
        }
    }
    printf("\n");
    
    // count how many times each number repeat：
    k=1;
    while(k <= 50){
        count=0;
        for (i=0 ; i < 100; i++){
                k == randnum[i] ? count++ : 0;
        }
        printf("%2d: %2d ",k,count);
        if (k % 5 == 0){
            printf("\n");
        }
        token[k] = count; // array of how many time each number repeat in closed interval [1,50]
        k++;
    }
    printf("\n");
    
   //Find the value of mean.
    for (i=0 ;i < 100; i++){
        sum += randnum[i];
    }
    mean= sum / 100.0;
    printf("Mean: %f\n", mean);
    
    //Find the mode.
    
    for ( j = 1; j <= 50; j++) {
        if (token[j] > max) {
            max = token[j];
            modeCount = 1;
            mode = 1;
            modes[0] = j;
        }
        else if (token[j] == max) {
            modes[modeCount] = j;
            modeCount++;
        }
    }
    //There may be more than one mode.
    
    if (modeCount == 1) {
        printf("Mode: %2d\n", modes[0]);
    }
    else {
        printf("Mode: ");
        for (i = 0; i < modeCount; i++) {
            printf(" %2d ", modes[i]);
        }
        printf("\n");
    }
    
    //Find the Median.
    
    for (i = 0; i < 100-1; i++ ){
        for (j = 0; j < 100-i-1; j++){
            if (randnum[j] > randnum[j + 1] ){
                randnum[j] = randnum[j] + randnum[j + 1];
                randnum[j + 1] = randnum[j] - randnum[j + 1];
                randnum[j] = randnum[j] - randnum[j + 1];
            }
        }
    }
   
    median = (randnum[49] + randnum[50]) / 2.0;
    printf("Median: %f\n", median);
    
    //Find the standard deviation.
    
    for (i=0 ; i < 100; i++){
        sub = (randnum[i] - mean) * (randnum[i] - mean);
        sum_SD += sub;
    }
    average = sum_SD / 100.0;
    printf("Standard Deviation: %f \n",sqrt(average));
    printf(" \n ");
    
    // list out odd and even numbers
    
    count = 0;
    printf("odd: \n");
    for (i=1; i < 50; i += 2){
        if (token[i] > 0){
            for (j=0; j < token[i]; j++){
                printf("%2d ",i);
                // jump to next line every ten numbers.
                count++;
                if (count % 10==0 ){
                    printf("\n");
                }
            }
        }
    }
    
    printf("\n");
    
    count=0;
    printf("even: \n");
    for (i=0; i <= 50; i += 2){
        if (token[i] > 0){
            for (j=0; j < token[i]; j++){
                printf("%2d ",i);
                // jump to next line every ten numbers.
                count++;
                if (count % 10 == 0){
                    printf("\n");
                   // printf(" count: %d ",count);
                }
            }
        }
    }
    
    printf("\n");
    
    return  0;
}