#include<iostream>
using namespace std;

void input(int passArr[]){
    int password;
    cin>>password;
    passArr[0]=password/10000;
    passArr[1]=password/1000%10;
    passArr[2]=password/100%10;
    passArr[3]=password/10%10;
    passArr[4]=password%10;
}

void generateNewPattern(int newArr[]){
    for(int i=0;i<=9;i++){
        newArr[i]=rand()%3+1;
    }
}

void newlyPassword(int newArr[],int passArr[]){
    for(int i=0;i<5;i++){
        passArr[i]=newArr[passArr[i]];
        //cout<<npArr[i];
    }
    
}

void render(int newArr[]){
    for(int i=0;i<10;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<newArr[i]<<" ";
    }
    cout<<endl;
}

bool compare(int passArr[],int npArr[]){
    for(int i=0;i<5;i++){
        if(passArr[i]!=npArr[i]) return false;
    }
    return true;
}

int main(){
    srand(time(0));
    int ogArr[5]={0};
    for(int i=0;i<10;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    input(ogArr);
    while(1){
        int passArr[5],newArr[10],npArr[5];
        for(int i=0;i<5;i++){
            passArr[i]=ogArr[i];
        }
        generateNewPattern(newArr);
        newlyPassword(newArr,passArr);
        render(newArr);
        input(npArr);
        if(compare(passArr,npArr)) cout<<"Correct"<<endl;
        else cout<<"Wrong"<<endl;
    }
}
