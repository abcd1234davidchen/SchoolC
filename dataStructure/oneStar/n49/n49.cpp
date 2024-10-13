#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n,mod;
bool compare(int one,int two){
    int oneMod = one%mod,twoMod = two%mod;
    if(oneMod!=twoMod){
        return oneMod<twoMod;
    }
    else{
        int op2=abs(one%2),tp2=abs(two%2);
        if(op2==0&&tp2==0){
            return one<two;
        }
        else if(op2==1&&tp2==0){    
            return true;             
        }
        else if(op2==0&&tp2==1){
            return false;
        }
        else if(op2==1&&tp2==1){
            return one>two;
        }
    }

}

int main(){
    int arr[10001];
    while(cin>>n>>mod,n!=0||mod!=0){
        cout<<n<<" "<<mod<<endl;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arr[i] = temp;
        }
        sort(arr,arr+n,compare);
        for(int i=0;i<n;i++) cout<<arr[i]<<endl;
    }
    cout<<"0 0"<<endl;
}