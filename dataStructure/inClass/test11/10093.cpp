#include <iostream>
#include <vector>
using namespace std;
//0123456789
//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
//0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61
int main(){
	string c_table="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string input;
	while(cin>>input){
		int flag;
		vector<int> reverse_num;
		int input_num;
		int max;
		int N;
		int sum;
		input_num=0;
		max=0;
		sum=0;
		flag=0;
		reverse_num.clear();
		for(int i=0;i<input.size();i++){
			if(input[i]>max){
				max=input[i];
			}
		}
		for(int i=0;i<62;i++){
			if(c_table[i]==(char)max){
				N=i+1;
			}
		}
		if(N<2){
			cout<<"such number is impossible!"<<endl;
			continue;
		}
		for(int i=input.size()-1;i>=0;i--){
			for(int j=0;j<62;j++){
				if(input[i]==c_table[j]){
					reverse_num.push_back(j);
				}
			}
		}
		for(int i=0;i<reverse_num.size();i++){
			for(int j=0;j<i;j++){
				reverse_num[i]*=N;
			}
			sum+=reverse_num[i];
		}
		while(sum%(N-1)!=0){
			sum=0;
			for(int i=0;i<reverse_num.size();i++){
				for(int j=0;j<i;j++){
					reverse_num[i]/=N;
				}
			}
			N++;
			for(int i=0;i<reverse_num.size();i++){
				for(int j=0;j<i;j++){
					reverse_num[i]*=N;
				}
				sum+=reverse_num[i];
			}
			if(N>62){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"such number is impossible!"<<endl;
		}
		else{
			cout<<N<<endl;
		}
	}
}
