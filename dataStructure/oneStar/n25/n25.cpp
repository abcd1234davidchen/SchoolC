#include<iostream>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        int sm=0,base=0;
         for (int i = 0; i < s.size(); i++) {
            int temp;
            if (s[i] >= '0' && s[i] <= '9') {
                temp = s[i] - '0';
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                temp = s[i] - 'A' + 10;
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                temp = s[i] - 'a' + 36;
            }
            else {
                continue; // 忽略非數字和字母字符
            }

            sm += temp;
            if (temp > base) {
                base = temp;
            }
        }
        int flag = -1;
        for(int i=base;i<62;i++){
            if(sm%i==0){
                flag = i+1;
                break;
            }
        }
        if(flag!=-1){
            cout<<flag<<endl;
        }
        else{
            cout<<"such number is impossible!"<<endl;
        }
    }
}