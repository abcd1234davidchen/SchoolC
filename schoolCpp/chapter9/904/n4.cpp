#include<iostream>
#include<cctype>
using namespace std;

int main(){
    string input;
    while(1){
        getline(cin,input);
        for(int i=0;i<input.size();i++){
            if(!isalpha(input[i-1])&&isalpha(input[i])&&isalpha(input[i+1])&&isalpha(input[i+2])&&isalpha(input[i+3])&&!isalpha(input[i+4])){
                if(isupper(input[i])){
                    cout<<"Love";
                }
                else{
                    cout<<"love";
                }
                i+=3;
            }
            else{
                cout<<input[i];
            }
        }
        cout<<endl;
    }
}
