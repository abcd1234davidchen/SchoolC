#include <iostream>
#include <vector>
using namespace std;

void fact(int n){
    vector<int> vec;
    vec.push_back(1);
    for(int i=1;i<=n;i++){
        for(size_t j=0;j<vec.size();j++){
            vec[j]*=i;
        }
        for (size_t j=0;j<vec.size();j++) {
            if (vec[j] >= 10) {
                if (vec.size()==j+1) {
                    vec.push_back(0);
                }
                vec[j+1]+=vec[j]/10;
                vec[j]%=10;
            }
        }
        cout<<i<<"!=";
        for(size_t j=vec.size();j>0;j--){
            cout<<vec[j-1];
        }
        cout<<endl;
    }
}

int main(){
    vector<int> n;
    int input;
    while(cin>>input,input!=0){
        n.push_back(input);
    }
    for(size_t i=0;i<n.size();i++){
        fact(n[i]);
        if (i!=n.size()-1)
        cout<<endl;
    }
}
