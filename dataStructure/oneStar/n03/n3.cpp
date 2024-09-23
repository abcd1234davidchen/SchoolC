#include<iostream>
#include<vector>

using namespace std;

int main(){
    int one;
    int two;

    while(cin>>one>>two,(one!=0||two!=0)){
        vector <int> vec1;
        vector <int> vec2;
        vector <int> newVec;
        int carryInt = 0;
        while(one>0){
            vec1.push_back(one%10);
            one/=10;
        }
        while(two>0){
            vec2.push_back(two%10);
            two/=10;
        }

        if (vec1.size()>vec2.size()){
            for(size_t i=0;i<vec1.size();i++){
                if(i<vec2.size()) newVec.push_back(vec1[i]+vec2[i]);
                else newVec.push_back(vec1[i]);
            }
        }
        else{
            for(size_t i=0;i<vec2.size();i++){
                if(i<vec1.size()) newVec.push_back(vec1[i]+vec2[i]);
                else newVec.push_back(vec2[i]);
            }
        }
        newVec.push_back(0);
        for(size_t i=0;i<newVec.size();i++){
            if(newVec[i]>=10){
                newVec[i+1]+=1;
                carryInt+=1;
            }
        }
        if (carryInt==0){
            cout<<"No carry operation."<<endl;
        }
        else if (carryInt==1){
            cout<<"1 carry operation."<<endl;
        }
        else{
            cout<<carryInt<<" carry operations."<<endl;
        }
    }
}