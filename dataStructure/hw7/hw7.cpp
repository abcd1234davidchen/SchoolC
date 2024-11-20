#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
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
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
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

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
void cqsort(int* a, int n){
    qsort(a, size_t(n), sizeof(int), compare);
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

void writeUnsorted(int n){
    ofstream out;
    out.open("input.txt");
    out<<n<<endl;
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0;i<n;i++){
        out<<rand()%(n*10)<<endl;
    }
    out.close();
}

void readUnsorted(int* a,int& n){
    ifstream in;
    in.open("input.txt");
    in>>n;
    int temp;
    int i=0;
    while(in>>temp){
        a[i]=temp;
        i++;
    }
    in.close();
}

void writeSorted(int m,string method,int* a,int n){
    char c = static_cast<char>('A' + m);
    ofstream out;
    out.open("output" + string(1, c) + ".txt");
    out<<method;
    for(int i=0;i<n;i++){
        out<<endl<<a[i];
    }
}

int sortBy(int* a,int i,int n,bool table){
    string methods[5] = {"Selection Sort", "Heap Sort", "Quick Sort", "C qsort", "C++ std::sort"};

    auto start = high_resolution_clock::now();

    switch (i){
    case 0:
        selectionSort(a,n);
        break;
    case 1:
        heapSort(a,n);
        break;
    case 2:
        quickSort(a,n);
        break;
    case 3:
        cqsort(a,n);
        break;
    case 4:
        sortfunc(a,n);
        break;
    default:
        break;
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    if(!table) cout << "Time taken by "<<methods[i]<<": " << duration.count() << " milliseconds" << endl;
    
    writeSorted(i,methods[i],a,n);
    return static_cast<int>(duration.count());
}

void run(int n=20,bool table=false){
    writeUnsorted(n);
    int* ogArr = new int[n];
    int* arr = new int[n];


    readUnsorted(ogArr,n);
    if(table){
        for(int i=0;i<5;i++){
            if(i!=0) cout<<"       ";
            for(int j=0;j<5;j++){
                copy(ogArr,ogArr+n,arr);
                cout<<setw(7)<<sortBy(arr,j,n,table);
            }
            cout<<endl;
        }
    }
    else{
        for(int i=0;i<5;i++){
            copy(ogArr,ogArr+n,arr);
            sortBy(arr,i,n,table);
        }
    }
}

int main(){
    bool table = true;
    if (!table){
        run(50000);
    }
    else{
        int dataN[] = {100,500,1000,5000,10000,50000,100000,500000};
        cout<<"       "<<"   sele"<<"   heap"<<"   qsor"<<"   cqSo"<<"   c+qS"<<endl;
        for(int j=0;j<8;j++){
            cout<<setw(7)<<dataN[j];
            run(dataN[j],true);
            cout<<endl;
        }
        cout<<endl;
    }
}
