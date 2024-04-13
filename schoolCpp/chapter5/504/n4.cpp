#include<iostream>
using namespace std;

int main(){
    char input[50];
    cin>>input;
    int size=sizeof(input)/sizeof(char);
    int vowel[5]={0};
    for(int i=0;i<size;i++){
        if(input[i]=='a'){
            vowel[0]+=1;
        }
        else if(input[i]=='e'){
            vowel[1]+=1;
        }
        else if(input[i]=='i'){
            vowel[2]+=1;
        }
        else if(input[i]=='o'){
            vowel[3]+=1;
        }
        else if(input[i]=='u'){
            vowel[4]+=1;
        }
    }
    cout<<"vowel/times"<<endl
        <<"a"<<vowel[0]<<endl
        <<"e"<<vowel[1]<<endl
        <<"i"<<vowel[2]<<endl
        <<"o"<<vowel[3]<<endl
        <<"u"<<vowel[4];
}
