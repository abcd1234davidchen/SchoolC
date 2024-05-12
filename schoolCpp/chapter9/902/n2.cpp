#include<iostream>
#include<cctype>
using namespace std;

int main(){
    string message;
    getline(cin,message);
    for(int i=0;i<message.size();i++){
        if(isalpha(message[i])){
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base + 3) % 26 + base;
        }
        else if(isdigit(message[i])){
            message[i]=((message[i]-'0')+5)%10+'0';
        }
        else if(isspace(message[i])){
            message.erase(i,1);
            i--;
        }
        else{
            message[i]=' ';
        }
    }
    cout<<message<<endl;
}
