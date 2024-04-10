#include<iostream>
using namespace std;

int dice(){
    int ttl=0;
    ttl+=rand()%6+1;
    ttl+=rand()%6+1;
    return ttl;
}

int main(){
    int win=0,lose=0,point,nextRoll;
    srand(time(0));
    for(int i=0;i<10000;i++){
        //one round
        int firstRoll = dice(); 
        //cout<<"First roll is"<<firstRoll<<endl;
        if(firstRoll==7||firstRoll==11){
            win+=1;
            cout<<"WIN"<<endl;
        }
        else if(firstRoll==2||firstRoll==3||firstRoll==12){
            lose+=1;
            cout<<"LOSE"<<endl;
        }
        else{
            point=firstRoll;
            while(1){
                nextRoll=dice();
                //cout<<"nextRolled"<<nextRoll<<endl;
                if(nextRoll==point){
                    win+=1;
                    cout<<"WIN"<<endl;
                    break;
                }
                else if(nextRoll==7){
                    lose+=1;
                    cout<<"LOSE"<<endl;
                    break;
                }
            }
        }
    }
    cout<<"win"<<win<<"lose"<<lose<<endl<<1.0*win/(win+lose)*100<<"%"<<endl;
}
