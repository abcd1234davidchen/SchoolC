#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int times;
    while(cin>>times){
        int arr[times];
        for(int i=0;i<times;i++){
            cin>>arr[i];
        }
        sort(arr,arr+times);
        int mid1,mid2;
        mid1 = arr[(times-1)/2];
        mid2 = arr[times/2];
        int count = 0;
        for(int i=0;i<times;i++){
            if(arr[i]==mid1||arr[i]==mid2){
                count+=1;
            }
        }
        cout<<mid1<<" "<<count<<" "<<mid2-mid1+1<<endl;
    }
}
