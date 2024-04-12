#include<iostream>
using namespace std;

int randDoor(){
    return rand()%3+1;
}

bool win(bool& userSwap){
    int priceDoor=randDoor(),pickDoor=randDoor();
    int openDoor=randDoor();
    //open door
    bool niceSwap;
    if(priceDoor==pickDoor){
        while(openDoor==pickDoor){
            openDoor=randDoor();
        }
        cout<<openDoor<<" is open"<<endl;
        niceSwap=false;
    }
    else{
        cout<<6-priceDoor-pickDoor<<" is open"<<endl;
        niceSwap=true;
    }
    //switch
    userSwap=rand()%2;
    if(niceSwap==userSwap){
        cout<<"WON"<<endl;
        return true;
    }
    else{
        cout<<"LOSE"<<endl;
        return false;
    }
}

int main(){
    srand(time(0));
    bool userSwap;
    int winSwap=0,winNoSwap=0,loseSwap=0,loseNoSwap=0;

    for(int i=0;i<10000;i++){
        if(win(userSwap)){
            if(userSwap) winSwap+=1;
            else winNoSwap+=1;
        }
        else{
            if(userSwap) loseSwap+=1;
            else loseNoSwap+=1;
        }
    }
    cout<<"From Swapping: "<<winSwap<<" win "<<loseSwap<<" lose"<<endl
        <<"From No Swapping "<<winNoSwap<<" win "<<loseNoSwap<<" lose";

}
