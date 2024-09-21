#include<iostream>
using namespace std;

int number(int** arr,int row,int column){
    int sum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            sum+=arr[i][j];
        }
    }
    return sum;
}

int main(){

    int** arr = new int*[2];
    for(int i=0;i<2;i++){
        arr[i] = new int[2];
    }
    arr[0][0] = 1;arr[0][1] = 2;
    arr[1][0] = 3;arr[1][1] = 4;
    cout<<number(arr,2,2);
}
