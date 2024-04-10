#include<iostream>
using namespace std;

const int kbpermb=8000;

double videomb(int bitrate,int duration){
    return 1.0*bitrate*duration/kbpermb;
}

int main(){
    int bitrate,duration;
    cin>>bitrate>>duration;
    cout<<videomb(bitrate,duration);
}
