#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double ax,ay,bx,by,cx,cy,dx,dy;
    double fourthX=0,fourthY=0;
    while(cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy){
        if(ax==cx&&ay==cy){
            fourthX = bx-ax+dx;
            fourthY = by-ay+dy;
        }
        else if(bx==cx&&by==cy){
            fourthX = ax-bx+dx;
            fourthY = ay-by+dy;
        }
        else if(ax==dx&&ay==dy){
            fourthX = bx-ax+cx;
            fourthY = by-ay+cy;
        }
        else if(bx==dx&&by==dy){
            fourthX = ax-bx+cx;
            fourthY = ay-by+cy;
        }
        cout<<fixed<<setprecision(3)<<fourthX<<" "<<setprecision(3)<<fourthY<<endl;
    }
}
