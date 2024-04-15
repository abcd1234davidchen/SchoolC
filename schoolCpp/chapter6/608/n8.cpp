#include<iostream>
using namespace std;

class money{
    private:
        int dollar;
        int cent;
    public:
        int getDollar(){
            return dollar;
        }
        int getCent(){
            return cent;
        }
        void mutator(int x,int y){
            dollar=x;
            cent=y;
        }
        void inDollar(){
            cin>>dollar;
        }
        void inCent(){
            cin>>cent;
        }
        double getTotal(){
            return getDollar()*1.0+getCent()*1.0/100;
        }
};

int main(){
    money money1,money2;
    money1.mutator(3,2);
    money2.mutator(6,4);
    money* chosenMoney;
    int choose;
    while(1){
        cout<<"select your target 1/2 ";
        cin>>choose;
        if(choose==1){
            chosenMoney=&money1;
            cout<<chosenMoney->getTotal()<<endl;
        }
        else if(choose==2){
            chosenMoney=&money2;
            cout<<chosenMoney->getTotal()<<endl;
        }
        else{
            continue;
        }

        cout<<"Input new dollar or cent ";
        cin>>choose;
        if(choose==1){
            chosenMoney->inDollar();
            cout<<chosenMoney->getTotal()<<endl;
        }
        else if(choose==2){
            chosenMoney->inCent();
            cout<<chosenMoney->getTotal()<<endl;
        }
        else{
            continue;
        }
    }
}
