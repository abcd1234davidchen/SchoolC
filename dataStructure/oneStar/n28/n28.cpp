#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n,n!=0){
        string str;
        int oneCount = 0;
        while(n>=1){
            if(n%2 == 0){
                str+='0';
            }
            else{
                str+='1';
                oneCount+=1;
            }
            n/=2;
        }
        reverse(str.begin(),str.end());
        cout<<str<<" "<<oneCount<<endl;
    }
}