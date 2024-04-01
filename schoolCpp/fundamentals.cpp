/*
Comment...
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int add(int n) {
    return (n>0)?n+add(n-1):0;
}
int main() {
    srand(time(0));
    int first,second,n;
    cin >> n;
//    cin >> first >>second;
//    cout << ((first>second)?first:second) << endl;
    cout << add(n) << endl;
    return 0;
}

/* 
    5+add(4)=15
        4+add(3)=10
            3+add(2)=6
                2+add(1)=3
                    1+add(0)=1
    0
    */