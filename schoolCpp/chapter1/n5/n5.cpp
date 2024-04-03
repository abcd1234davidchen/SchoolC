#include<iostream>
#include<math.h>
using namespace std;
//capacity,average,current 5000 500 10
int main(){
    double capacity,average,maxBox;
    int current;
    cin>>capacity>>average>>current;
    maxBox=capacity/average;
    maxBox=floor(maxBox);
    if(maxBox>current){
        cout<<"You can still fit "<<maxBox-current<<" boxes";
    }
    else if (maxBox==current){
        cout<<"You're fitting just right";
    }
    else{
        cout<<current-maxBox<<" boxes should be removed";
    }
}
