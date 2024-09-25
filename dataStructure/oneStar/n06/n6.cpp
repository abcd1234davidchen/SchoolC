#include<iostream>
#include<vector>

using namespace std;

int main(){
    string ipt;
    cin>>ipt;
    reverse(ipt.begin(),ipt.end());
    vector <int> vec;
    for(size_t i=0;i<ipt.size();i++){
        int digit = ipt[i]-'0';
        if(i==0){
            vec.push_back(digit);
        }
        else if(i==1){
            vec.back()+=10*digit;
        }
        else if((i-2)%7==0){
            vec.push_back(digit);
        }
        else if((i-2)%7==1){
            vec.push_back(digit);
        }
        else if((i-2)%7==2){
            vec.back()+=10*digit;
        }
        else if((i-2)%7==3){
            vec.push_back(digit);
        }
        else if((i-2)%7==4){
            vec.back()+=10*digit;
        }
        else if((i-2)%7==5){
            vec.push_back(digit);
        }
        else if((i-2)%7==6){
            vec.back()+=10*digit;
        }
    }
    reverse(vec.begin(),vec.end());
    string types[4] = {"s","h","l","k"};
    for(size_t i=0;i<vec.size()-1;i++){
        cout<<vec[i];
        cout<<types[(vec.size()-i+2)%4];
    }
    cout<<vec.back();
}
