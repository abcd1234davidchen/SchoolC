#include<iostream>
using namespace std;

class pizza{
    private:
        int size;
        int type;
        int toppings;
        int price;
    public:
        void outputDescription(){
            cout<<"Small pizza = $10 + $2 per topping"<<endl
                <<"Medium pizza = $14 + $2 per topping"<<endl
                <<"Large pizza = $17 + $2 per topping"<<endl;
        }
        void chooseType(){
            cout<<"1.Deep Dish 2.Hand Tossed 3.Pan ";
            cin>>type;
            type-=1;
        }
        void chooseSize(){
            cout<<"1.Small 2.Medium 3.Large ";
            cin>>size;
            size-=1;
        };
        void chooseTopping(){
            cout<<"Input amount of toppings ";
            cin>>toppings;
        }
        void compute(){
            switch(size){
                case 0:
                    price=10;
                    break;
                case 1:
                    price=14;
                    break;
                case 2:
                    price=17;
                    break;
            }
            price+=2*toppings;
        }
        void output(){
            char typePizza[3][12]={"Deep dish","Hand tossed","Pan"};
            char sizePizza[3][12]={"Small","Medium","Large"};
            cout<<"Your pizza is "<<sizePizza[size]<<" "<<typePizza[type]<<", price is "<<price;
        };
};

int main(){
    pizza one;
    one.outputDescription();
    one.chooseType();
    one.chooseSize();
    one.chooseTopping();
    one.compute();
    one.output();
}
