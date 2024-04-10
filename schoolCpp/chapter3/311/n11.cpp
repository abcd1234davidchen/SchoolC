#include<iostream>
using namespace std;

int dice(){
    return rand()%5+1;
}

int humanTurn(int humanTotalScore){
    int roll,gain=0;
    char ans;
    bool cont;
    while(1){
        roll=dice();
        if(roll==1){
            cout<<"DAMN";
            return humanTotalScore;
        }
        else{
            gain+=roll;
            while(1){
                cout<<"Roll"<<roll<<"Gain"<<gain<<endl;
                cin>>ans;
                if(ans=='r'){
                    cont=true;
                    break;
                }
                else if(ans=='h'){
                    cont=false;
                    break;
                }
                else continue;
            }
            if(!cont) return humanTotalScore+=gain;
        }
    }
}

int autoHuman(int humanTotalScore){
    int roll,gain=0;
    while(1){
        roll=dice();
        if(roll==1){
            return humanTotalScore;
        }
        else{
            gain+=roll;
            if(roll>4){
                return humanTotalScore+gain;
            }
        }
    }
}

int computerTurn(int computerTotalScore){
    int roll,gain=0;
    while(1){
        roll=dice();
        if(roll==1){
            return computerTotalScore;
        }
        else{
            gain+=roll;
            if(gain>20){
                return computerTotalScore+gain;
            }
        }
    }
}


int main(){
    srand(time(0));
    int man=0,comp=0;
    bool manWin;
    while(1){
        cout<<"MAN TURN"<<endl;
        man=autoHuman(man);
        cout<<man<<endl;
        if(man>100){
            manWin=true;
            break;
        }
        cout<<"COMPUTER TURN"<<endl;
        comp=computerTurn(comp);
        cout<<comp<<endl;
        if(comp>100){
            manWin=false;
            break;
        }
    }
    if(manWin){
        cout<<"MAN"<<endl;
    }
    else{
        cout<<"COMPUTER"<<endl;
    }
}
