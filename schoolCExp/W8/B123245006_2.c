#include<stdio.h>
int main(void){
	int in,i,j,x,ogin;
	while(scanf("%d",&in)!=EOF){
		if(in>0&&in%2==1){
			ogin=in;
			x=in/2+1;
			for(i=0;i<x;i+=1){
				for(j=0;j<i;j++){
					printf(" ");
				}
				for(j=0;j<in;j++){
					printf("*");
				}
				in-=2;
				printf("\n");
			}
			for(i=1;i<x;i+=1){
				for(j=0;j<(x-i)-1;j++){
					printf(" ");
				}
				for(j=0;j<2*i+1;j++){
					printf("*");
				}
				printf("\n");
			}
		}
		else if(in==0){
			printf("Finish!");
			break;
		}
		else{
			printf("Please input a valid number.\n");
		}
	}
	return 0;
}

