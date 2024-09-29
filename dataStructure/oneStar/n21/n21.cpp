#include<iostream>
using namespace std;

int main(){
    int matSize,temp;
    cin>>matSize;
    vector <int> vec;
    for(int i=0;i<matSize*matSize;i++){
        cin>>temp;
        vec.push_back(temp);
    }
    vector<int> og;
    og = vec;
    reverse(vec.begin(),vec.end());
    cout<<(vec==og);
}
