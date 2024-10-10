#include <iostream>
using namespace std;

int main(){
	int times;
	cin>>times;
	while(times--){
		int n;
		cin>>n;
		int nb[n];
		for(int i=0;i<n;i++){
			cin>>nb[i];
		}
		int swapN = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n-i-1;j++){
				if(nb[j]>nb[j+1]){
					swap(nb[j],nb[j+1]);
					swapN+=1;
				}
			}
		}
		cout<<"Optimal train swapping takes "<<swapN<<" swaps."<<endl;
	}
}
