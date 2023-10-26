#include<stdio.h>
int main(void){
	int x1,y1,x2,y2,x3,y3,x4,y4,s1,s2,h,flag;
	float size;
	printf("Enter four points (x1 y1 x2 y2 x3 y3 x4 y4):");
	while(scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF){
		if(x1>=-1000000&&x1<=1000000&&x2>=-1000000&&x2<=1000000&&x3>=-1000000&&x3<=1000000&&x4>=-1000000&&x4<=1000000){
			if(y1>=-1000000&&y1<=1000000&&y2>=-1000000&&y2<=1000000&&y3>=-1000000&&y3<=1000000&&y4>=-1000000&&y4<=1000000){
				flag=0;
				if(x1==x2&&x3==x4){
					s1=y1-y2;
					s2=y3-y4;
					h=x1-x3;
				}
				else if(x1==x3&&x2==x4){
					s1=y1-y3;
					s2=y2-y4;
					h=x1-x2;
				}
				else if(x1==x4&&x2==x3){
					s1=y1-y4;
					s2=y2-y3;
					h=x1-x2;
				}
				else if(y1==y2&&y3==y4){
					s1=x1-x2;
					s2=x3-x4;
					h=y1-y3;
				}
				else if(y1==y3&&y2==y4){
					s1=x1-x3;
					s2=x2-x4;
					h=y1-y2;
				}
				else if(y1==y4&&y2==y3){
					s1=x1-x4;
					s2=x2-x3;
					h=y1-y2;
				}
				else{
					printf("Invalid input.\n");
					flag=1;
				}
				if(flag==0){
					if(s1<0){
						s1=0-s1;
					}
					if(s2<0){
						s2=0-s2;
					}
					if(h<0){
						h=0-h;
					}
					size=1.0*(s1+s2)*h/2;
					printf("The area of the trapezoid is: %.2lf\n",size);
				}
			}
			else{
				printf("Invalid input.\n");
			}	
		}
		else{
			printf("Invalid input.\n");
		}
		printf("Enter four points (x1 y1 x2 y2 x3 y3 x4 y4)");	
	}
	
	return 0;
}
