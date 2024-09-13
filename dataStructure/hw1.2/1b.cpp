#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec;
    vec.push_back(1);
    for(int i=1;i<10;i++){
        for(int j=0;j<vec.size();j++){
            vec[j]*=i;
        }
        for(int j=0;j<vec.size();j++){
            if(vec.size()>(j+1)) vec.push_back(0);
            vec[j+1]+=vec[j]/10;
            vec[j]%=10;
        }
        cout<<"VEC"<<i<<endl;
        for(int j=vec.size()-1;j>=0;j--){
            cout<<vec[j];
        }
        cout<<endl<<endl;
    }
}
