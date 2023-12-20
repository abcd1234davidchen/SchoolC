#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int pascal(int n,int a){
	if(n==a){
		return 1;
	}
	if(a==1){
		return 1;
	}
	else{
		return(pascal(n-1,a)+pascal(n-1,a-1));
	}
}
int main(void){
	int layers,i,j;
	printf("Please input a layer number: ");
	while(scanf("%d",&layers)!=EOF){
		if(layers>15||layers<1){
			printf("Wrong input, input again!\n");
			printf("Please input a layer number: ");
			continue;
		} 
		for(i=1;i<=layers;i++){
			for(j=0;j<layers-i;j++){
				printf("%5c",' ');
			}
			for(j=1;j<=i;j++){
				printf("%5d%5c",pascal(i,j),' ');
			}
			printf("\n");
		}
		printf("Please input a layer number: ");
	}
	return 0;
}

