#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ifstream file;
    file.open("test.txt");
    size_t lineCount=0;
    int num;
    while(file>>num){
        lineCount++;
    }
    file.close();

    vector<int> nums;
    file.open("test.txt");
    for(size_t i=0;i<lineCount;i++){
        file>>num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());
    
    if(lineCount%2==0){
        cout<<"Median: "<<(nums[lineCount/2-1]+nums[lineCount/2])/2.0<<endl;
    }
    else{
        cout<<"Median: "<<nums[lineCount/2]<<endl;
    }

    if(lineCount%4==0){
        cout<<"Q1: "<<(nums[lineCount/4-1]+nums[lineCount/4])/2.0<<endl;
        cout<<"Q3: "<<(nums[3*lineCount/4]+nums[3*lineCount/4-1])/2.0<<endl;
    }
    else{
        cout<<"Q1: "<<nums[lineCount/4]<<endl;
        cout<<"Q3: "<<nums[(3*lineCount+1)/4]<<endl;
    }
}
