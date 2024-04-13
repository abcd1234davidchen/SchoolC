#include<iostream>
using namespace std;

void searchDuplicate(char arr[],int& size){
    //locate each
    for(int i=1;i<size;i++){
        //search to front
        for(int j=i-1;j>=0;j--){
            if(arr[j]==arr[i]){
                for(int k=i;k<size;k++){
                    arr[k]=arr[k+1];
                }
                size-=1;
            }
        }
    }
}

int main(){
    char arr[10]={'a','b','c','d','a','e','c'};
    int size=7;
    searchDuplicate(arr,size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}
