#include<iostream>
using namespace std;

int generateBirthday(){
    return rand()%365;
}

bool sameBirthday(int people){
    int birthday[365]={0};
    bool same=false;
    for(int i=0;i<people;i++){
        birthday[generateBirthday()]+=1;
    }
    for(int i=0;i<365;i++){
        if(birthday[i]>1) same=true;
    }
    return same;
}

int main(){
    for(int people=2;people<=50;people++){
        int sameCount=0;
        for(int trial=0;trial<5000;trial++){
            if(sameBirthday(people)) sameCount+=1;
        }
        cout<<"For "<<people<<" people same rate is "<<sameCount*1.0/5000<<endl;
    }
}
