#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void selectionSort(int* a,int n){
    for(int i=0;i<n-1;i++){
        int j=i;
        for(int k=i+1;k<n;k++){
            if(a[j]>a[k]) j=k;
        }
        swap(a[i],a[j]);
    }
}


void heapify(int* a,int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&a[l]>a[largest]){
        largest = l;
    }
    if(r<n&&a[r]>a[largest]){
        largest = r;
    }
    if(i!=largest){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void heapSort(int* a,int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void quickSort(int* a,int n){
    if(n<=1) return;
    int pivot = a[n-1];
    int i=0;
    for(int j=0;j<n-1;++j){
        if(a[j]<pivot){
            swap(a[j],a[i]);
            ++i;
        }
    }
    swap(a[n-1],a[i]);
    quickSort(a,i);
    quickSort(a+i+1,n-i-1);
}

void cqsort(int* a, int n){
    qsort(a,size_t(n),sizeof(int),[](const void* a,const void* b)->int{return (*(int*)a - *(int*)b);});
}

void sortfunc(int* a,int n){
    sort(a,a+n);
}


void print(int*a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void writeUnsorted(int* a,int n){
    ofstream out;
    out.open("input.txt");
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0;i<n;i++){
        a[i]=rand()%(n*10);
    }
}

void readUnsorted(){
    
}

void writeSorted(){

}


int main(){
    bool handout = true;
    if (handout){

        int setN = 500000;
        int* ogArr = new int[setN];
        int* arr = new int[setN];
        //generateRandom(ogArr,setN);

        copy(ogArr,ogArr+setN,arr);
        auto start = high_resolution_clock::now();
        quickSort(arr,setN);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken by quickSort: " << duration.count() << " milliseconds" << endl;
        //print(arr,setN);
    }
    else{
        //int dataN[] = {100,500,1000,5000,10000,50000,100000,500000};
    }
}
