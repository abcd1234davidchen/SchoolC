#include <iostream>
using namespace std;
int main(){
	string ipt;
    bool first = true;
	while(getline(cin,ipt)){
        if(!first)cout<<endl;
		size_t fqc[256]={0};
		size_t maxSum = 0;
		for (size_t i=0;i<ipt.size();i++){
            if(ipt[i]>=32&&ipt[i]<=127){
                fqc[ipt[i]]+=1;
                if(fqc[ipt[i]]>maxSum){
                    maxSum = fqc[ipt[i]];
                }
            }
		}
		for (size_t i=1;i<=maxSum;i++){
			for(int j=255;j>=0;j--){
				if(fqc[j]==i){
					cout<<j<<" "<<i<<endl;
				}	
			}
		}
        first = false;
	}
}
