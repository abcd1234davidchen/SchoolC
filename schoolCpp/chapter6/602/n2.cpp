#include<iostream>
using namespace std;

const double pi = 3.14159;

class circle{
    public:
        void input();
        void generate();
        void outArea();
        void outDiameter();
        void outCircum();
    private:
        int radius;
        double area;
        int diameter;
        double circumference;
};
void circle::input(){
    cin>>radius;
}
void circle::generate(){
    diameter=radius*2;
    area=radius*radius*pi;
    circumference=diameter*pi;
}
void circle::outArea(){
    cout<<area<<endl;
}
void circle::outDiameter(){
    cout<<diameter<<endl;
}
void circle::outCircum(){
    cout<<circumference<<endl;
}
int main(){
    circle one;
    one.input();
    one.generate();
    one.outArea();
    one.outDiameter();
    one.outCircum();
}
