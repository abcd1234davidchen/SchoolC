#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n,n!=0){
        int top=1,north=2,west=3;
        string ipt;
        while(n--){
            cin>>ipt;
            if(ipt == "north"){
                int temp = north;
                north = top;
                top = 7-temp;
            }
            else if(ipt == "west"){
                int temp = west;
                west = top;
                top = 7-temp;
            }
            else if(ipt == "south"){
                int temp = north;
                north = 7-top;
                top = temp;
            }
            else if(ipt == "east"){
                int temp = west;
                west = 7-top;
                top = temp;
            }
        }
        cout<<top<<endl;
    }
}
