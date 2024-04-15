#include<iostream>
using namespace std;

class speedometer{
    private:
        double time;
        double distance;
        double speed;
    public:
        void input(){
            cout<<"Input minute and miles ";
            cin>>time>>distance;
        }
        void conversion(){
            speed=1.0*distance/time*60;
        }
        void output(){
            conversion();
            cout<<speed<<"mph"<<endl;
        }
};

int main(){
    speedometer bike;
    while (1){
        bike.input();
        bike.output();    
    }
}
