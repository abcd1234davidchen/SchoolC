#include<iostream>
#include<cstdlib>
#include<cmath>
class money{
    private:
        int cent,dollar;
    public:
        money(){
            cent=0;dollar=0;
        }
        money(int d,int c){
            dollar=d;cent=c;
        }
        money(int d){
            dollar=d;
        }
        money(double m){
            dollar=(int)m;
            cent=(m-dollar)*100;
        }
        const money operator +(const money& money2){
            int c,d;
            c = cent + money2.cent;
            d = dollar + money2.dollar;
            if(c < 0){
                c += 100;
                d -= 1;
            }
            return money(d,c);
        }
        friend const money operator -(const money& money1, const money& money2){
            int c,d;
            c = money1.cent - money2.cent;
            d = money1.dollar - money2.dollar;
            if(c < 0){
                c += 100;
                d -= 1;
            }
            return money(d,c);
        }
        friend bool operator == (const money& money1, const money& money2){
            if(money1.cent==money2.cent&&money1.dollar==money2.dollar){
                return true;
            }
            return false;
        }
        const money operator-() const {
            return money(-dollar, -cent);
        }
};