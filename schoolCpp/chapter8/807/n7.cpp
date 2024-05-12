#include<iostream>
using namespace std;

class PrimeNumber{
    private:
        int p;
    public:
        PrimeNumber(int x):p(x){}
        PrimeNumber():p(1){}
        PrimeNumber operator++(){//++p
            bool prime=true;
            do{
                prime=true;
                p+=1;
                for(int i=2;i*i<=p;i++){
                    if((p%i)==0){
                        prime=false;
                    }
                }
            }while(!prime);
            return PrimeNumber(p);
        }
        PrimeNumber operator++(int){//p++
            int ogP=p;
            bool prime=true;
            do{
                prime=true;
                p+=1;
                for(int i=2;i*i<=p;i++){
                    if((p%i)==0){
                        prime=false;
                    }
                }
            }while(!prime);
            return PrimeNumber(ogP);
        }
        PrimeNumber operator--(){//++p
            bool prime=true;
            do{
                prime=true;
                p-=1;
                for(int i=2;i*i<=p;i++){
                    if((p%i)==0){
                        prime=false;
                    }
                }
            }while(!prime);
            return PrimeNumber(p);
        }
        PrimeNumber operator--(int){//p++
            int ogP=p;
            bool prime=true;
            do{
                prime=true;
                p-=1;
                for(int i=2;i*i<=p;i++){
                    if((p%i)==0){
                        prime=false;
                    }
                }
            }while(!prime);
            return PrimeNumber(ogP);
        }
        friend ostream& operator<<(ostream& os,PrimeNumber pM){
            os<<pM.p;
            return os;
        }
};
int main(){
    PrimeNumber P1(5);
    cout<<P1<<endl;
    cout<<P1++<<endl;
    cout<<P1<<endl;
    cout<<++P1<<endl;
    cout<<P1<<endl;
}
