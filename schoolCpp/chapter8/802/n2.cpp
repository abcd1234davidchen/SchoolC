#include<iostream>
using namespace std;

class Rational{
    private:
        int numerator;
        int denomenator;//n/d
    public:
        Rational(int n,int d){
            numerator=n;
            denomenator=d;
        }
        Rational(){
            numerator=0;
            denomenator=1;
        }
        Rational(int w){
            numerator=w;
            denomenator=1;
        }
        void normalize() {
            int n = numerator, d = denomenator, temp;
            while (d != 0) {
                temp = n % d;
                n = d;
                d = temp;
            }
            numerator /= n;
            denomenator /= n;
        }
        friend const Rational operator +(const Rational& r1,const Rational& r2){
            int n,d;
            n=r1.numerator*r2.denomenator+r2.numerator*r1.denomenator;
            d=r1.denomenator*r2.denomenator;
            Rational r(n,d);
            r.normalize();
            return r;
        }
        friend const Rational operator -(const Rational& r1,const Rational& r2){
            int n,d;
            n=r1.numerator*r2.denomenator-r2.numerator*r1.denomenator;
            d=r1.denomenator*r2.denomenator;
            Rational r(n,d);
            r.normalize();
            return r;
        }
        friend const Rational operator *(const Rational& r1,const Rational& r2){
            int n,d;
            n=r1.numerator*r2.numerator;
            d=r1.denomenator*r2.denomenator;
            Rational r(n,d);
            r.normalize();
            return r;
        }
        friend const Rational operator /(const Rational& r1,const Rational& r2){
            int n,d;
            n=r1.numerator*r2.denomenator;
            d=r1.denomenator*r2.numerator;
            Rational r(n,d);
            r.normalize();
            return r;
        }
        friend bool operator ==(const Rational& r1,const Rational& r2){
            if(r1.numerator==r2.numerator&&r1.denomenator==r2.denomenator){
                return true;
            }
            return false;
        }
        friend bool operator <(const Rational& r1,const Rational& r2){
            if(r1.numerator*r2.denomenator<r2.numerator*r1.denomenator){
                return true;
            }
            return false;
        }
        friend bool operator >(const Rational& r1,const Rational& r2){
            if(r1.numerator*r2.denomenator>r2.numerator*r1.denomenator){
                return true;
            }
            return false;
        }
        friend bool operator <=(const Rational& r1,const Rational& r2){
            if(r1.numerator*r2.denomenator<=r2.numerator*r1.denomenator){
                return true;
            }
            return false;
        }
        friend bool operator >=(const Rational& r1,const Rational& r2){
            if(r1.numerator*r2.denomenator>=r2.numerator*r1.denomenator){
                return true;
            }
            return false;
        }
        friend ostream& operator <<(ostream& os,const Rational& r){
            os<<r.numerator<<"/"<<r.denomenator;
            return os;
        }
        friend istream& operator >>(istream& is,Rational& r){
            is>>r.numerator>>r.denomenator;
            return is;
        }
        
};

int main(){
    Rational r1,r2;
    cin>>r1>>r2;
    cout<<r1+r2<<endl;
    cout<<r1-r2<<endl;
    cout<<r1*r2<<endl;
    cout<<r1/r2<<endl;
    cout<<(r1==r2)<<endl;
    cout<<(r1<r2)<<endl;
    cout<<(r1>r2)<<endl;
    cout<<(r1<=r2)<<endl;
    cout<<(r1>=r2)<<endl;
    return 0;
}
