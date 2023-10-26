#include<stdio.h>
int main(void){
	int min,max,i,j,flag;
	while(scanf("%d %d",&min,&max)!=EOF){
		if(min>max||min<0||max<0){
			printf("Invalid input\n");
		}
		else{
			for(i=min;i<=max;i++){
				flag=0;
				for(j=2;j*j<i;j++){
					if(i%j==0){
						flag=1;
						break;
					}
				}
				if(flag==0){
					printf("%d\n",i);
				}
			}
		}
	}
	return 0;
}
