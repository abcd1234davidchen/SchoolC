#include<iostream>
using namespace std;

class point{
    public:
        void set(int iX,int iY);
        void move();
        void rotate();
        void outX() const;
        void outY() const;
    private:
        int x;
        int y;
};

void point::set(int iX,int iY){
    x=iX;
    y=iY;
}

void point::move(){
    cin>>x>>y;
}

void point::rotate(){
    int temp;
    temp=x;
    x=y;
    y=temp*-1;
}

void point::outX() const{
    cout<<x;
}

void point::outY() const{
    cout<<y;
}

int main(){
    point one,two,three,four;
    one.set(1,2);
    two.set(2,1);
    three.set(4,3);
    four.set(6,3);
    int pn,md;
    point* chosenPoint;
    while(1){
        cin>>pn>>md;//1 2 3 4 / 1 2 3
        switch(pn){
            case 1:
                chosenPoint=&one;
                break;
            case 2:
                chosenPoint=&two;
                break;
            case 3:
                chosenPoint=&three;
                break;
            case 4:
                chosenPoint=&four;
                break;
            default:
                continue;
        }
        switch (md){
            case 1:
                chosenPoint->move();
                break;
            case 2:
                chosenPoint->rotate();
                break;
            case 3:
                chosenPoint->outX();
                cout<<",";
                chosenPoint->outY();
                cout<<endl;
                break;
            default:
                return 0;
        }
    }
    
}
