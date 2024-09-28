#include<iostream>
#include<vector>
using namespace std;

int main(){
    string ipt;
    vector <string> vec;
    size_t maxSen = 0;
    while(getline(cin,ipt)){
        vec.push_back(ipt);
        if (ipt.size()>maxSen){
            maxSen = ipt.size();
        }
    }
    //cout<<"MAX"<<maxSen;
    for(size_t i=0;i<maxSen;i++){
        for(size_t j=vec.size();j>0;j--){
            if (i<vec[j-1].size()){
                cout<<vec[j-1][i];
            }
            else{
                cout<<' ';
            }
        }
        cout<<endl;
    }
    
}