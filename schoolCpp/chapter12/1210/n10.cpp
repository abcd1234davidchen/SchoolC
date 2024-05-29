#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream in;
    in.open("input.txt");
    int count = 0,num = 0;
    string word;
    while(in>>word){
        count++;
        num+=word.size();
        if(!isalpha(word[0])){
            num--;
        }
        if(!isalpha(word[word.size()-1])){
            num--;
        }
    }
    cout<<"average length of words: "<<(double)num/count<<endl;
}
