#include<iostream>
using namespace std;
class weight{
    private:
        double pounds;
    public:
        void reset(double x){
            pounds=x;
        }
        void setPnd(){
            cin>>pounds;
        }
        void setOnc(){
            double x;
            cin>>x;
            pounds=x*1.0/16;
        }
        void setKlo(){
            double x;
            cin>>x;
            pounds=2.21*x;
        }
        void viewPnd(){
            cout<<pounds;
        }
        void viewOnc(){
            cout<<pounds*16;
        }
        void viewKlo(){
            cout<<pounds/2.21;
        }
};

int main(){
    weight one;
    one.reset(6);
    int mode;
    while(1){
        cout<<"1 sP 2 sK 3 sO"<<endl<<"4 vP 5 vK 6 vO ";
        cin>>mode;
        switch (mode){
            case 1:
                one.setPnd();
                break;
            case 2:
                one.setKlo();
                break;
            case 3:
                one.setOnc();
                break;
            case 4:
                one.viewPnd();
                break;
            case 5:
                one.viewKlo();
                break;
            case 6:
                one.viewOnc();
                break;
            
        }
        cout<<endl;
    }
}
