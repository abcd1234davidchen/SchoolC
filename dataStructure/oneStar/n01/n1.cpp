#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

int main(){
    int nTimes;
    cin>>nTimes;
    for(int j=0;j<nTimes;j++){
        int inputTimes;
        int input;
        vector <int> home;
        int theHouse;
        int distance = 0;

        cin>>inputTimes;
        for(int i=0;i<inputTimes;i++){
            cin>>input;
            home.push_back(input);
        }   
        
        sort(home.begin(),home.end());

        theHouse = home[home.size()/2];

        for(int num:home){
            distance+=abs(theHouse-num);
        }
        cout<<distance<<endl;
    }
}
