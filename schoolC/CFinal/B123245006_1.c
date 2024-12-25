#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int GCD(int a,int b){
	if (b==0) return a;
	else return GCD(b,a%b);
}

int main(void){
	FILE* input=fopen("GCD.txt","r");
	int a,b;
	while(fscanf(input,"%d %d",&a,&b)!=EOF){
		printf("GCD of (%d, %d) is %d.\n",a,b,GCD(a,b));
	}
	fclose(input);
}

