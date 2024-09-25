#include<iostream>
using namespace std;

int main(){
    string ipt;
    while(cin>>ipt){
        char alp1[256]={0};
        for(size_t i=0;i<ipt.size();i++){
            alp1[int(ipt[i])]++;
        }
        cin>>ipt;
        char alp2[256]={0};
        for(size_t i=0;i<ipt.size();i++){
            alp2[int(ipt[i])]++;
        }
        for(int i=0;i<256;i++){
            if (alp1[i]>alp2[i]){
                for(int j=0;j<alp2[i];j++){
                    cout<<char(i);
                }
            }
            else{
                for(int j=0;j<alp1[i];j++){
                    cout<<char(i);
                }
            }
        }
        cout<<endl;
    }
}
