#include<iostream>
#include<iomanip>
using namespace std;

void arrayCreate(int k){
    int arr[k][k];
    memset(arr,0,sizeof(arr));
    int currentEdit[2] = {0};
    arr[0][k/2] = 1;
    currentEdit[0] = 0;
    currentEdit[1] = k/2;
    for(int i = 0;i<(k*k-1);i++){
        if (arr[(currentEdit[0]+(k-1))%k][(currentEdit[1]+(k-1))%k]!=0){
            currentEdit[0]+=1;
            currentEdit[0]%=k;
        }
        else{
            currentEdit[0]+=(k-1);
            currentEdit[0]%=k;
            currentEdit[1]+=(k-1);
            currentEdit[1]%=k;
        }
        arr[currentEdit[0]][currentEdit[1]] = i+2;
    }
    for (int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n[5] = {1,3,5,7,9};
    for(int i=0;i<5;i++){
        cout<<n[i]<<endl;
        arrayCreate(n[i]);
        cout<<endl;
    }
}
