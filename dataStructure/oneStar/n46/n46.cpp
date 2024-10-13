#include <iostream>
using namespace std;

int main(){
    const char notes[14][11] = {"0110000000","0100000000","0111001111","0111001110","0111001100","0111001000","0111000000",
    "1110000000","1100000000","0010000000","1111001110","1111001100","1111001000","1111000000"};
    int n;
    cin>>n;
    string buffer;
    getline(cin,buffer);
    while(n--){
        string ipt;
        getline(cin,ipt);
        int count[10] = {0};
        char current[11]="0000000000";
        for(size_t i=0;i<ipt.size();i++){
            int index = 15;
            if(ipt[i]=='a') index = 0;
            if(ipt[i]=='b') index = 1;
            if(ipt[i]=='c') index = 2;
            if(ipt[i]=='d') index = 3;
            if(ipt[i]=='e') index = 4;
            if(ipt[i]=='f') index = 5;
            if(ipt[i]=='g') index = 6;
            if(ipt[i]=='A') index = 7;
            if(ipt[i]=='B') index = 8;
            if(ipt[i]=='C') index = 9;
            if(ipt[i]=='D') index = 10;
            if(ipt[i]=='E') index = 11;
            if(ipt[i]=='F') index = 12;
            if(ipt[i]=='G') index = 13;
            if(index==15) continue;
            for(int j=0;j<10;j++){
                if(current[j]=='0'&&notes[index][j]=='1') count[j]++;
                current[j]=notes[index][j];
            }
        }
        for(int j=0;j<10;j++){
            cout<<count[j];
            if(j!=9) cout<<" ";
        }
        cout<<endl;
    }
}
