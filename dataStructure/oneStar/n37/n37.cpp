#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int s;
    double a;
    string d;
    while(cin>>s>>a>>d){
        s+=6440;
        double arc,chord;
        if(d=="min") a/=60.0;
        if (a > 180) a = abs(360 - a);
        double rad = M_PI / 180.0 * a;
        arc = s*rad;
        chord = 2*s*sin(rad/2);
        cout<<fixed<<setprecision(6)<<arc<<" "<<chord<<endl;
    }
}
