#include<iostream>
#include<vector>
using namespace std;

int ink(int characters[36], int n, int base){
    int rt = 0;
    rt+=characters[n%base];
    n/=base;
    while(n>0){
        rt+=characters[n%base];
        n/=base;
    }
    return rt;
}

int main(){
    int cases;
    cin>>cases;
    for(int i=0;i<cases;i++){
        int characters[36] = {0};
        for(int j=0;j<36;j++){
            cin>>characters[j];
        }

        int n;
        cin>>n;
        cout<<"Case "<<i+1<<":"<<endl;
        
        for(int j=0;j<n;j++){
            int one;
            cin>>one;
            int min=ink(characters,one,2);
            vector<int> list;
            for(int k=2;k<=36;k++){
                int temp = ink(characters,one,k);
                if(temp<min){
                    list.clear();
                    min=temp;
                    list.push_back(k);
                }
                else if(temp == min){
                    list.push_back(k);
                }
            }
            cout<<"Cheapest base(s) for number "<<one<<": ";
            for(size_t k=0;k<list.size();k++){
                cout<<list[k]<<" ";
            }
            cout<<endl;
        }
    }
}
