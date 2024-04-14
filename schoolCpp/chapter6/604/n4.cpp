#include<iostream>
using namespace std;

class gasPump{
    private:
        double dispense;
        double charge;
        double pricePerGallon;
    public:
        bool done;
        void set();
        void reset();
        void add();
        void out();
};

void gasPump::set(){
    cout<<"Set price per gallon"<<endl;
    cin>>pricePerGallon;
    reset();
    cout<<"setted"<<endl;
}

void gasPump::reset(){
    dispense=0;
    charge=0;
    done=false;
}

void gasPump::add(){
    double gallon;
    cout<<"add? ";
    cin>>gallon;
    if(gallon==-1){
        done=true;
    }
    else{
        dispense+=gallon;
        charge=dispense*pricePerGallon;
    }
}

void gasPump::out(){
    cout<<dispense<<" gallon cost "<<charge<<endl;
}

int main(){
    gasPump gas;
    gas.set();
    while (1){
        while(!gas.done){
            gas.add();
            gas.out();
        }
        cout<<"Thank You"<<endl;
        gas.reset();
    }
}
