#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfPrime(long long n, long long prime) {
    if (n < 1 || prime < 2) return false;
    while (n % prime == 0) {
        n /= prime;
    }
    return n == 1;
}
bool amp(long long n){
    long long prime = n;
    for(long long i=2;i*i<=n;i++){
        if((n%i)==0){
            prime = i;
        }
    }
    if(prime==n) return false;
    return (isPowerOfPrime(n,prime));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int high,low,count=0;
        cin>>low>>high;
        for(int i=low;i<=high;i++){
            if(amp(i)) count++;
        }
        cout<<count<<endl;
    }
}

