#include<iostream>
#include<cctype>
using namespace std;

int main(){
    string in;
    while(1){
        getline(cin,in);
        unsigned long size=in.size();
        in[0]=toupper(in[0]);
        for(unsigned int i=1;i<size;i++){
            in[i]=tolower(in[i]);
            if(in[i+1]==' '&&in[i]==' '){
                in.erase(i,1);
            }
            size-=1;
        }
        cout<<in<<endl;
    }
}
