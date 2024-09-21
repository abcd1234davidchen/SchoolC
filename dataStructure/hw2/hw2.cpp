#include<iostream>
#include<cstring>
using namespace std;

class set{
    private:
        char arr[256];
        int arrLength;
    public:
        set(char input[]){
            memset(arr,0,256);
            arrLength = 0;
            for(int i=0;i<256&&input[i]!='\0';i++){
                bool flag = true;
                for(int j=0;j<arrLength;j++){
                    if (input[i]==arr[j]){
                        flag = false; break;
                    }
                }
                if (flag){
                    arr[arrLength] = input[i];
                    arrLength+=1;
                }
            }
            for(int i=0;i<arrLength;i++){
                for(int j=i;j<arrLength;j++){
                    if (arr[i]>arr[j]){
                        swap(arr[i],arr[j]);
                    }
                }
            }
        }
        set operator+ (const set& other){
            strcat(arr,other.arr);
            set returnSet(arr);
            return returnSet;
        }
        set operator* (const set& other){
            char newArr[256];
            int newLength = 0;
            for(int i=0;i<arrLength;i++){
                for(int j=0;j<other.arrLength;j++){
                    if (arr[i]==other.arr[j]){
                        newArr[newLength] = arr[i];
                        newLength+=1;
                    }
                }
            }
            newArr[newLength] = '\0';
            set returnSet(newArr);
            return returnSet;
        }
        set operator- (const set& other){
            char newArr[256];
            int newLength = 0;
            strcpy(newArr,arr);
            for(int i=0;i<arrLength;i++){
                bool flag = true;
                for(int j=0;j<other.arrLength;j++){
                    if (arr[i]==other.arr[j]){
                        flag = false; break;
                    }
                }
                if(flag){
                    newArr[newLength] = arr[i];
                    newLength+=1;
                }
            }
            newArr[newLength] = '\0';
            set returnSet(newArr);
            return returnSet;
        }
        bool operator>= (const set& other){
            for(int i=0;i<other.arrLength;i++){
                bool flag = true;
                for(int j=0;j<arrLength;j++){
                    if(other.arr[i]==arr[j]){
                        flag = false; break;
                    }
                }
                if(flag) return false;
            }
            return true;
        }
        bool has(const char x){
            for(int i=0;i<arrLength;i++){
                if (arr[i] == x) return true;
            }
            return false;
        }
        friend ostream& operator<< (ostream& os,const set& one){
            os<<one.arr;
            return os;            
        }
};

int main(){
    int times;
    cin>>times;
    for(int i=0;i<times;i++){
        char one[256]={0};
        char two[256]={0};
        char x;
        cin>>one>>two>>x;
        set A(one);
        set B(two);
        cout<<"Test Case"<<i+1<<endl;
        cout<<"A:{"<<A<<"}"<<endl;
        cout<<"B:{"<<B<<"}"<<endl;
        cout<<"A+B:{"<<(A+B)<<"}"<<endl;
        cout<<"A*B:{"<<(A*B)<<"}"<<endl;
        cout<<"A-B:{"<<(A-B)<<"}"<<endl;
        cout<<"B-A:{"<<(B-A)<<"}"<<endl;
        cout<<"A "<<((A>=B)?"contains":"does not contain")<<" B"<<endl;
        cout<<"B "<<((B>=A)?"contains":"does not contain")<<" A"<<endl;
        cout<<"'"<<x<<"'"<<((A.has(x))?"is":"is not")<<" in A"<<endl;
        cout<<"'"<<x<<"'"<<((B.has(x))?"is":"is not")<<" in B"<<endl<<endl;
    }
}
