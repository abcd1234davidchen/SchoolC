#include<iostream>
using namespace std;

void sort(int&a,int&b,int&c){
    int arr[3]={a,b,c},temp;
    for(int i=0;i<2;i++){
        for(int j=i;j<3;j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    a=arr[0];
    b=arr[1];
    c=arr[2];
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    sort(a,b,c);
    cout<<a<<b<<c;
}
