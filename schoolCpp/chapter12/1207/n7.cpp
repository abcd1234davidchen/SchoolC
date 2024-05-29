#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream inMail;
    ofstream outMail;
    outMail.open("send.txt");
    ifstream can;
    can.open("candidate.txt");
    string word,email,date,location;
    cin>>email>>date>>location;
    string people;
    while(can>>people){
        cout<<people<<endl;
        inMail.open("email.txt");
        while(inMail>>word){
            if(word=="<name>"){
                word=people;
            }
            if(word=="<email>"){
                word=email;
            }
            if(word=="<date>"){
                word=date;
            }
            if(word=="<location>"){
                word=location;
            }
            outMail<<word<<" ";
        }
        inMail.close();
        outMail<<endl<<endl;
    }
    outMail.close();
}
