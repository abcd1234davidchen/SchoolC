#include <iostream>
using namespace std;


void twoway(int* a, int* b, int* c, int n1, int n2){
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }
    while(i < n1){
        c[k++] = a[i++];
    }
    while(j < n2){
        c[k++] = b[j++];
    }
}
int mergeSort(int* a,int n){
    if(n==1) return 1;
    mergeSort(a,n/2);
    mergeSort(a+n/2,n-n/2);
    int* c = new int[n];
    twoway(a,a+n/2,c,n/2,n-n/2);
    copy(a,a+n,c);
    return 1;
}

int main(){

}