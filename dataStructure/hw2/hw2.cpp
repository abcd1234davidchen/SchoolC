//Author: 陳展皝 B123245006
//Date: Sept. 11, 2024
//Purpose: input two sets and do +,-,*,>= and include operations based on the sets

#include<iostream>
#include<cstring>
using namespace std;

class TSet{
    private:
        string name;            //specify name for direct output
        char arr[256];          //initialize 256 space for char that is in
    public:
        TSet(string inName,char input[]){   //constructor for sets that have input
            name=inName;                    //set name
            memset(arr,0,256);              //set array to be empty
            for(int i=0;i<256;i++){         //set array to copy input
                if (input[i]=='1') arr[i]='1';
            }
        }
        TSet(string inName){                //set with only name
            name=inName;                    //set name
            memset(arr,0,256);              //set array to be empty
        }
        TSet(){
            name = "";                      //set with name to be setted
            memset(arr,0,256);              //set array to be empty
        }
        TSet operator+ (const TSet& other){ //+ operator that adds element if included in either
            char newArr[256] = {0};         //set a new empty array
            for(int i=0;i<256;i++){         //if any of the array includes the elememt, set elemet in new array to be 1
                if (arr[i]=='1' || other.arr[i]=='1') newArr[i]='1';
            }
            return TSet(name + "+" + other.name,newArr);    //return set that is built with name together and new array
        }
        TSet operator* (const TSet& other){ //* operator that adds element if included in both
            char newArr[256] = {0};         //set a new empty array
            for(int i=0;i<256;i++){         //if both of the array include the element, set element in new array to be 1
                if ((arr[i]=='1') && (other.arr[i]=='1')) newArr[i]='1';
            }
            return TSet((name + "*" + other.name),newArr);  //return set that is built with name together and new array
        }
        TSet operator- (const TSet& other){ // operator that adds element if included in one
            char newArr[256] = {0};         //set a new empty array
            for(int i=0;i<256;i++){         //if only the first array include the element, set element in new array to be 1
                if (arr[i]=='1' && other.arr[i]!='1') newArr[i]='1';
            }
            return TSet(name + "-" + other.name,newArr); //return set that is built with name together and new array
        }
        string operator>= (const TSet& other){
            for(int i=0;i<256;i++){         //if the second array include any element that the first don't return string that it doesn't
                if (other.arr[i]=='1' && arr[i]!='1') return name+" does not contain "+other.name;
            }
            return name+" does contain "+other.name;    //else return string that it does
        }
        string has(const char x){           //convert the input char to int and find if the element in array is 1
            return "'"+string(1,x)+((arr[int(x)]=='1')? "' is in ":"' is not in ")+name;    //return the result
        }
        friend ostream& operator<< (ostream& os,const TSet& one){   //directly output the set
            os<<one.name<<": {";                    //output name:{
            for(int i=0;i<256;i++){                 //outout the elements that is included
                if (one.arr[i]=='1') os<<char(i);   
            }
            os<<"}";                                //output the last }
            return os;
        }
        friend istream& operator>> (istream& is,TSet& one){         //directly input the set
            string input;
            is>>input;
            for(size_t i=0;i<input.length();i++){       //set the elements that is included in the input to be 1
                one.arr[int(input[i])]='1';
            }
            return is;
        }
};

int main(){
    int times;
    cin>>times;
    for(int i=0;i<times;i++){   //loop for input times
        TSet A("A");    //create set A with name specified
        TSet B("B");    //create set B with name specified
        char x;         //char x to be checked later
        cin>>A>>B>>x;   //input with istream overload
        TSet C,D;       //create set with empty name
        C=A+B;          //make set C to be A+B which passes the name and new array
        D=A*B;          //make set D to be A*B which passes the name and new array
        cout<<"Test Case "<<i+1<<endl;  //output to specify test case
        cout<<A<<endl;  //output set A
        cout<<B<<endl;  //output set B
        cout<<C<<endl;  //output set C
        cout<<D<<endl;  //output set D
        cout<<(A-B)<<endl;  //output A-B
        cout<<(B-A)<<endl;  //output B-A
        cout<<(A>=B)<<endl; //output B in A?
        cout<<(B>=A)<<endl; //output A in B?
        cout<<A.has(x)<<endl;   //if A has x?
        cout<<B.has(x)<<endl<<endl; //if B has x?
    }
}
