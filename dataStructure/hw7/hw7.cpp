#include <iostream>
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

void heapSort(){

}

void quickSort(){

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

void generateRandom(int* a, int n){
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0;i<n;i++){
        a[i]=rand()%(n*10);
    }
}


int main(){
    bool handout = true;
    if (handout){

        int setN = 500000;
        int* ogArr = new int[setN];
        int* arr = new int[setN];
        generateRandom(ogArr,setN);

        copy(ogArr,ogArr+setN,arr);
        auto start = high_resolution_clock::now();
        selectionSort(arr,setN);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken by selectionSort: " << duration.count() << " milliseconds" << endl;
        
    }
    else{
        //int dataN[] = {100,500,1000,5000,10000,50000,100000,500000};
    }
}
