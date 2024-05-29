#include<iostream>
#include<fstream>

using namespace std;

int main(){

    ifstream in1,in2;
    in1.open("one.txt");

    ofstream out;
    out.open("three.txt");

    string word;
    while(in1>>word){
        in2.open("two.txt");
        string word2;
        bool duplicate=false;
        while(in2>>word2){
            if(word==word2){
                duplicate=true;
                break;
            }
        }
        if(!duplicate){
            out<<word<<" ";
        }
        in2.close();
    }
    in1.close();
    in2.open("two.txt");
    while(in2>>word){
        in1.open("one.txt");
        string word2;
        bool duplicate=false;
        while(in1>>word2){
            if(word==word2){
                duplicate=true;
                break;
            }
        }
        if(!duplicate){
            out<<word<<" ";
        }
        in1.close();
    }
}