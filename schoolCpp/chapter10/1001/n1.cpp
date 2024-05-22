#include<iostream>
using namespace std;

class TwoD {
private:
    double* data;
    int MaxRows;
    int MaxCols;

public:
    // Default constructor
    TwoD(int mRows,int mCols):MaxRows(mRows),MaxCols(mCols){
        data=new double[MaxRows*MaxCols]();
    }
    // Copy constructor
    TwoD(const TwoD& other){
        MaxRows=other.MaxRows;
        MaxCols=other.MaxCols;
        data=new double[MaxRows*MaxCols]();
        copy(other.data,other.data+MaxRows*MaxCols,data);
    }

    // Destructor
    ~TwoD(){
        delete[] data;
    }

    // Overloaded assignment operator
    TwoD& operator=(const TwoD& other){
        if(this!=&other){
            delete[] data;
            MaxRows=other.MaxRows;
            MaxCols=other.MaxCols;
            data=new double[MaxRows*MaxCols];
            copy(other.data,other.data+MaxRows*MaxCols,data);
        }
        return *this;
    }
    // Accessor function
    double get(int row,int col) const {
        return data[row*MaxCols+col];
    }
    // Mutator function
    void set(int row,int col,double value){
        data[row*MaxCols+col]=value;
    }
    // Overloaded + operator
    friend TwoD operator+(const TwoD& one,const TwoD& two){
        int mRow=(one.MaxRows>two.MaxRows)?one.MaxRows:two.MaxRows;
        int mCol=(one.MaxCols>two.MaxCols)?one.MaxCols:two.MaxCols;
        TwoD result(mRow,mCol);
        for (int i = 0; i < one.MaxRows; i++) {
            for (int j = 0; j < one.MaxCols; j++) {
                result.set(i, j, one.get(i,j));
            }
        }

        for (int i = 0; i < two.MaxRows; i++) {
            for (int j = 0; j < two.MaxCols; j++) {
                result.set(i, j, result.get(i,j) + two.get(i,j));
            }
        }
        return result;
    }
    friend ostream& operator<<(ostream& out,const TwoD& one){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                out<<one.get(i,j);
            }
            out<<endl;
        }
        return out;
    }
};
int main(){
    srand(time(0));
    TwoD one(2,2);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            one.set(i,j,rand()%5);
        }
    }
    cout<<one;
    TwoD two(one);
    cout<<two;
    cout<<one+two;    
}
