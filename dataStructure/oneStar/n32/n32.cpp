#include <iostream>
#include <vector>
using namespace std;

int main(){
    int one,two;
    while(cin>>one>>two){
        if(two == 0 || two == 1 || one == 0 || one == 1){
            cout<<"Boring!"<<endl;
            continue;
        }
        bool flag = true;
        vector <int> vec;
        while(one!=1){
            if(one%two==0){
                vec.push_back(one);
                one/=two;
            }
            else{
                cout<<"Boring!"<<endl;
                flag = false;
                break;
            }
        }
        if(flag){
            vec.push_back(1);
            for(int i=0;i<vec.size()&&flag;i++){
                if(i!=0){
                    cout<<" ";
                }
                cout<<vec[i];
            }
            cout<<endl;
        }
    }
}
