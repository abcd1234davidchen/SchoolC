#include<iostream>
using namespace std;

class myInterger{
    private:
        int x;
        char xint[10];
    public:
        myInterger(int a):x(a){
            setChar();
        }
        myInterger():x(0){}
        void setChar(){
            int i=0;
            do{
                xint[i]=x%10+'0';
                x/=10;
                i++;
            }while(x>0);
        }
        char& operator[](int index){
            return xint[index];
        }
};

int main(){
    myInterger a(418);
    cout<<a[0]<<a[1]<<a[2];
}
