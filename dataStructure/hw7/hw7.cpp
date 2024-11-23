#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <algorithm>
using namespace std;
using namespace std::chrono;

double selectionSort(int* a,int n,int limit){
    auto start = high_resolution_clock::now();
    for(int i=0;i<n-1;i++){
        auto now = high_resolution_clock::now();
        if( duration_cast<seconds>(now - start).count()>limit) return -1;
        int j=i;
        for(int k=i+1;k<n;k++){
            if(a[j]>a[k]) j=k;
        }
        swap(a[i],a[j]);
    }
    auto now = high_resolution_clock::now();
    return static_cast<int>(duration_cast<milliseconds>(now - start).count())*1.0/1000;
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
double heapSort(int* a,int n,int limit){
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    auto start = high_resolution_clock::now();
    for (int i = n - 1; i > 0; i--) {
        auto now = high_resolution_clock::now();
        if( duration_cast<seconds>(now - start).count()>limit) return -1;
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
    auto now = high_resolution_clock::now();
    return static_cast<int>(duration_cast<milliseconds>(now - start).count())*1.0/1000;
}

double quickSort(int* a,int n,int limit){
    if(n<=1) return true;
    auto start = high_resolution_clock::now();
    int pivot = a[n-1];
    int i=0;
    for(int j=0;j<n-1;++j){
        if(a[j]<pivot){
            swap(a[j],a[i]);
            ++i;
        }
    }
    swap(a[n-1],a[i]);

    quickSort(a,i,limit);
    quickSort(a+i+1,n-i-1,limit);
    auto now = high_resolution_clock::now();
    double time = static_cast<int>(duration_cast<milliseconds>(now - start).count())*1.0/1000;
    return (time<limit?time:-1);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
double cqsort(int* a, int n,int limit){
    auto start = high_resolution_clock::now();
    qsort(a, size_t(n), sizeof(int), compare);
    auto now = high_resolution_clock::now();
    double time = static_cast<int>(duration_cast<milliseconds>(now - start).count())*1.0/1000;
    return (time<limit?time:-1);
}

double sortfunc(int* a,int n,int limit){
    auto start = high_resolution_clock::now();
    sort(a,a+n);
    auto now = high_resolution_clock::now();
    double time = static_cast<int>(duration_cast<milliseconds>(now - start).count())*1.0/1000;
    return (time<limit?time:-1);
}

void writeUnsorted(int n){
    ofstream out;
    out.open("input.txt");
    out<<n<<endl;
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0;i<n;i++){
        out<<rand()<<endl;
    }
    out.close();
}

void readFirstLine(int& n){
    ifstream in;
    in.open("input.txt");
    in>>n;
    in.close();
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

double sortBy(int* a,int i,int n,bool table,int limit){
    string methods[5] = {"Selection Sort", "Heap Sort", "Quick Sort", "C qsort", "C++ std::sort"};

    double time = 0;

    switch (i){
    case 0:
        time = selectionSort(a,n,limit);
        break;
    case 1:
        time = heapSort(a, n, limit);
        break;
    case 2:
        time = quickSort(a, n, limit);
        break;
    case 3:
        time = cqsort(a, n, limit);
        break;
    case 4:
        time = sortfunc(a, n, limit);
        break;
    default:
        break;
    }
    
    if(!table) cout << "Time taken by "<<methods[i]<<": " << time << " seconds" << endl;
    
    writeSorted(i,methods[i],a,n);
    return time;
}

void run(int n=20, int limit=10, bool table=false){
    if(table){
        double avg[5]={0};
        cout<<setw(7)<<n;
        for(int i=0;i<10;i++){

            writeUnsorted(n);
            readFirstLine(n);

            int* ogArr = new int[n];
            int* arr = new int[n];

            readUnsorted(ogArr,n);

            if(i!=0) cout<<"       ";
            for(int j=0;j<5;j++){
                copy(ogArr,ogArr+n,arr);
                double time=sortBy(arr,j,n,table,limit);
                cout<<setw(7)<<setprecision(3)<<fixed<<time;
                avg[j]+=time;
            }
            cout<<endl;
        }
        cout<<"    avg";
        for(int i=0;i<5;i++){
            cout<<setw(7)<<setprecision(3)<<fixed<<avg[i]/10;
        }
        cout<<endl;
    }
    else{

        writeUnsorted(n);
        readFirstLine(n);

        int* ogArr = new int[n];
        int* arr = new int[n];

        readUnsorted(ogArr,n);

        for(int i=0;i<5;i++){
            copy(ogArr,ogArr+n,arr);
            sortBy(arr,i,n,table,limit);
        }
    }
}

int main(){
    bool table = true;
    int limit = 30;
    if (!table){
        run(50000,limit);
    }
    else{
        int dataN[] = {100,500,1000,5000,10000,50000,100000,500000};
        cout<<"       "<<"   sele"<<"   heap"<<"   qsor"<<"   cqSo"<<"   c+qS"<<endl;
        for(int j=0;j<8;j++){
            run(dataN[j],limit,true);
            cout<<endl;
        }
        cout<<endl;
    }
}
