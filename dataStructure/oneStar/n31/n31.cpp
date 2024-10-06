#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long int gcd(long long int one, long long int two) {
    if (two == 0) return one;
    else return gcd(two, one % two);
}

int convert(string ipt){
    reverse(ipt.begin(),ipt.end());
    int rt=0;
    for(int i=0;i<ipt.size();i++){
        rt+=(ipt[i]-'0')*pow(2,i);
    }
    return rt;
}

int main() {
    string a, b;
    int times;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> a >> b;
        int one = convert(a);
        int two = convert(b);
        if (gcd(one,two) == 1) {
            cout <<"Pair #"<<i+1<< ": Love is not all you need!" << endl;
        } else {
            cout <<"Pair #"<<i+1<< ": All you need is love!" << endl;
        }
    }
    return 0;
}