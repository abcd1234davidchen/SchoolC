#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void hanoi(int n,char A,char B,char C,int* number){
	if(n==1){
		printf("	Move disk 1 from %c to %c\n",A,C);
		(*number)++;
		//printf("NUMBER %d\n",*number);

	}
	else{
		hanoi(n-1,A,C,B,number);
		printf("	Move disk %d from %c to %c\n",n,A,C);
		(*number)++;
		//printf("NUMBER %d\n",*number);
		hanoi(n-1,B,A,C,number);
	}
}

int main(void){
	int n;
	int number;
	printf("Enter the number of disks: ");
	while(scanf("%d",&n)!=EOF){
		printf("The sequence of moves involved in the tower of Hanoi are:\n\n");
		number=0;
		hanoi(n,'A','B','C',&number);
		printf("\n	The number of moves: %d\n\n",number);
		printf("Enter the number of disks: ");
	} 
	return 0;
}

