#include <iostream>
using namespace std;

int main(){
    int n,count;
    cin>>count;
    for(int i=0;i<count;i++){
        cin>>n;
        int decTemp = n,hexTemp = n,decCount = 0,hexCount = 0;
        while(decTemp>=1){
            decCount+=decTemp%2;
            decTemp/=2;
        }
        while (hexTemp>0){
            int temp = hexTemp %10;
            //cout<<"TEMP"<<temp;
            while(temp>=1){
                hexCount+=temp%2;
                temp/=2;
            }
            hexTemp/=10;
        }
        cout<<decCount<<" "<<hexCount<<endl;
    }
}
