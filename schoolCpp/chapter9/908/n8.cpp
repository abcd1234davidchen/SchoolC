#include<iostream>
using namespace std;

int main(){
    string in;
    while(1){
        cin>>in;
        if(in[0]=='a'||in[0]=='e'||in[0]=='i'||in[0]=='o'||in[0]=='u'){
            in=in+"way";            
        }
        else{
            string temp=in.substr(0,1);
            in.erase(0,1);
            in+=temp;
            in+="ay";
        }
        cout<<in<<endl;
    }
}
