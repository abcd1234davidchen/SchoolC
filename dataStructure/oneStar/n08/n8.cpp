#include<iostream>
using namespace std;

int main(){
    int alp[26]={0};
    string ipt;
    cin>>ipt;
    for(size_t i=0;i<ipt.size();i++){
        if(ipt[i]<='z' && ipt[i]>='a'){
            alp[ipt[i]-'a']+=1;
        }
        else if(ipt[i]<='Z' && ipt[i]>='A'){
            alp[ipt[i]-'A']+=1;
        }
    }


    int mx = 0;
    for (int i = 0; i < 26; i++) {
        if (alp[mx] < alp[i]) {
            mx = i;
        }
    }
    mx = alp[mx];

    for (int i = mx; i > 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (alp[j] == i) {
                cout << char('A' + j);
            }
        }
        cout << endl;
    }
}