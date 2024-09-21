//Author: 陳展皝 B123245006
//Date: Sept. 11, 2024
//Purpose: Print out factorial of multiple numbers

#include <iostream>
#include <vector>
using namespace std;

void fact(int n){
    //create vectors to save the factorial number and initialize to one
    vector<int> vec;
    vec.push_back(1);

    //loop through all numbers
    for(int i=1;i<=n;i++){
        //each elements times number
        for(size_t j=0;j<vec.size();j++){
            vec[j]*=i;
        }

        //spread out the numbers to keep all element less then ten
        for (size_t j=0;j<vec.size();j++) {
            if (vec[j] >= 10) {
                //if last element exceeds 10, add a new element to save digit
                if (vec.size()==j+1) {
                    vec.push_back(0);
                }

                vec[j+1]+=vec[j]/10;
                vec[j]%=10;
            }
        }
        cout<<i<<"!=";
        //print out all elements
        for(size_t j=vec.size();j>0;j--){
            cout<<vec[j-1];
        }
        cout<<endl;
    }
}

int main(){
    int input;
    //save n to vector until user inputs 0
    while(cin>>input,input!=0){
        fact(input);
        cout<<endl;
    }
}
