#include<iostream>
using namespace std;

class counter{
    private:
        int max;
        int f,d,s,a;
        bool o;
    public:
        counter(int x){
            max=x;
            reset();
        }
        void reset(){
            f=0;d=0;s=0;a=0;
            o=false;
        }
        bool overflow(){
            if(o==true){
                cout<<"OVERFLOW! r to reset"<<endl;
                return true;
            };
            double total=f*10+d+s*0.1+a*0.01;
            if(total>=max){
                cout<<"OVERFLOW! r to reset"<<endl;
                return true;
            } 
            else return false;
        }
        void incr1(){
            if(!overflow()){
                a+=1;
                check();
            }
        }
        void incr10(){
            if(!overflow()){
                s+=1;
                check();
            }
        }
        void incr100(){
            if(!overflow()){
                d+=1;
                check();
            }
        }
        void incr1000(){
            if(!overflow()){
                f+=1;
                check();
            }
        }
        void overloadRequest(){
            o=true;
        }
        void check(){
            if(a>=10){
                a=0;
                s+=1;
            }
            if(s>=10){
                s=0;
                d+=1;
            }
            if(d>=10){
                d=0;
                f+=1;
            }
            if(f>=10){
                f=0;
                o=true;
            }
            if(!o){
                o=overflow();
            }
        }
        void output(){
            cout<<f<<d<<"."<<s<<a<<endl;
        }
};

int main(){
    cout<<"max?"<<endl;
    int max;
    char c;
    cin>>max;
    counter acounter(max);
    while(1){
        cin>>c;
            switch(c){
                case 'f':
                    acounter.incr1000();
                    acounter.output();
                    break;
                case 'd':
                    acounter.incr100();
                    acounter.output();
                    break;
                case 's':
                    acounter.incr10();
                    acounter.output();
                    break;
                case 'a':
                    acounter.incr1();
                    acounter.output();
                    break;
                case 'r':
                    acounter.reset();
                    break;
                case 'o':
                    acounter.overloadRequest();
                    break;
                default:
                    acounter.output();
                    break;
            }
    }
}
