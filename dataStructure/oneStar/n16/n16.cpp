#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){
    int times;
    cin>>times;
    for(int i=0;i<times;i++){
        int n;
        double p,chance;
        int k;

        cin>>n>>p>>k;
        chance = (p==0) ? 0:pow(1-p,k-1)*p/(1-pow((1-p),n));

        cout<<fixed<<setprecision(4)<<chance<<endl;
    }
}
