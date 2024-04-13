#include<iostream>
#include<cstring>
using namespace std;

void input(char input[],int num[],int& size){
    cin>>input;
    size=(int)strlen(input);
    for(int i=0;i<size;i++){
        num[size-i-1]=input[i]-'0';
    }
}

void addNum(int first[],int second[],int& size,int total[],bool&run){
    for(int i=0;i<size;i++){
        total[i]+=(first[i]+second[i]);
        if(total[i]>=10){
            if (i+1>=20){
                run =false;
                break;
            } 
            if(i==0) size+=1;
            total[i+1]=1;
            total[i]-=10;
        }
    }
}

int main(){
    int firstNum[20]={0};
    int secondNum[20]={0};
    char firstChar[20],secondChar[20];
    int firstSize,secondSize;
    input(firstChar,firstNum,firstSize);
    input(secondChar,secondNum,secondSize);
    int total[20]={0};
    int size=firstSize>secondSize?firstSize:secondSize;
    bool run=true;
    addNum(firstNum,secondNum,size,total,run);
    for(int i=0; i<size; i++){

        if(run) cout<<total[size-i-1]<<" ";
    }
}
