#include<iostream>
#include"TwoD.h"

using namespace std;

TwoD::TwoD(){
    row=3;
    column=3;
    arr = new int*[row]();
    for(int i=0;i<row;i++){
        arr[i]=new int[column]();
    }
}

TwoD::TwoD(int r,int c){
    row=r;
    column=c;
    arr = new int*[row]();
    for(int i=0;i<row;i++){
        arr[i]=new int[column]();
    }
}

TwoD::TwoD(const TwoD &other){
    row=other.getRow();
    column=other.getColumn();
    arr = new int*[row]();
    for(int i=0;i<row;i++){
        arr[i]=new int[column]();
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            arr[i][j]=other.getValue(i,j);
        }
    }
}

TwoD::~TwoD(){
    delete[] arr;
}

int TwoD::getColumn()const{
    return column;
}

int TwoD::getRow()const{
    return row;
}

void TwoD::setRow(int newRow){
    int** newArr = new int*[newRow];
    for(int i = 0; i < newRow; ++i)
        newArr[i] = new int[column];

    for(int i=0; i<newRow; i++){
        if(i<row){
            for(int j=0; j<column; j++){
                newArr[i][j]=arr[i][j];
            }
        }
        else{
            for(int j=0; j<column; j++){
                newArr[i][j]=0;
            }
        }
    }

    for(int i = 0; i < row; ++i)
        delete [] arr[i];
    delete [] arr;

    arr = newArr;
    row = newRow;
}
void TwoD::setColumn(int newColumn){
    int** newArr=new int*[row];
    for(int i=0;i<row;i++){
        newArr[i] = new int[newColumn];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<newColumn;j++){
            if(i<column){
                newArr[i][j]=arr[i][j];
            }
            else{
                newArr[i][j]=0;
            }
        }
    }
    for(int i=0;i<row;i++){
        delete[] arr[i];
    }
    delete[] arr;

    arr=newArr;
    column=newColumn;
}
int TwoD::getValue(int r,int c)const{
    if(r<row&&c<column){
        return arr[r][c];
    }
    else{
        cout<<"Index out of range";
        exit(1);
    }
}
void TwoD::setValue(int r,int c,int value){
    arr[r][c]=value;
}

TwoD& TwoD::operator=(const TwoD& other){
    if(this!=&other){
        for(int i=0;i<row;i++){
            delete[] arr[i];
        }
        delete[] arr;

        row=other.getRow();
        column=other.getColumn();
        arr = new int*[row]();
        for(int i=0;i<row;i++){
            arr[i]=new int[column]();
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                arr[i][j]=other.getValue(i,j);
            }
        }
    }
    return *this;
}

const TwoD TwoD::operator+(const TwoD& other)const{
    TwoD result(row>other.getRow()?row:other.getRow(),column>other.getColumn()?column:other.getColumn());
    for(int i=0;i<result.getRow();i++){
        for(int j=0;j<result.getColumn();j++){
            if(i<row&&j<column){
                result.setValue(i,j,getValue(i,j)+arr[i][j]);
            }
            if(i<other.getRow()&&j<other.getColumn()){
                result.setValue(i,j,getValue(i,j)+other.getValue(i,j));
            }
        }
    }
    return result;
}

const TwoD TwoD::operator*(const TwoD& other)const{
    if(column!=other.getRow()){
        cout<<"Numbers are off";
        exit(1);
    }
    TwoD result(row,other.getColumn());
    for(int i=0;i<row;i++){
        for(int j=0;j<other.getColumn();j++){
            for(int k=0;k<column;k++){
                result.setValue(i,j,result.getValue(i,j)+arr[i][k]*other.getValue(k,j));
            }
        }
    }
    return result;
}