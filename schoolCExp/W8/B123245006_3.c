#include<stdio.h>
int main(void){
	unsigned long long a,b,lcm;
	while(scanf("%d %d",&a,&b)!=EOF){
		if(a>0&&a<10000000000000&&b>0&&b<10000000000000){
			if(a>b){
				lcm=a;
			}
			else{
				lcm=b;
			}
			while(lcm%a!=0||lcm%b!=0){
				lcm+=1;
				//printf("still running");
			}
			printf("LCM of %d and %d is: %d\n",a,b,lcm);
		}
		else if(a==0&&b==0){
			printf("Finish!");
			break;
		}
		else{
			printf("Invalid\n");
		}
	}
	return 0;
}

