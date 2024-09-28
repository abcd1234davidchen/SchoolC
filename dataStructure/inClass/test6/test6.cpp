#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string *one = new string[2];
	
	one[1]="01";
	one[0]="02";
	
	sort(one,one+2);
	
	cout<<one[0]<<one[1];
}