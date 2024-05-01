#include<iostream>
using namespace std;
class rectangle{
    private:
        double height;
        double width;
    public:
        rectangle():height(5),width(5){}
        rectangle(double h,double w):height(h),width(w){}
        void setWidth(double w){
            width=w;
        }
        void setHeight(double h){
            height=h;
        }
        double area(){
            return height*width;
        }
        void output(){
            cout<<"width "<<width<<" height "<<height<<" area "<<area();
        }
};

int main(){
    rectangle r1;
    rectangle r2(3,4);
    r1.output();
    r2.output();
}
