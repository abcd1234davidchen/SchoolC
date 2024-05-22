#include<iostream>
using namespace std;

class polynominal{
    private:
        double* coef;
        int max;
    public:
        polynominal():coef(nullptr),max(0){}

        polynominal(int x):max(x){
            coef=new double[max+1]();
        }

        polynominal(const polynominal& p):max(p.max){
            coef = new double[max+1];
            std::copy(p.coef, p.coef+max+1, coef);
        }

        ~polynominal(){
            delete[] coef;
        }

        void set(int i,double value){
            coef[i]=value;
        }
        
        double get(int i) const{
            return coef[i];
        }

        const polynominal operator+(const polynominal& other)const{
            int rMax = max > other.max ? max : other.max;
            polynominal result(rMax);
            for(int i = 0; i <= rMax; i++){
                double value = 0;
                if(i <= max) value += coef[i];
                if(i <= other.max) value += other.coef[i];
                result.set(i, value);
            }
            return result;
        }

        const polynominal operator-(const polynominal& other)const{
            int rMax = max > other.max ? max : other.max;
            polynominal result(rMax);
            for(int i = 0; i <= rMax; i++){
                double value = 0;
                if(i <= max) value += coef[i];
                if(i <= other.max) value -= other.coef[i];
                result.set(i, value);
            }
            return result;
        }

        polynominal operator*(const polynominal& other) const {
            int rMax = max + other.max;
            polynominal result(rMax);
            for (int i = 0; i <= max; i++) {
                for (int j = 0; j <= other.max; j++) {
                    result.coef[i + j] += coef[i] * other.coef[j];
                }
            }
            return result;
        }

        polynominal& operator=(const polynominal& other) {
            if (this != &other) {
                delete[] coef;
                max = other.max;
                coef = new double[max+1];
                copy(coef,coef + max + 1, other.coef);
            }
            return *this;
        }

        double evaluate(const double x){
            double result=coef[0];
            for(int i=1;i<=max;i++){
                double add=1;
                for(int j=0;j<i;j++){
                    add*=x;
                }
                result+=coef[i]*add;
            }
            return result;
        }

        polynominal operator+(double c) const {
            polynominal result(*this);
            result.coef[0] += c;
            return result;
        }

        polynominal operator-(double c) const {
            polynominal result(*this);
            result.coef[0] -= c;
            return result;
        }

        polynominal operator*(double c) const {
            polynominal result(*this);
            for (int i = 0; i <= max; i++) {
                result.coef[i] *= c;
            }
            return result;
        }

        friend polynominal operator+(const double c, const polynominal& p) {
            polynominal result(p);
            result.coef[0] += c;
            return result;
        }

        friend polynominal operator-(const double c, const polynominal& p) {
            polynominal result(p);
            result.coef[0]-=c;
            for (int i = 0; i <= result.max; i++) {
                result.coef[i] = 0 - result.coef[i];
            }
            return result;
        }

        friend polynominal operator*(const double c, const polynominal& p) {
            polynominal result(p);
            for (int i = 0; i <= result.max; i++) {
                result.coef[i] *= c;
            }
            return result;
        }

        friend ostream& operator<<(ostream& os, const polynominal& p) {
            for(int i = p.max; i >= 0; i--){
                if(i != p.max) os << " + ";
                os << p.coef[i] << "x^" << i;
            }
            return os;
        }
};

int main(){
    polynominal p1(0),p2(1);
    p1.set(0,1);
    p2.set(1,2);
    cout<<p1<<endl;
    cout<<p2<<endl<<endl;

    cout<<p1+p2<<endl;
    cout<<p1-p2<<endl;
    cout<<p1*p2<<endl<<endl;

    cout<<p1<<endl;
    cout<<p2<<endl<<endl;

    cout<<p1+2.0<<endl;
    cout<<p1-2.0<<endl;
    cout<<p1*2<<endl<<endl;

    cout<<2+p2<<endl;
    cout<<2-p2<<endl;
    cout<<2*p2<<endl;
}
