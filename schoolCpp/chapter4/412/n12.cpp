#include<iostream>
using namespace std;

bool alive(int i){
    int chance=rand()%i;
    if(chance==0){
        return false;
    }
    else{
        return true;
    }
}

int winner(){
//1 1/3 for Aaron 2 1/2 for Bob 3 1 for Charlie
    bool aaron=true,bob=true,charlie=true;
    while(1){
        if(aaron){
            if(charlie){
                charlie=alive(3);
            }
            else if(bob){
                bob=alive(3);
            }
            else{
                return 1;
            }
        }
        if(bob){
            if(charlie){
                charlie=alive(2);
            }
            else if(aaron){
                aaron=alive(2);
            }
            else{
                return 2;
            }
        }
        if(charlie){
            if(bob){
                bob=false;
            }
            else if(aaron){
                aaron=false;
            }
            else{
                return 3;
            }
        }
    }
}

int missAaronWinner(){
    bool aaron=true,bob=true,charlie=true;
    while(1){
        if(bob){
            if(charlie){
                charlie=alive(2);
            }
            else if(aaron){
                aaron=alive(2);
            }
            else{
                return 2;
            }
        }
        if(charlie){
            if(bob){
                bob=false;
            }
            else if(aaron){
                aaron=false;
            }
            else{
                return 3;
            }
        }
        if(aaron){
            if(charlie){
                charlie=alive(3);
            }
            else if(bob){
                bob=alive(3);
            }
            else{
                return 1;
            }
        }
    }
}

int main(){
    srand(time(0));
    int theOne;
    int alive[3]={0};
    for(int i=0;i<10000;i++){
        theOne=winner()-1;
        alive[theOne]+=1;
    }
    char winnerName[3][10]={"Aaron","Bob","Charlie"};
    for(int i=0;i<3;i++){
        cout<<winnerName[i]<<" won "<<alive[i]<<" times "<<endl;
    }

    cout<<"change of plan"<<endl;
    alive[0]=0;
    alive[1]=0;
    alive[2]=0;
    for(int i=0;i<10000;i++){
        theOne=missAaronWinner()-1;
        alive[theOne]+=1;
    }
    for(int i=0;i<3;i++){
        cout<<winnerName[i]<<" won "<<alive[i]<<" times "<<endl;
    }
}
