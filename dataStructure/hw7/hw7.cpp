//Author: 陳展皝 B123245006
//Date: Nov. 12, 2024
//Purpose: compare different sorting methods
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
using namespace std;

double selectionSort(int* a,int n,int limit){   //code for selection sort
    clock_t start = clock();    //start time
    for(int i=0;i<n-1;i++){     //go through all the numbers
        clock_t now = clock();  //now for TLE
        if(static_cast<double>(now - start)/(CLOCKS_PER_SEC)>limit) return -1;  //return -1 when TLE
        int j=i;                //j for the smallest
        for(int k=i+1;k<n;k++){
            if(a[j]>a[k]) j=k;  //if k is smaller change it to j
        }
        swap(a[i],a[j]);        //swap i to the smallest
    }
    clock_t now = clock();      //clock to remember time at last
    return static_cast<double>(now - start)/(CLOCKS_PER_SEC);   //return time useds
}

void heapify(int* a,int n,int i){   //a is array n is size i is the one to sort
    int largest=i;      //set the largest to i
    int l=2*i+1;        //left subtree
    int r=2*i+2;        //right subtree
    if(l<n&&a[l]>a[largest]){   //if left exist and bigger than largest set to left
        largest = l;
    }
    if(r<n&&a[r]>a[largest]){   //if right exist and bigger that largest set to right
        largest = r;
    }
    if(i!=largest){     //if the largest is changed
        swap(a[i],a[largest]);  //swap value
        heapify(a,n,largest);   //do heapify for the changed
    }
}
double heapSort(int* a,int n,int limit){
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);  //sort to make it max heap
    clock_t start = clock();    //start timer
    for (int i = n - 1; i > 0; i--) {
        clock_t now = clock();  //a timer to test if time exceed limit
        if(static_cast<double>(now - start)/(CLOCKS_PER_SEC)>limit) return -1;
        swap(a[0], a[i]);   //swap the first item with the last unsorted item
        heapify(a, i, 0);   //make them max heap
    }
    clock_t now = clock();  //stop timer
    return static_cast<double>(now - start)/(CLOCKS_PER_SEC);   //return time
}

double quickSort(int* a,int n,int limit){
    if(n<=1) return 0;       //if the size is 1 or less return
    clock_t start = clock();    //start timer
    int pivot = a[n-1];         //pivot that is the right most item
    int i=0;                    //i to control where to put pivot
    for(int j=0;j<n-1;++j){     //from the start of array
        if(a[j]<pivot){         //if the value is less than pivot
            swap(a[j],a[i]);    //swap to i
            ++i;                //move i forward
        }
    }
    swap(a[n-1],a[i]);          //swap pivot and i

    quickSort(a,i,limit);       //sort values before pivot
    quickSort(a+i+1,n-i-1,limit);   //after pivot
    clock_t now = clock();      //stop time
    double time = static_cast<double>(now - start)/(CLOCKS_PER_SEC);
    return (time<limit?time:-1);    //return time if less than limit
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);   //compare function for qsort
}
double cqsort(int* a, int n,int limit){
    clock_t start = clock();        //start timer
    qsort(a, size_t(n), sizeof(int), compare);  //qsort from c
    clock_t now = clock();          //stop timer
    double time = static_cast<double>(now - start)/(CLOCKS_PER_SEC);
    return (time<limit?time:-1);    //return time if less than limit
}

double sortfunc(int* a,int n,int limit){
    clock_t start = clock();        //start timer
    sort(a,a+n);                    //sort
    clock_t now = clock();          //stop timer
    double time = static_cast<double>(now - start)/(CLOCKS_PER_SEC);
    return (time<limit?time:-1);    //return time if less than limit
}

void generateUnsorted(int n){       //input n to generate a file with n random values
    ofstream out;
    out.open("input.txt");  //open or create input file
    out<<n<<endl;           //output n first
    srand(static_cast<unsigned int>(time(0)));  //set seed
    for(int i=0;i<n;i++){
        out<<rand()<<endl;  //output a random number to file
    }
    out.close();            //close file
}

void readFirstLine(int& n){
    ifstream in;
    in.open("input.txt");   //open input.txt
    in>>n;                  //read first lien for n
    in.close();             //close it
}

void readUnsorted(int* a,int& n){
    ifstream in;
    in.open("input.txt");   //open input.txt
    in>>n;                  //input n
    int temp;
    int i=0;
    while(in>>temp){
        a[i]=temp;          //input to a array
        i++;
    }
    in.close();             //close file
}

void writeSorted(int m,string method,int* a,int n){
    ofstream out;
    char c[12]="output .txt";   //file name
    c[6]=static_cast<char>('A'+m);  //set with sort method m
    out.open(c);                //open or create file
    out<<method;                //output the method first
    for(int i=0;i<n;i++){
        out<<endl<<a[i];        //output each item in a
    }
}

double sortBy(int* a,int i,int n,bool table,int limit){ //unify way to sort
    string methods[5] = {"Selection Sort", "Heap Sort", "Quick Sort", "C qsort()", "C++ sort()"};
    //methods of sorting to pass to output
    double time = 0;
    //record time
    switch (i){
    case 0:
        time = selectionSort(a,n,limit);    //if 0 selection sort
        break;
    case 1:
        time = heapSort(a, n, limit);       //if 1 heap sort
        break;
    case 2:
        time = quickSort(a, n, limit);      //if 2 quicksort
        break;
    case 3:
        time = cqsort(a, n, limit);         //if 3 qsort
        break;
    case 4:
        time = sortfunc(a, n, limit);       //if 4 sort()
        break;
    default:
        break;
    }
    
    if(!table) cout<<setw(7)<<setprecision(3)<<fixed<< "Time taken by "<<methods[i]<<": " << time << " seconds" << endl;
    //if not outputing a table output info to terminal
    writeSorted(i,methods[i],a,n);  //write result
    return time;    //return time used
}

void run(int n=20, int limit=10, bool table=false){
    if(table){  //if outputing a table
        double avg[5]={0};  //record average of 5 sorting methods
        cout<<setw(7)<<n<<" ";  //output data size
        for(int i=0;i<10;i++){  //run ten times

            generateUnsorted(n);    //generate data
            int* ogArr = new int[n];//set array with n data
            int* arr = new int[n];  //and another to sort
            readUnsorted(ogArr,n);  //read from file to array

            if(i!=0) cout<<"        ";  //i not zero print to align
            for(int j=0;j<5;j++){       //use five methods to sort
                copy(ogArr,ogArr+n,arr);//copy from ogArr to arr
                double time=sortBy(arr,j,n,table,limit);    //sort and record time
                cout<<setw(7)<<setprecision(3)<<fixed<<time;//output time
                avg[j]+=time;           //add value to the specified
            }
            cout<<endl;                 //change line
        }
        cout<<"    avg ";               //output the average
        for(int i=0;i<5;i++){
            cout<<setw(7)<<setprecision(3)<<fixed<<avg[i]/10;
        }       //output with fixed format
        cout<<endl;
    }
    else{   //if not output as a table
        readFirstLine(n);   //read first line for creating array
        int* ogArr = new int[n];//two arrays one to memorize
        int* arr = new int[n];  //one to sort
        readUnsorted(ogArr,n);  //read to ogArr
        for(int i=0;i<5;i++){
            copy(ogArr,ogArr+n,arr);    //copy from ogArr to arr
            sortBy(arr,i,n,table,limit);//sort arr
        }
    }
}

int main(){
    bool table = false; //control whether using a table
    int limit = 2000;     //set limit to 10 seconds
    if (!table){        //output to terminal
        generateUnsorted(1000000);    //generate data
        run(0,limit,false);     //sort
    }
    else{   //output as a table
        int dataN[] = {100,500,1000,5000,10000,50000,100000,500000};    //different datasets
        cout<<"'-1' stands for TLE which is "<<limit<<" seconds in this case"<<endl;    //warn message that -1 means TLE
        cout<<"       "<<"   sele"<<"   heap"<<"   qsor"<<"   cqSo"<<"   c+qS"<<endl;   //a title for all the sorting methods
        for(int j=0;j<8;j++){   //run with different dataset
            run(dataN[j],limit,true);   //run each
            cout<<endl;         //output change line
        }
        cout<<endl;
    }
}
