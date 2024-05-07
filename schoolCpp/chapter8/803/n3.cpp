#include <iostream>
using namespace std;

class complex{
    private:
        double real;
        double imag;//√-1
    public:
        complex(double r,double i){
            real=r;
            imag=i;
        }
        complex(){
            real=0;
            imag=0;
        }
        complex(double r){
            real=r;
            imag=0;
        }
        friend const complex operator+(const complex complex1, const complex complex2){
            return complex(complex1.real+complex2.real,complex1.imag+complex2.imag);
        }
        friend const complex operator-(const complex complex1, const complex complex2){
            return complex(complex1.real-complex2.real,complex1.imag-complex2.imag);
        }
        friend const complex operator*(const complex complex1, const complex complex2){
            return complex(complex1.real*complex2.real-complex1.imag*complex2.imag,complex1.real*complex2.imag+complex1.imag*complex2.real);
        }
        friend bool operator ==(const complex complex1, const complex complex2){
            return (complex1.real==complex2.real&&complex1.imag==complex2.imag);
        }
        friend ostream& operator<<(ostream& os, const complex& cplx){
            os<<cplx.real<<"+"<<cplx.imag<<"i";
            return os;
        }
        friend istream& operator>>(istream&is, complex& cplx){
            is>>cplx.real>>cplx.imag;
            return is;
        }
};

int main(){
    const complex i(0,1);
    complex a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    cout<<(a==b)<<endl;
}
