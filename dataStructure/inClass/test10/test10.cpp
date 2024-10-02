#include <iostream>
using namespace std;

int main(){
    int** a = new int* [2];
    for(int i=0;i<2;i++){
        a[i] = new int[3];
    }
}