#include <iostream>
#include <fstream>
using namespace std;

class vegetable{
    private:
        int vegeNum;
        string vegeName;
    public:
        int reset(){
            vegeNum=rand()%5;
            return vegeNum;
        }
        void input(){
            cin>>vegeNum;
            vegeNum-=1;
            convert(vegeNum);
        }
        void convert(int x){
            ifstream inVege;
            inVege.open("vege.txt");
            string theVege;
            for(int i=0;i<=x;i++){
                inVege>>theVege;
            }
            inVege.close();
            vegeName=theVege;
        }
        string output(){
            return vegeName;
        }
};

int main(){
    srand(time(0));
    vegetable vege[3];
    //reset
    for(int i=0;i<3;i++){
        vege[i].convert(vege[i].reset());
        cout<<"Box "<<i+1<<" "<<vege[i].output()<<endl;
    }
    int modify=0;
    while(1){
        cin>>modify;
        if(modify==-1){
            break;
        }
        ifstream inVege;
        inVege.open("vege.txt");
        string theVege;
        for(int i=0;i<5;i++){
            inVege>>theVege;
            cout<<i+1<<theVege<<" ";
        }
        inVege.close();
        modify-=1;
        vege[modify].input();
        for(int i=0;i<3;i++){
            cout<<"Box "<<i+1<<" "<<vege[i].output()<<endl;
        }
    }
    for(int i=0;i<3;i++){
        cout<<"Box "<<i+1<<" "<<vege[i].output()<<endl;
    }
}
