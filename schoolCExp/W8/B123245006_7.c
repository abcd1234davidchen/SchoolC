#include<stdio.h>
int main(void){
	int x,count=0,num;
	while(scanf("%d",&x)!=EOF){
		count+=1;
		switch (count){
			case 1: 
				num=x;
				printf("(State RST)=>%d\n",num);
			break;
			case 2: 
				num+=x;
				printf("(State ADD)=>%d\n",num);
			break;
			case 3: 
				num-=x;
				printf("(State SUB)=>%d\n",num);
			break;
			case 4:
				num*=x;
				printf("(State MUL)=>%d\n",num);
			break;	 
			case 5: 
				if(num==0){
					printf("(State DIV)=>division by zero=>reset\n");
					count=0;
				}
				else{
					num=x/num;
					printf("(State DIV)=>%d\n",num);
					count=1;	
				}
			break;
		}
	} 
	return 0;
}

