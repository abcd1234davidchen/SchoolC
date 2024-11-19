#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void selectionSort(int* a,int n){
    for(int i=0;i<n-1;i++){
        int j=i;
        for(int k=i+1;k<n;k++){
            if(a[j]>a[k]) j=k;
        }
        swap(a[i],a[j]);
    }
}

void insertionSort(int* a,int n){

}

void heapSort(){

}

void quickSort(){
    
}

void twoway(int* a, int* b, int* c, int n1, int n2){
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while(i < n1) c[k++] = a[i++];
    while(j < n2) c[k++] = b[j++];
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


void print(int*a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void generateInput(){

}

void generateRandom(int* a, int n){
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i]=rand()%(n*10);
    }
}

int main(){
    int setN=5;
    int* arr = new int[setN];
    generateRandom(arr,setN);
    print(arr,setN);
    selectionSort(arr,setN);
    print(arr,setN);
}
