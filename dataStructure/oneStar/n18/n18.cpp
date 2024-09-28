#include<iostream>
using namespace std;

int main(){
    int x,ans=0;
    bool neg;
    string ipt,buffer;
    vector<int> pol;
    pol.push_back(0);
    cin>>x;
    getline(cin,buffer);
    getline(cin,ipt);
    for(size_t i=0;i<ipt.size();i++){
        if(ipt[i]==' '){
            pol.push_back(0);
            neg = false;
        }
        else if(ipt[i] == '-'){
            neg = true;
        }
        else if(neg){
            pol.back()-=(ipt[i]-'0');
        }
        else{
            pol.back()*=10;
            pol.back()+=(ipt[i]-'0');
        }
    }
    pol.pop_back();
    reverse(pol.begin(),pol.end());
    int size = static_cast<int>(pol.size());
    for(int i=0;i<size;i++){
        ans+=int(pow(x,i))*pol[size_t(i)]*(i+1);
    }
    cout<<ans;
}
