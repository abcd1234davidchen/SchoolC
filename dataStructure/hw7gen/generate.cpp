#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

void generateUnsorted(int n){
    ofstream out;
    out.open("input.txt");
    out<<n<<endl;
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0;i<n;i++){
        out<<rand()<<endl;
    }
    out.close();
}

int main(){
    generateUnsorted(50000);
}