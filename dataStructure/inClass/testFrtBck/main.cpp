#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(0));
    int set = 7;
    int* a = new int[set];
    for(int i=0;i<set;i++) a[i]=rand()%20;
    sort(a,a+set);
    reverse(a,a+set);
    for(int i=0;i<set;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<set/2;i++){
        cout<<a[i]<<" ";
        cout<<a[set-1-i]<<" ";
    }
    if(set%2==1) cout<<a[set/2];
}