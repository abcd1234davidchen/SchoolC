#include<iostream>
using namespace std;
int main(){
    int amount,sum=0;
    char score;
    cin>>amount;
    for(int i=0;i<amount;i++){
        cin>>score;
        switch (score)
        {
        case 'S':
        case 's':
            sum+=10;
            break;
        
        case 'A':
        case 'a':
            sum+=9;
            break;

        case 'B':
        case 'b':
            sum+=8;
            break;

        case 'C':
        case 'c':
            sum+=7;
            break;

        case 'D':
        case 'd':
            sum+=6;
            break;
        
        case 'E':
        case 'e':
            sum+=5;
            break;
        
        case 'F':
        case 'f':
            sum+=0;
            break;
        
        default:
            break;
        }
    }
    cout<<sum*1.0/amount;
}
