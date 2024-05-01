#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int current=0;
    //initialize
    for(int i=0;i<7;i++){
        v.push_back(i+1);
    }
    for(unsigned long i=0;i<v.size();i++){
        cout<<v[i];
    }
    cout<<endl;
    while(v.size()>1){
        current+=2;
        current%=v.size();
        v.erase(v.begin()+current);
        for(unsigned long i=0;i<v.size();i++){
            cout<<v[i];
        }
        cout<<endl;
    }
}
