#include <iostream>
#include <vector>
using namespace std;

int main(){
    int cases;
    cin>>cases;
    for(int k=0;k<cases;k++){
        int n,setDay,temp;
        cin>>setDay;
        cin>>n;
        vector<int> lst;
        for(int j=0;j<n;j++){
            cin>>temp;
            lst.push_back(temp);
        }
        int h = 0;
        for(int day = 0; day<setDay;day++){
            bool flag = false;
            if(day%7 == 5||day%7 == 6){
                continue;
            }
            for(size_t i=0;i<lst.size()&&!flag;i++){
                if(day%lst[i] == lst[i]-1){
                    flag = true;
                    break;
                }
            }
            if(flag){
                //cout<<"DAY"<<day;
                h+=1;
            }
        }
        cout<<h<<endl;
    }
}
