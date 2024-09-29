#include <iostream>
using namespace std;

int main(){
    int t,in;
    cin>>t;
    vector<int> ipt;
    vector<int> b;
    for(int i=0;i<t;i++){
        cin>>in;
        ipt.push_back(in);
    }
    reverse(ipt.begin(),ipt.end());
    for(size_t i=0;i<ipt.size();i++){
        for(size_t j=i;j<ipt.size();j++){
            b.push_back(ipt[i]+ipt[j]);
        }
    }
    bool flag = true;
    for(size_t i=0;i<b.size()&&flag;i++){
        for(size_t j=i+1;j<b.size();j++){
            if(b[i]==b[j]){
                //cout<<b[i];
                flag = false;
                break;
            }
        }
    }
    cout<<flag;
}
