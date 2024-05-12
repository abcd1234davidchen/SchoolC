#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> scores;
    int s,max=0,amount=0;
    while(1){
        cin>>s;
        if(s==-1){
            break;
        }
        else{
            if(s>max) max=s;
            amount+=1;
            scores.push_back(s);
        }
    }
    vector<int> graph(max+1,0);
    for(int i=0;i<amount;i++){
        graph[scores[i]]++;
    }
    for(int i=0;i<max+1;i++){
        cout<<i<<"  ";
        for(int j=0;j<graph[i];j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
