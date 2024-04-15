#include<iostream>
using namespace std;

class money{
    private:
        double total;
    public:
        int getDollar(){
            return (int)total;
        }
        double getCent(){
            return total-getDollar();
        }
        void mutator(double x){
            total=x;
        }
        void inDollar(){
            int x;
            cin>>x;
            total=x+1.0*getCent();
        }
        void inCent(){
            int x;
            cin>>x;
            total=getDollar()+x*1.0/100;
        }
        double getTotal(){
            return total;
        }
};

int main(){
    money money1,money2;
    money1.mutator(3.2);
    money2.mutator(6.4);
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
