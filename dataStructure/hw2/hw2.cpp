#include<iostream>
#include<cstring>
using namespace std;

class set{
    private:
        char arr[256];
        int arrLength = 0;
    public:
        set(string input){
            for(size_t i=0;i<input.length();i++){
                bool flag = true;
                for(int j=0;j<arrLength;j++){
                    if (input[i]==arr[j]){
                        flag = false;
                        break;
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
                        char temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        set(char input[]){
            for(int i=0;i<256&&input[i]!='\0';i++){
                bool flag = true;
                for(int j=0;j<arrLength;j++){
                    if (input[i]==arr[j]){
                        flag = false;
                        break;
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
                        char temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        void setArr(char input[]){
            strcpy(arr,input);
            for(int i=0;i<256;i++){
                if (arr[i]=='\0'){
                    arrLength = i;
                    break;
                }
            }
        }
        char* getArr(){
            return arr;
        }
        set operator+ (const set& other){
            char newArr[256];
            strcpy(newArr,arr);
            for(int i=0;i<other.arrLength;i++){
                newArr[arrLength+i] = other.arr[i];
            }
            newArr[arrLength+other.arrLength] = '\0';
            set returnSet(newArr);
            return returnSet;
        }
};

int main(){
    string one = "abcdef";
    string two = "chfeechi";
    set A(one);
    set B(two);
    cout<<(A+B).getArr();
}
