#include <iostream>

using namespace std;

void sel(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

int main(){
    int arr[4]={5,7,5,3};
    sel(arr,4);
    cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<endl;
}