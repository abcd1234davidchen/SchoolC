#include<iostream>
#include<cmath>
using namespace std;

int randNum(){
    return rand()%10+1;
}

void fillArray(double arr[],int& size){
    size=randNum();
    for(int i=0;i<size;i++){
        arr[i]=randNum();
    }
}

double arrAvg(double arr[],int size){
    double sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum*1.0/size;
}

double stdDer(double arr[],int size){
    double avg=arrAvg(arr,size),sum=0;
    for(int i=0;i<size;i++){
        sum+=(arr[i]-avg)*(arr[i]-avg);
    }
    sum/=size;
    return sqrt(sum);
}

int main(){
    srand(time(0));
    double arr[10];
    int size=0;
    fillArray(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Standard Derivaiation"<<stdDer(arr,size);
}
