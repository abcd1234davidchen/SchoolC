#include<iostream>
using namespace std;

class fraction{
    private:
        int denominator;
        int numerator;
        double doub;
    public:
        void calc(){
            doub=1.0*numerator/denominator;
        };
        void mutator(){
            cin>>numerator>>denominator;
        };
        int gcd(){
            int one=denominator,two=numerator,temp;
            while(two!=0){
                temp=two;
                two=one%two;
                one=temp;
            }
            return one;
        };
        void reduce(){
            cout<<numerator/gcd()<<"/"<<denominator/gcd()<<endl;
        };
        void output(){
            reduce();
            calc();
            cout<<"Double is "<<doub;
        }
        
};

int main(){
    fraction frac;
    frac.mutator();
    frac.output();
}
