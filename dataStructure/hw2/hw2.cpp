#include<iostream>
#include<cstring>
using namespace std;

class TSet{
    private:
        string name;
        char arr[256];
    public:
        TSet(string inName,char input[]){
            name=inName;
            memset(arr,0,256);
            for(int i=0;i<256;i++){
                if (input[i]=='1') arr[i]='1';
            }
        }
        TSet(string inName){
            name=inName;
            memset(arr,0,256);
        }
        TSet(){
            name = "";
            memset(arr,0,256);
        }
        TSet operator+ (const TSet& other){
            char newArr[256] = {0};
            for(int i=0;i<256;i++){
                if (arr[i]=='1' || other.arr[i]=='1') newArr[i]='1';
            }
            return TSet(name + "+" + other.name,newArr);
        }
        TSet operator* (const TSet& other){
            char newArr[256] = {0};
            for(int i=0;i<256;i++){
                if ((arr[i]=='1') && (other.arr[i]=='1')) newArr[i]='1';
            }
            return TSet((name + "*" + other.name),newArr);
        }
        TSet operator- (const TSet& other){
            char newArr[256] = {0};
            for(int i=0;i<256;i++){
                if (arr[i]=='1' && other.arr[i]!='1') newArr[i]='1';
            }
            return TSet(name + "-" + other.name,newArr);
        }
        string operator>= (const TSet& other){
            for(int i=0;i<256;i++){
                if (other.arr[i]=='1' && arr[i]!='1') return name+" does not contain "+other.name;
            }
            return name+" does contain "+other.name;
        }
        string has(const char x){
            return "'"+string(1,x)+((arr[int(x)]=='1')? "' is in ":"' is not in ")+name;
        }
        friend ostream& operator<< (ostream& os,const TSet& one){
            os<<one.name<<": {";
            for(int i=0;i<256;i++){
                if (one.arr[i]=='1') os<<char(i);
            }
            os<<"}";
            return os;            
        }
        friend istream& operator>> (istream& is,TSet& one){
            string input;
            is>>input;
            for(size_t i=0;i<input.length();i++){
                one.arr[int(input[i])]='1';
            }
            return is;
        }
};

int main(){
    int times;
    cin>>times;
    for(int i=0;i<times;i++){
        TSet A("A");
        TSet B("B");
        char x;
        cin>>A>>B>>x;
        TSet C,D;
        C=A+B;
        D=A*B;
        cout<<"Test Case "<<i+1<<endl;
        cout<<A<<endl;
        cout<<B<<endl;
        cout<<C<<endl;
        cout<<D<<endl;
        cout<<(A-B)<<endl;
        cout<<(B-A)<<endl;
        cout<<(A>=B)<<endl;
        cout<<(B>=A)<<endl;
        cout<<A.has(x)<<endl;
        cout<<B.has(x)<<endl<<endl;
    }
}
