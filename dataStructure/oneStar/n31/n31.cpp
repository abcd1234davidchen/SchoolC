#include <iostream>
using namespace std;

long long int gcd(long long int one, long long int two) {
    if (one == 0) return two;
    else return gcd(two, one % two);
}

int main() {
    long long int a, b;
    int times;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> a >> b;
        if (gcd(a, b) == 1) {
            cout << "NO" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}